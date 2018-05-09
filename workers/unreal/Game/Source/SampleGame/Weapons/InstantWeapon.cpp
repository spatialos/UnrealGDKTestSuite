// Fill out your copyright notice in the Description page of Project Settings.

#include "InstantWeapon.h"

#include "CollisionQueryParams.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SampleGameCharacter.h"
#include "UnrealNetwork.h"


AInstantWeapon::AInstantWeapon()
{
	// Set the default damage class to a generic one.
	DamageTypeClass = UDamageType::StaticClass();

	ShotVisualizationDelayTolerance = FTimespan::FromMilliseconds(3000.0f);
}

void AInstantWeapon::StartFire()
{
	float Now = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	if (CurrentState == EWeaponState::Idle && Now > LastBurstTime + BurstInterval)
	{
		CurrentState = EWeaponState::Firing;

		// Initialize the burst.
		LastBurstTime = Now;
		BurstShotsRemaining = BurstCount;

		// Fire a shot right away.
		DoFire();

		ClearTimerIfRunning();
		if (IsFullyAutomatic())
		{
			GetWorldTimerManager().SetTimer(NextShotTimer, NextShotTimerDelegate, BurstInterval, true);
		}
		else if (IsBurstFire())
		{
			GetWorldTimerManager().SetTimer(NextShotTimer, NextShotTimerDelegate, BurstShotInterval, true);
		}
		else
		{
			CurrentState = EWeaponState::Idle;
		}
	}
}

void AInstantWeapon::StopFire()
{
	// Can't force stop a burst.
	if (CurrentState == EWeaponState::Firing && !IsBurstFire())
	{
		StopFiring();
	}
}

void AInstantWeapon::BeginPlay()
{
	Super::BeginPlay();

	NextShotTimerDelegate.BindLambda([&]() {
		DoFire();
	});
}

void AInstantWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AInstantWeapon, HitNotify, COND_SkipOwner);
}

void AInstantWeapon::DoFire()
{
	if (HasAuthority())
	{
		return;
	}

	FInstantHitInfo hitInfo;
	if (DoLineTrace(hitInfo))
	{
		ServerDidHit(hitInfo);
		SpawnHitFX(hitInfo);  // Spawn the hit fx locally
	} else
	{
		ServerDidMiss(hitInfo);
	}

	if (IsBurstFire())
	{
		--BurstShotsRemaining;
		if (BurstShotsRemaining <= 0)
		{
			StopFiring();
		}
	}
}

bool AInstantWeapon::DoLineTrace(FInstantHitInfo& OutHitInfo)
{
	ASampleGameCharacter* character = GetCharacter();

	FCollisionQueryParams traceParams = FCollisionQueryParams(FName(TEXT("SampleGame_Trace")), true, this);
	traceParams.bTraceComplex = true;
	traceParams.bTraceAsyncScene = true;
	traceParams.bReturnPhysicalMaterial = false;
	traceParams.AddIgnoredActor(this);
	traceParams.AddIgnoredActor(character);

	const FName kTraceTag("SampleGameTrace");
	static bool didDo = false;
	if (!didDo)
	{
		GetWorld()->DebugDrawTraceTag = kTraceTag;
	}

	if (bDrawDebugLineTrace)
	{
		traceParams.TraceTag = kTraceTag;
	}

	FHitResult hitResult(ForceInit);
	FVector traceStart = character->GetLineTraceStart();
	FVector traceEnd = traceStart + character->GetLineTraceDirection() * MaxRange;

	bool didHit = GetWorld()->LineTraceSingleByChannel(
		hitResult,
		traceStart,
		traceEnd,
		ECC_WorldStatic,
		traceParams);

	if (!didHit)
	{
		return false;
 	}

	UE_LOG(LogClass, Log, TEXT("Line trace hit actor: %s"), *hitResult.Actor->GetName());
	
	OutHitInfo.Location = hitResult.ImpactPoint;
	if (hitResult.GetActor()->GetIsReplicated())
	{
		OutHitInfo.HitActor = hitResult.GetActor();
	} else
	{
		OutHitInfo.HitActor = nullptr;
	}
	return true;
}

void AInstantWeapon::NotifyClientsOfHit(const FInstantHitInfo& HitInfo)
{
	// Updating this replicated property should trigger OnRep_HitNotify on all clients except the owning one.
	HitNotify.HitActor = HitInfo.HitActor;
	HitNotify.Location = HitInfo.Location;
	HitNotify.Timestamp = FDateTime::UtcNow();
}

void AInstantWeapon::SpawnHitFX(const FInstantHitInfo& HitInfo)
{
	if (GetWorld()->GetNetMode() == NM_DedicatedServer || HitFXTemplate == nullptr)
	{
		return;
	}

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFXTemplate, HitInfo.Location, FRotator::ZeroRotator, true);
}

bool AInstantWeapon::ValidateHit(const FInstantHitInfo& HitInfo)
{
	if (HitInfo.HitActor == nullptr)
	{
		// Shouldn't be validating shots that didn't hit an actor, this doesn't make sense.
		return false;
	}

	// Get the bounding box of the actor we hit.
	const FBox HitBox = HitInfo.HitActor->GetComponentsBoundingBox();

	// Calculate the extent of the box along all 3 axes an add a tolerance factor.
	FVector BoxExtent = 0.5 * (HitBox.Max - HitBox.Min) + (HitValidationTolerance * FVector::OneVector);
	FVector BoxCenter = (HitBox.Max + HitBox.Min) * 0.5;

	// Avoid precision errors for really thin objects.
	BoxExtent.X = FMath::Max(20.0f, BoxExtent.X);
	BoxExtent.Y = FMath::Max(20.0f, BoxExtent.Y);
	BoxExtent.Z = FMath::Max(20.0f, BoxExtent.Z);

	// Check whether the hit is within the box + tolerance.
	if (FMath::Abs(HitInfo.Location.X - BoxCenter.X) > BoxExtent.X ||
		FMath::Abs(HitInfo.Location.Y - BoxCenter.Y) > BoxExtent.Y ||
		FMath::Abs(HitInfo.Location.Z - BoxCenter.Z) > BoxExtent.Z)
	{
		return false;
	}

	return true;
}

bool AInstantWeapon::ServerDidHit_Validate(const FInstantHitInfo& HitInfo)
{
	return true;
}

void AInstantWeapon::ServerDidHit_Implementation(const FInstantHitInfo& HitInfo)
{
	bool bDoNotifyHit = false;

	if (HitInfo.HitActor == nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("%s server: hit environment %s"), *this->GetName(), *HitInfo.Location.ToString());
		bDoNotifyHit = true;
	}
	else
	{
		if (ValidateHit(HitInfo)) {
			UE_LOG(LogClass, Log, TEXT("%s server: hit actor %s"), *this->GetName(), *HitInfo.HitActor->GetName());

			FDamageEvent DmgEvent;
			DmgEvent.DamageTypeClass = DamageTypeClass;

			HitInfo.HitActor->TakeDamage(ShotBaseDamage, DmgEvent, GetCharacter()->GetController(), this);
			bDoNotifyHit = true;
		}
		else
		{
			UE_LOG(LogClass, Log, TEXT("%s server: rejected hit of actor %s"), *this->GetName(), *HitInfo.HitActor->GetName());
		}
	}

	if (bDoNotifyHit)
	{
		NotifyClientsOfHit(HitInfo);
	}
}

bool AInstantWeapon::ServerDidMiss_Validate(const FInstantHitInfo& HitInfo)
{
	return true;
}

void AInstantWeapon::ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo)
{
	UE_LOG(LogClass, Log, TEXT("Shot missed"));
}

void AInstantWeapon::OnRep_HitNotify()
{
	if (FDateTime::UtcNow() < HitNotify.Timestamp + ShotVisualizationDelayTolerance)
	{
		SpawnHitFX(HitNotify);
	}
}

void AInstantWeapon::ClearTimerIfRunning()
{
	if (NextShotTimer.IsValid())
	{
		GetWorldTimerManager().ClearTimer(NextShotTimer);
	}
}

void AInstantWeapon::StopFiring()
{
	CurrentState = EWeaponState::Idle;
	ClearTimerIfRunning();
}

bool AInstantWeapon::IsBurstFire()
{
	return BurstCount > 1;
}

bool AInstantWeapon::IsFullyAutomatic()
{
	return BurstCount < 1;
}

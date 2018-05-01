// Fill out your copyright notice in the Description page of Project Settings.

#include "InstantWeapon.h"

#include "CollisionQueryParams.h"
#include "Engine/World.h"
#include "SampleGameCharacter.h"
#include "UnrealNetwork.h"


void AInstantWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInstantWeapon, HitNotify);
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
	} else
	{
		ServerDidMiss(hitInfo);
	}
}

bool AInstantWeapon::DoLineTrace(FInstantHitInfo& OutHitInfo)
{
	FCollisionQueryParams traceParams = FCollisionQueryParams(FName(TEXT("SampleGame_Trace")), true, this);
	traceParams.bTraceComplex = true;
	traceParams.bTraceAsyncScene = true;
	traceParams.bReturnPhysicalMaterial = false;

	ASampleGameCharacter* character = GetCharacter();
	FHitResult hitResult(ForceInit);
	FVector traceStart = character->GetFollowCamera()->GetComponentLocation();
	FVector traceEnd = traceStart + character->GetFollowCamera()->GetForwardVector() * MaxRange;

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

bool AInstantWeapon::ServerDidHit_Validate(const FInstantHitInfo& HitInfo)
{
	return true;
}

void AInstantWeapon::ServerDidHit_Implementation(const FInstantHitInfo& HitInfo)
{
	if (HitInfo.HitActor == nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("AInstantWeapon server: hit %s"), *HitInfo.Location.ToString())
	} else
	{
		UE_LOG(LogClass, Log, TEXT("AInstantWeapon server: hit actor %s"), *HitInfo.HitActor->GetName())
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

}

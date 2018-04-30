// Fill out your copyright notice in the Description page of Project Settings.

#include "InstantWeapon.h"

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
		// No reason for this to be running on the server.
		return;
	}

	// Do line trace
	// Send to server
	FInstantHitInfo hitInfo;
	ServerDidHit(hitInfo);
}

bool AInstantWeapon::ServerDidHit_Validate(const FInstantHitInfo& HitInfo)
{
	return true;
}

void AInstantWeapon::ServerDidHit_Implementation(const FInstantHitInfo& HitInfo)
{
	UE_LOG(LogClass, Log, TEXT("AInstantWeapon server: shot weapon"))
}

bool AInstantWeapon::ServerDidMiss_Validate(const FInstantHitInfo& HitInfo)
{
	return true;
}

void AInstantWeapon::ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo)
{

}

void AInstantWeapon::OnRep_HitNotify()
{

}

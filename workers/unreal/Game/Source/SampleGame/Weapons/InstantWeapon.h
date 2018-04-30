// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "InstantWeapon.generated.h"


USTRUCT()
struct FInstantHitInfo
{
	GENERATED_USTRUCT_BODY()

};


/**
 * 
 */
UCLASS()
class SAMPLEGAME_API AInstantWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	// RPC for telling the server that we fired and hit something.
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDidHit(const FInstantHitInfo& HitInfo);
	bool ServerDidHit_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidHit_Implementation(const FInstantHitInfo& HitInfo);

	// RPC for telling the server that we fired and did not hit something.
	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerDidMiss(const FInstantHitInfo& HitInfo);
	bool ServerDidMiss_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Runs a line trace and triggers the server RPC for hits.
	virtual void DoFire() override;

	// Responds to a change in the HitNotify property, used as a broadcast event for displaying hit effects.
	UFUNCTION()
	virtual void OnRep_HitNotify();

	UPROPERTY(ReplicatedUsing = OnRep_HitNotify)
	FInstantHitInfo HitNotify;
	
};

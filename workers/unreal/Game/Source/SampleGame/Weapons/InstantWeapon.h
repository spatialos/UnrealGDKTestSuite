// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "InstantWeapon.generated.h"


USTRUCT()
struct FInstantHitInfo
{
	GENERATED_USTRUCT_BODY()

	// Location of the hit in world space.
	UPROPERTY()
	FVector Location;

	// Actor that was hit, or nullptr if nothing was hit.
	UPROPERTY()
	AActor* HitActor;

	// Currently this is only used to ensure that the struct gets replicated even if the above properties don't change.
	// In the future it could also be used to reproduce pseudorandom values on client and server (as Epic's ShooterGame does).
	UPROPERTY()
	int32 RandomSeed;

	FInstantHitInfo() :
		Location(FVector{ 0,0,0 }),
		HitActor(nullptr),
		RandomSeed(0)
	{}
};


/**
 * 
 */
UCLASS()
class SAMPLEGAME_API AInstantWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	AInstantWeapon();

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
	FInstantHitInfo LastHitInfo;
	virtual void Tick(float DeltaSeconds) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Runs a line trace and triggers the server RPC for hits.
	virtual void DoFire() override;

	// [client] Performs a line trace and populates OutHitInfo based on the results.
	// Returns true if it hits anything, false otherwise.
	bool DoLineTrace(FInstantHitInfo& OutHitInfo);

	// [server] Notifies clients of a hit.
	void NotifyClientsOfHit(const FInstantHitInfo& HitInfo);

	// [client] Spawns the hit FX in the world.
	void SpawnHitFX(const FInstantHitInfo& HitInfo);

	// Responds to a change in the HitNotify property, used as a broadcast event for displaying hit effects.
	UFUNCTION()
	virtual void OnRep_HitNotify();

	// Replicated property used to notify clients of a shot, for visualization.
	UPROPERTY(ReplicatedUsing = OnRep_HitNotify)
	FInstantHitInfo HitNotify;

	// Maximum range of the weapon's hitscan.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float MaxRange = 50000.0f;

	UPROPERTY(EditAnywhere, Category = "Weapons")
	class UParticleSystem* HitFXTemplate = nullptr;

	UPROPERTY(EditAnywhere, Category = "Weapons")
	bool bDrawDebugLineTrace = false;
};

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "InstantWeapon.generated.h"


// Tag for weapon line trace visualization.
const FName kTraceTag("SampleGameTrace");

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

	// Used to ensure that the struct gets replicated even if the above properties don't change.
	// Also used to make sure that only recent shots get visualized.
	UPROPERTY()
	FDateTime Timestamp;

	FInstantHitInfo() :
		Location(FVector{ 0,0,0 }),
		HitActor(nullptr),
		Timestamp(0)
	{}
};


/**
 * AInstantWeapon implements hitscan shooting for a single-shot, burst-fire, or full-auto weapon.
 * Hit detection is entirely client-side, with loose server validation.
 * Shot timing and rate-limiting is entirely client-side, with no server validation.
 */
UCLASS()
class SAMPLEGAME_API AInstantWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	AInstantWeapon();

	virtual void StartFire() override;

	virtual void StopFire() override;

	// RPC for telling the server that we fired and hit something.
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDidHit(const FInstantHitInfo& HitInfo);
	bool ServerDidHit_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidHit_Implementation(const FInstantHitInfo& HitInfo);

	// RPC for telling the server that we fired and did not hit anything.
	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerDidMiss(const FInstantHitInfo& HitInfo);
	bool ServerDidMiss_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// [client] Runs a line trace and triggers the server RPC for hits.
	virtual void DoFire();

private:
	// [client] Performs a line trace and populates OutHitInfo based on the results.
	// Returns true if it hits anything, false otherwise.
	bool DoLineTrace(FInstantHitInfo& OutHitInfo);

	// [server] Notifies clients of a hit.
	void NotifyClientsOfHit(const FInstantHitInfo& HitInfo);

	// [client] Spawns the hit FX in the world.
	void SpawnHitFX(const FInstantHitInfo& HitInfo);

	// [server] Validates the hit. Returns true if it's valid, false otherwise.
	bool ValidateHit(const FInstantHitInfo& HitInfo);

	// [client] Responds to a change in the HitNotify property, used as a broadcast event for displaying hit effects.
	UFUNCTION()
	virtual void OnRep_HitNotify();

	// [client] Clears the NextShotTimer if it's running.
	void ClearTimerIfRunning();

	// [client] Actually stops the weapon firing.
	void StopFiring();

	// Returns true if the weapon is a burst-fire weapon.
	bool IsBurstFire();

	// Returns true if the weapon is fully-automatic.
	bool IsFullyAutomatic();

	// Replicated property used to notify clients of a shot, for visualization.
	UPROPERTY(ReplicatedUsing = OnRep_HitNotify)
	FInstantHitInfo HitNotify;

	// Minimum time between bursts (or shots, if in single-shot or automatic mode), in seconds.
	// 0 = as fast as you can pull the trigger
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float BurstInterval;

	// Number of shots in a single burst.
	// 0  = full-auto
	// 1  = single-shot
	// >1 = burst fire
	UPROPERTY(EditAnywhere, Category = "Weapons")
	int32 BurstCount;

	// Interval between individual shots within a burst, in seconds.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float BurstShotInterval;

	// Time (in seconds since start of level) since the last burst fire. Used for limiting fire rate.
	float LastBurstTime;

	// Number of shots remaining in the current burst.
	int32 BurstShotsRemaining;

	// Maximum range of the weapon's hitscan.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float MaxRange;

	// Base damage done to others by a single shot.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float ShotBaseDamage;

	// Tolerance, in world units, to add to the bounding box of an actor when validating hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float HitValidationTolerance;

	// Type of damage to send to hit actors.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<UDamageType> DamageTypeClass;

	// Template for the particle system to spawn in the world on hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	class UParticleSystem* HitFXTemplate;

	// Tolerance, in seconds, after which we will no longer visualize a shot notification.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	FTimespan ShotVisualizationDelayTolerance;

	// If true, draws debug line traces for hitscan shots.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	bool bDrawDebugLineTrace;

	// Timer that handles firing the next shot.
	FTimerHandle NextShotTimer;

	// Delegate for running the next shot method.
	FTimerDelegate NextShotTimerDelegate;
};

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
 * 
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

	// RPC for telling the server that we fired and did not hit something.
	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerDidMiss(const FInstantHitInfo& HitInfo);
	bool ServerDidMiss_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Runs a line trace and triggers the server RPC for hits.
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

	// Responds to a change in the HitNotify property, used as a broadcast event for displaying hit effects.
	UFUNCTION()
	virtual void OnRep_HitNotify();

	void ClearTimerIfRunning();

	// Actually stops the weapon firing.
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
	float BurstInterval = 0.5f;

	// Number of shots in a single burst.
	// 0  = full-auto
	// 1  = single-shot
	// >1 = burst fire
	UPROPERTY(EditAnywhere, Category = "Weapons")
	int32 BurstCount = 1;

	// Interval between individual shots within a burst, in seconds.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float BurstShotInterval = 0.2f;

	// Time (in seconds since start of level) since the last burst fire. Used for limiting fire rate.
	float LastBurstTime = 0.0f;

	// Number of shots remaining in the current burst.
	int32 BurstShotsRemaining = 0;

	// Maximum range of the weapon's hitscan.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float MaxRange = 50000.0f;

	// Base damage done to others by a single shot.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float ShotBaseDamage = 10.0f;

	// Tolerance, in world units, to add to the bounding box of an actor when validating hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float HitValidationTolerance = 50.0f;

	// Type of damage to send to hit actors.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<UDamageType> DamageTypeClass;

	// Template for the particle system to spawn in the world on hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	class UParticleSystem* HitFXTemplate = nullptr;

	// Tolerance, in seconds, after which we will no longer visualize a shot notification.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	FTimespan ShotVisualizationDelayTolerance;

	// If true, draws debug line traces for hitscan shots.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	bool bDrawDebugLineTrace = false;

	// Timer that handles firing the next shot.
	FTimerHandle NextShotTimer;

	// Delegate for running the next shot method.
	FTimerDelegate NextShotTimerDelegate;
};

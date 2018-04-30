// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/InstantWeapon.h"
#include "AutomaticInstantWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API AAutomaticInstantWeapon : public AInstantWeapon
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void StartFire() override;

	virtual void StopFire() override;

protected:
	// Interval between shots, in seconds.
	UPROPERTY(EditAnywhere, Category = "Weapon")
	float ShotInterval = 0.1f;

private:
	void ClearTimerIfRunning();

	// Timer that handles firing the next shot.
	FTimerHandle NextShotTimer;

	// Delegate for running the next shot method.
	FTimerDelegate NextShotTimerDelegate;
	
};

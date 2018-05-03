// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticInstantWeapon.h"

#include "TimerManager.h"


void AAutomaticInstantWeapon::BeginPlay()
{
	Super::BeginPlay();

	NextShotTimerDelegate.BindLambda([&]() {
		DoFire();
	});
}

void AAutomaticInstantWeapon::StartFire()
{
	if (CurrentState == EWeaponState::Idle)
	{
		CurrentState = EWeaponState::Firing;

		// Fire a shot right away.
		DoFire();

		// Set a timer to execute the next shot.
		ClearTimerIfRunning();
		GetWorldTimerManager().SetTimer(NextShotTimer, NextShotTimerDelegate, ShotInterval, true);
	}
}

void AAutomaticInstantWeapon::StopFire()
{
	if (CurrentState == EWeaponState::Firing)
	{
		CurrentState = EWeaponState::Idle;
		ClearTimerIfRunning();
	}
}

void AAutomaticInstantWeapon::ClearTimerIfRunning()
{
	if (NextShotTimer.IsValid())
	{
		GetWorldTimerManager().ClearTimer(NextShotTimer);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


// TODO: change to a class enum
enum EWeaponState
{
	Idle,
	Firing
};

UCLASS(Abstract)
class SAMPLEGAME_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	// [client] Starts firing the weapon.
	// Not implemented in AWeapon.
	virtual void StartFire() PURE_VIRTUAL(AWeapon::StartFire,);

	// [client] Stops firing the weapon.
	// Not implemented in AWeapon.
	virtual void StopFire() PURE_VIRTUAL(AWeapon::StopFire,);

protected:
	// Get the character actor for this weapon, or nullptr if there isn't one.
	class ASampleGameCharacter* GetCharacter();
	
	// The current state of the weapon.
	EWeaponState CurrentState = EWeaponState::Idle;

	// Set up a root component so this actor can have a position in the world.
	class USceneComponent* LocationComponent = nullptr;
	
};

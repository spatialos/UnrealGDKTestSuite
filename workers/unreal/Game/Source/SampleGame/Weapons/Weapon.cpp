// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

#include "Engine/World.h"
#include "SampleGameCharacter.h"
#include "UnrealNetwork.h"


AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);
}

class ASampleGameCharacter* AWeapon::GetOwningCharacter()
{
	return OwningCharacter;
}

void AWeapon::SetOwningCharacter(ASampleGameCharacter* NewCharacter)
{
	OwningCharacter = NewCharacter;
}

void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, OwningCharacter);
}

EWeaponState AWeapon::GetWeaponState()
{
	return CurrentState;
}

void AWeapon::SetWeaponState(EWeaponState NewState)
{
	CurrentState = NewState;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	// Note that this appears not to work for child actors.
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);
}


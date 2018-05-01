// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

#include "Engine/World.h"
#include "SampleGameCharacter.h"


AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	// Note that this appears not to work for child actors.
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);
}

class ASampleGameCharacter* AWeapon::GetCharacter()
{
	// TODO: retain a reference to the owning character

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (controller == nullptr)
	{
		return nullptr;
	}
	return Cast<ASampleGameCharacter>(controller->GetPawn());
}


// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "MyActor.h"
#include "Engine.h"

ASampleGameGameMode::ASampleGameGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
        TEXT("/Game/EntityBlueprints/SampleGameCharacter_BP"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void ASampleGameGameMode::BeginPlay() 
{
    Super::BeginPlay();

    FVector Location(0.0f, 0.0f, 0.0f);
    FRotator Rotation(0.0f, 0.0f, 0.0f);
    FActorSpawnParameters SpawnInfo;
    //GetWorld()->SpawnActor<AMyActor>(Location, Rotation, SpawnInfo);
}

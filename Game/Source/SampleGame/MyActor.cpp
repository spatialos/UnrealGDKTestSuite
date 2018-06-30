// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Engine.h"
#include "SpatialNetDriver.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if
    // you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    USpatialNetDriver* netDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());

    //UE_LOG(LogTemp, Warning, TEXT("Tick: %s"), *netDriver->GetSpatialOS()->GetWorkerId());
 //   FString workerId = netDriver->GetSpatialOS()->GetWorkerId();
	//if(workerId.Contains(TEXT("UnrealClient")))
 //   {
	//	Foo(2);
 //   }
}

bool AMyActor::Foo_Validate(int x)
{
    return true;
}

void AMyActor::Foo_Implementation(int x)
{
    USpatialNetDriver* netDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
    UE_LOG(LogTemp, Warning, TEXT("Wowee %s"), *netDriver->GetSpatialOS()->GetWorkerId());
    //UE_LOG(LogTemp, Warning, TEXT("WOW I DID IT"));
}

bool AMyActor::Bar_Validate(double y)
{
    return true;
}

void AMyActor::Bar_Implementation(double y) {}

// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCube.h"
#include "UnrealNetwork.h"

// Sets default values
AMyCube::AMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	transparency = 0.001f;
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Cube Mesh"));
    CubeMesh->SetSimulatePhysics(true);
    RootComponent = CubeMesh;
}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (transparency > 0.9f)
        transparency = 0.00001f;

	transparency = 10*(pow(1.11, transparency)-1);
}

void AMyCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AMyCube, transparency);
}


UStaticMeshComponent* AMyCube::GetMesh() {
    return CubeMesh;
}

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ActorProxyTestActor.h"

#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AActorProxyTestActor::AActorProxyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	NetCullDistanceSquared = 100000.0f;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	RootComponent = Root;
		
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (CubeAsset.Succeeded())
	{
		Mesh->SetStaticMesh(CubeAsset.Object);
	}

}

// Called when the game starts or when spawned
void AActorProxyTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorProxyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


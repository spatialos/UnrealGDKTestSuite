// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCube.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ATestCube::ATestCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    bReplicates = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATestCube::BeginPlay()
{
	Super::BeginPlay();
	OnRep_Color1();
}

void ATestCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ATestCube, bColor1);
}

// Called every frame
void ATestCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestCube::Interact(ACharacter* Interactor)
{
    if (HasAuthority())
    {
        ToggleColor();
    } else
    {
        ServerInteract();
    }
}

bool ATestCube::ServerInteract_Validate()
{
    return true;
}

void ATestCube::ServerInteract_Implementation()
{
    ToggleColor();
}

void ATestCube::ToggleColor()
{
    bColor1 = !bColor1;
}

void ATestCube::OnRep_Color1()
{
	// TODO: check if I'm a client
	if (MaterialInstanceDynamic == nullptr)
	{
		MaterialInstanceDynamic = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	}
	MaterialInstanceDynamic->SetVectorParameterValue(FName("BaseColor"), bColor1 ? Color1 : Color2);
}


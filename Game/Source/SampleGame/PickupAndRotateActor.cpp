// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupAndRotateActor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealNetwork.h"

// Sets default values
APickupAndRotateActor::APickupAndRotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    bHolding = false;

	bReplicates = true;
}

void APickupAndRotateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APickupAndRotateActor, HoldingComp);
    DOREPLIFETIME(APickupAndRotateActor, bHolding);
    DOREPLIFETIME(APickupAndRotateActor, MyCharacter);
    DOREPLIFETIME(APickupAndRotateActor, PlayerCamera);
}

// Called when the game starts or when spawned
void APickupAndRotateActor::BeginPlay()
{
	Super::BeginPlay();

	if (!GetMesh())
    {
		// this loop will be entered only when GetMesh() is not overwritten by inherited class
        MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
        MyMesh->SetSimulatePhysics(true);
        RootComponent = MyMesh;
	}
	
	//if (Role < ROLE_Authority)
 //   {
	//	// stop physics simulation on client side
	//	GetMesh()->PutRigidBodyToSleep();
 //       GetMesh()->SetSimulatePhysics(false);
 //       GetMesh()->SetEnableGravity(false);
 //       GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}
}

// Called every frame
void APickupAndRotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bHolding && HoldingComp)
    {
        SetActorLocationAndRotation(HoldingComp->GetComponentLocation(),
                                    HoldingComp->GetComponentRotation());
    }
}

UStaticMeshComponent* APickupAndRotateActor::GetMesh()
{
    return MyMesh;
}


bool APickupAndRotateActor::LinkToPlayer_Validate(ACharacter* myChar)
{
    return true;
}

// link with interacting player: get their camera and holding component
void APickupAndRotateActor::LinkToPlayer_Implementation(ACharacter* myChar)
{
    MyCharacter = myChar;
    PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();

    TArray<USceneComponent*> Components;

    MyCharacter->GetComponents(Components);

    if (Components.Num() > 0)
    {
        for (auto& Comp : Components)
        {
            if (Comp->GetName() == "HoldingComponent")
            {
                HoldingComp = Cast<USceneComponent>(Comp);
            }
        }
    }
}



void APickupAndRotateActor::RotateActor()
{
    if (MyCharacter == nullptr)
        return;

    FRotator ControlRotation = MyCharacter->GetControlRotation();
    SetActorRotation(FQuat(ControlRotation));
}

bool APickupAndRotateActor::Pickup_Validate() {
    return true;
}

void APickupAndRotateActor::Pickup_Implementation()
{
    if (!MyCharacter)
        return;

    bHolding = !bHolding;
    GetMesh()->SetEnableGravity(bHolding ? false : true);
    GetMesh()->SetSimulatePhysics(bHolding ? false : true);
    GetMesh()->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision
                                         : ECollisionEnabled::QueryAndPhysics);

    if (!bHolding)
    {
        FVector ForwardVector = PlayerCamera->GetForwardVector();
        GetMesh()->AddForce(ForwardVector * 50000 * GetMesh()->GetMass());
    }
}

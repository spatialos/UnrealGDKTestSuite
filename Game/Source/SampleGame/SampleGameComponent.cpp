// Fill out your copyright notice in the Description page of Project Settings.

#include "SampleGameComponent.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

// Sets default values for this component's properties
USampleGameComponent::USampleGameComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
	bReplicates = true;
}


// Called when the game starts
void USampleGameComponent::BeginPlay()
{
	Super::BeginPlay();
	foo = 8;
	SetIsReplicated(true);
	//if(GetOwner()->HasAuthority())
	//	GetWorld()->GetTimerManager().SetTimer(MemberTimerHandle, this, &USampleGameComponent::Test, 6.0f, true, 6.0);
}

void USampleGameComponent::Test()
{
	if(!bReplicates)
	{
		DestroyComponent();
	}
	SetIsReplicated(false);
}

// Called every frame
void USampleGameComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(GetOwner()->HasAuthority())
	{
		//foo = FMath::RandRange(1, 10);
		//UE_LOG(LogTemp, Warning, TEXT("%d"), foo);
	}
}

void USampleGameComponent::NotifyFooReplicated()
{
	//UE_LOG(LogTemp, Warning, TEXT("foo: %d"), foo);
}

void USampleGameComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USampleGameComponent, foo);
}

void USampleGameComponent::TestRPC_Implementation()
{

}

bool USampleGameComponent::TestRPC_Validate()
{
	return true;
}
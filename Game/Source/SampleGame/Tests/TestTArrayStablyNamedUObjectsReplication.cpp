// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTArrayStablyNamedUObjectsReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"
#include "SpatialNetDriver.h"
#include "Legacy/EntityRegistry.h"

ATestActor::ATestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void ATestActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestActor, EntityPath, COND_None);
}

void ATestTArrayStablyNamedUObjectsReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
	{
		bDynamicallyCreatedActorReplicated = false;
		bReplicationRecievedOnClient = false;

		ValidateReplication_Client(StablyNamedArray, DynamicallyCreatedArray);

		Server_ReportReplication(StablyNamedArray, DynamicallyCreatedArray);
	}
}

void ATestTArrayStablyNamedUObjectsReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestTArrayStablyNamedUObjectsReplication, StablyNamedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayStablyNamedUObjectsReplication, DynamicallyCreatedArray, COND_None);
}

bool ATestTArrayStablyNamedUObjectsReplication::Server_ReportReplication_Validate(const TArray<UTestUObject*>& RepStablyNamedArray, const TArray<ATestActor*>& RepDynamicallyCreatedActors)
{
	return true;
}

void ATestTArrayStablyNamedUObjectsReplication::Server_ReportReplication_Implementation(const TArray<UTestUObject*>& RepStablyNamedArray, const TArray<ATestActor*>& RepDynamicallyCreatedActors)
{
	ValidateRPC_Server(RepStablyNamedArray, RepDynamicallyCreatedActors);

	SignalResponseRecieved();
}

void ATestTArrayStablyNamedUObjectsReplication::StartTestImpl()
{
	// Setup stably named UObjects
	UTestUObject* Testing = LoadObject<UTestUObject>(nullptr, TEXT("/Script/SampleGame.Default__TestUObject"));

	StablyNamedArray.Add(Testing);
	StablyNamedArray.Add(Testing);

	// Setup dynamically generated actors
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	FString test = NewActor->GetPathName();
	UE_LOG(LogTemp, Error, TEXT("%s"), *test);

	DynamicallyCreatedArray.Add(NewActor);

	SignalReplicationSetup();
}

void ATestTArrayStablyNamedUObjectsReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestTArrayStablyNamedUObjectsReplication::SendTestResponseRPCImpl()
{
	// Empty due to the deferred execution
}

void ATestTArrayStablyNamedUObjectsReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestTArrayStablyNamedUObjectsReplication::ValidateReplication_Client(const TArray<UTestUObject*>& TestStablyNamedArray, const TArray<ATestActor*>& TestDynamicallyCreatedActors)
{
	// Validate the stably named object
	int num = TestStablyNamedArray.Num();
	check(num == 2);

	check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	check(DynamicallyCreatedArray.Num() == 1);
	//Get the net driver
	//USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	//check(NetDriver);
	//worker::EntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(DynamicallyCreatedArray[0]).ToSpatialEntityId();
	//check(EntityId == DynamicallyCreatedArray[0]->EntityId);

}

void ATestTArrayStablyNamedUObjectsReplication::ValidateRPC_Server(const TArray<UTestUObject*>& TestStablyNamedArray, const TArray<ATestActor*>& TestDynamicallyCreatedActors)
{
	// Validate the stably named object
	int num = TestStablyNamedArray.Num();
	check(num == 2);

	check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	check(DynamicallyCreatedArray.Num() == 1);

	//Get the net driver
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	check(NetDriver);
	worker::EntityId RPCEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(TestDynamicallyCreatedActors[0]).ToSpatialEntityId();
	worker::EntityId ServerEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(DynamicallyCreatedArray[0]).ToSpatialEntityId();
	check(RPCEntityId == ServerEntityId);
}



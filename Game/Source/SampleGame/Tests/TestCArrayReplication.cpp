// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCArrayReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestCArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, PODArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, StablyNamedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, DynamicallyCreatedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, ArrayOfStructs, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, ArrayOfStructNetSerialize, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, EnumCArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, UEnumCArray, COND_None);
}

void ATestCArrayReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
	{
		bDynamicallyCreatedActorReplicated = false;
		bReplicationRecievedOnClient = false;

		ValidateReplication_Client();

		Server_ReportReplication();
	}
}


bool ATestCArrayReplication::Server_ReportReplication_Validate()
{
	return true;
}

void ATestCArrayReplication::Server_ReportReplication_Implementation()
{
	SignalResponseRecieved();
}

void ATestCArrayReplication::StartTestImpl()
{
	// Setup PODs
	PODArray[0] = FirstComparisonValue;
	PODArray[1] = SecondComparisonValue;

	// Setup stably named UObjects
	UTestUObject* StablyNamedObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/SampleGame.Default__TestUObject"));

	StablyNamedArray[0] = StablyNamedObject;
	StablyNamedArray[1] = StablyNamedObject;

	// Setup dynamically generated actors
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	NewActor->ActorName = NewActor->GetName();
	DynamicallyCreatedArray[0] = NewActor;
	DynamicallyCreatedArray[1] = NewActor;

	// Setup array of structs
	FTArrayTestStruct Entry;
	Entry.RootProp = 42;
	ArrayOfStructs[0] = Entry;
	Entry.RootProp = 37;
	ArrayOfStructs[1] = Entry;
 
	// Setup of array of structs with net serialize
	FTestStructWithNetSerialize NetSerializeEntry;
	NetSerializeEntry.MyInt = 42;
	NetSerializeEntry.MyFloat = 25.0f;
	ArrayOfStructNetSerialize[0] = NetSerializeEntry;
	NetSerializeEntry.MyInt = 43;
	NetSerializeEntry.MyFloat = 50.0f;
	ArrayOfStructNetSerialize[1] = NetSerializeEntry;

	// Setup of array of C++ 11 style enums
	EnumCArray[0] = ETest8Enum::Enum_1;
	EnumCArray[1] = ETest8Enum::Enum_0;

	// Setup of array of Unreal style enums
	UEnumCArray[0] = EnumNamespace::Enum_1;
	UEnumCArray[1] = EnumNamespace::Enum_0;

	SignalReplicationSetup();
}

void ATestCArrayReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestCArrayReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}

void ATestCArrayReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestCArrayReplication::ValidateReplication_Client()
{
	// Validate PODs
	check(PODArray[0] == FirstComparisonValue);
	check(PODArray[1] == SecondComparisonValue);

	// Validate the stably named object
	check(StablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(StablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(StablyNamedArray[0]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	check(StablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(StablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(StablyNamedArray[1]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	// Assert on name rather than path name as the path name is different for each PIE instance.
	check(DynamicallyCreatedArray[0]->ActorName == DynamicallyCreatedArray[0]->GetName());
	check(DynamicallyCreatedArray[1]->ActorName == DynamicallyCreatedArray[1]->GetName());

	// Validate TArray with structs
	check(ArrayOfStructs[0].RootProp == 42);
	check(ArrayOfStructs[1].RootProp == 37);

	// Validate TArray with structs and net serialize
	check(ArrayOfStructNetSerialize[0].MyInt == 42);
	check(ArrayOfStructNetSerialize[0].MyFloat == 25.0f);
	check(ArrayOfStructNetSerialize[1].MyInt == 43);
	check(ArrayOfStructNetSerialize[1].MyFloat == 50.0f);

	// Validate TArray of C++ 11 style enums
	check(EnumCArray[0] == ETest8Enum::Enum_1);
	check(EnumCArray[1] == ETest8Enum::Enum_0);

	// Setup of array of Unreal style enums
	check(UEnumCArray[0] == EnumNamespace::Enum_1);
	check(UEnumCArray[1] == EnumNamespace::Enum_0);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TestTArrayReplication.h"

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
	DOREPLIFETIME_CONDITION(ATestActor, ActorName, COND_None);
}

void ATestTArrayReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
	{
		bDynamicallyCreatedActorReplicated = false;
		bReplicationRecievedOnClient = false;

		ValidateReplication_Client(StablyNamedArray, DynamicallyCreatedArray, ArrayOfStructs, ArrayOfStructNetSerialize, EnumTArray, UEnumTArray);

		Server_ReportReplication(StablyNamedArray, DynamicallyCreatedArray, ArrayOfStructs, ArrayOfStructNetSerialize, EnumTArray, UEnumTArray);
	}
}

void ATestTArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, StablyNamedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, DynamicallyCreatedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, ArrayOfStructs, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, ArrayOfStructNetSerialize, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, EnumTArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, UEnumTArray, COND_None);
}

bool ATestTArrayReplication::Server_ReportReplication_Validate(const TArray<UTestUObject*>& RepStablyNamedArray, 
															   const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
															   const TArray<FTArrayTestStruct>& RepArrayOfStructs,
															   const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
															   const TArray<ETest8Enum>& RepEnumTArray,
															   const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray)
{
	return true;
}

void ATestTArrayReplication::Server_ReportReplication_Implementation(const TArray<UTestUObject*>& RepStablyNamedArray, 
																	 const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
																	 const TArray<FTArrayTestStruct>& RepArrayOfStructs,
																	 const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
																	 const TArray<ETest8Enum>& RepEnumTArray,
																	 const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray)
{
	ValidateRPC_Server(RepStablyNamedArray, RepDynamicallyCreatedActors, RepArrayOfStructs, RepArrayOfStructNetSerialize, RepEnumTArray, RepUEnumTArray);

	SignalResponseRecieved();
}

void ATestTArrayReplication::StartTestImpl()
{
	// Setup stably named UObjects
	UTestUObject* Testing = LoadObject<UTestUObject>(nullptr, TEXT("/Script/SampleGame.Default__TestUObject"));

	StablyNamedArray.Add(Testing);
	StablyNamedArray.Add(Testing);

	// Setup dynamically generated actors
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	NewActor->ActorName = NewActor->GetName();
	DynamicallyCreatedArray.Add(NewActor);

	// Setup array of structs
	FTArrayTestStruct Entry;
	Entry.RootProp = 42;
	ArrayOfStructs.Add(Entry);
	Entry.RootProp = 37;
	ArrayOfStructs.Add(Entry);

	// Setup of array of structs with net serialize
	FTestStructWithNetSerialize NetSerializeEntry;
	NetSerializeEntry.MyInt = 42;
	NetSerializeEntry.MyFloat = 25.0f;
	ArrayOfStructNetSerialize.Add(NetSerializeEntry);

	// Setup of array of C++ 11 style enums
	EnumTArray.Push(ETest8Enum::Enum_1);
	EnumTArray.Push(ETest8Enum::Enum_0);

	// Setup of array of Unreal style enums
	UEnumTArray.Push(EnumNamespace::Enum_1);
	UEnumTArray.Push(EnumNamespace::Enum_0);

	SignalReplicationSetup();
}

void ATestTArrayReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestTArrayReplication::SendTestResponseRPCImpl()
{
	// Empty due to the deferred execution
}

void ATestTArrayReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestTArrayReplication::ValidateReplication_Client(const TArray<UTestUObject*>& TestStablyNamedArray, 
														const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
														const TArray<FTArrayTestStruct>& TestArrayOfStructs,
														const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
														const TArray<ETest8Enum>& TestEnumTArray,
														const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray)
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
	check(TestDynamicallyCreatedActors.Num() == 1);
	// Assert on name rather than path name as the path name is different for each PIE instance.
	check(TestDynamicallyCreatedActors[0]->ActorName == TestDynamicallyCreatedActors[0]->GetName());

	// Validate TArray with structs
	check(TestArrayOfStructs.Num() == 2);
	check(TestArrayOfStructs[0].RootProp == 42);
	check(TestArrayOfStructs[1].RootProp == 37);

	// Validate TArray with structs and net serialize
	check(TestArrayOfStructNetSerialize.Num() == 1);
	check(TestArrayOfStructNetSerialize[0].MyInt == 42);
	check(TestArrayOfStructNetSerialize[0].MyFloat == 25.0f);

	// Validate TArray of C++ 11 style enums
	check(TestEnumTArray.Num() == 2);
	check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	// Setup of array of Unreal style enums
	check(TestUEnumTArray.Num() == 2);
	check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}

void ATestTArrayReplication::ValidateRPC_Server(const TArray<UTestUObject*>& TestStablyNamedArray, 
												const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
												const TArray<FTArrayTestStruct>& TestArrayOfStructs,
												const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
												const TArray<ETest8Enum>& TestEnumTArray,
												const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray)
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
	check(TestDynamicallyCreatedActors.Num() == 1);

	//Get the net driver
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	check(NetDriver);
	worker::EntityId RPCEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(TestDynamicallyCreatedActors[0]).ToSpatialEntityId();
	worker::EntityId ServerEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(DynamicallyCreatedArray[0]).ToSpatialEntityId();
	check(RPCEntityId == ServerEntityId);

	// Validate TArray with structs
	check(TestArrayOfStructs.Num() == 2);
	check(TestArrayOfStructs[0].RootProp == 42);
	check(TestArrayOfStructs[1].RootProp == 37);

	// Validate TArray of C++ 11 style enums
	check(TestEnumTArray.Num() == 2);
	check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	// Setup of array of Unreal style enums
	check(TestUEnumTArray.Num() == 2);
	check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}
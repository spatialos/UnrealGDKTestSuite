// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestUStructReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"
#include "SpatialNetDriver.h"
#include "Legacy/EntityRegistry.h"

void ATestUStructReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
	{
		bDynamicallyCreatedActorReplicated = false;
		bReplicationRecievedOnClient = false;

		ValidateReplication_Client(PODUStruct, 
								   NestedUStruct, 
								   UStructWithStablyNamedObject,
								   UStructWithDynamicallyCreatedActor, 
								   UStructWithNetSerialize, 
								   UStructWithCStyleArray, 
								   UStructWithTArray,
								   UStructWithUnrealStyleEnum,
								   UStructWithCppStyleEnum);

		Server_ReportReplication(PODUStruct, 
								 NestedUStruct,
								 UStructWithStablyNamedObject,
								 UStructWithDynamicallyCreatedActor,
								 UStructWithNetSerialize,
								 UStructWithCStyleArray,
								 UStructWithTArray,
								 UStructWithUnrealStyleEnum,
								 UStructWithCppStyleEnum);
	}
}

void ATestUStructReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, PODUStruct, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, NestedUStruct, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithStablyNamedObject, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithDynamicallyCreatedActor, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithNetSerialize, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithCStyleArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithTArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithUnrealStyleEnum, COND_None);
	DOREPLIFETIME_CONDITION(ATestUStructReplication, UStructWithCppStyleEnum, COND_None);
}

bool ATestUStructReplication::Server_ReportReplication_Validate(const FSimpleTestStruct& RepPODUStruct,
																const FNestedTestStruct& RepNestedUStruct,
																const FStablyNamedObjectTestStruct& RepUStructWithStablyNamedObject,
																const FDynamicallyCreatedActorTestStruct& RepUStructWithDynamicallyCreatedActor,
																const FTestStructWithNetSerialize& RepUStructWithNetSerialize,
																const FCArrayTestStruct& RepUStructWithCStyleArray,
																const FTArrayTestStruct& RepUStructWithTArray,
																const FUnrealStyleEnumTestStruct& RepUStructWithUnrealStyleEnum,
																const FCStyleEnumTestStruct& RepUStructWithCppStyleEnum)
{
	return true;
}

void ATestUStructReplication::Server_ReportReplication_Implementation(const FSimpleTestStruct& RepPODUStruct,
																	  const FNestedTestStruct& RepNestedUStruct,
																	  const FStablyNamedObjectTestStruct& RepUStructWithStablyNamedObject,
																	  const FDynamicallyCreatedActorTestStruct& RepUStructWithDynamicallyCreatedActor,
																	  const FTestStructWithNetSerialize& RepUStructWithNetSerialize,
																	  const FCArrayTestStruct& RepUStructWithCStyleArray,
																	  const FTArrayTestStruct& RepUStructWithTArray,
																	  const FUnrealStyleEnumTestStruct& RepUStructWithUnrealStyleEnum,
																	  const FCStyleEnumTestStruct& RepUStructWithCppStyleEnum)
{
	ValidateRPC_Server(RepPODUStruct,
					   RepNestedUStruct, 
					   RepUStructWithStablyNamedObject, 
					   RepUStructWithDynamicallyCreatedActor, 
					   RepUStructWithNetSerialize, 
					   RepUStructWithCStyleArray, 
					   RepUStructWithTArray,
					   RepUStructWithUnrealStyleEnum,
					   RepUStructWithCppStyleEnum);

	SignalResponseRecieved();
}

void ATestUStructReplication::StartTestImpl()
{
	// Setup UStruct with POD
	// PODArray.Add(42);
	// PODArray.Add(37);

	// Setup UStruct with a nested UStruct
	// UTestUObject* StablyNamedObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/SampleGame.Default__TestUObject"));

	// StablyNamedArray.Add(StablyNamedObject);
	// StablyNamedArray.Add(StablyNamedObject);

	// Setup UStruct with Stably named UObject
	// ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	// NewActor->ActorName = NewActor->GetName();
	// DynamicallyCreatedArray.Add(NewActor);

	// Setup UStruct with a dynamically created actor
	// FTArrayTestStruct Entry;
	// Entry.RootProp = 42;
	// ArrayOfStructs.Add(Entry);
	// Entry.RootProp = 37;
	// ArrayOfStructs.Add(Entry);

	// Setup UStruct with Netserialize
	// FTestStructWithNetSerialize NetSerializeEntry;
	// NetSerializeEntry.MyInt = 42;
	// NetSerializeEntry.MyFloat = 25.0f;
	// ArrayOfStructNetSerialize.Add(NetSerializeEntry);

	// Setup UStruct with C-style array
	// EnumTArray.Push(ETest8Enum::Enum_1);
	// EnumTArray.Push(ETest8Enum::Enum_0);

	// Setup UStruct with TArray
	// UEnumTArray.Push(EnumNamespace::Enum_1);
	// UEnumTArray.Push(EnumNamespace::Enum_0);

	// Setup UStruct with Unreal style enum

	// Setup UStruct with C++ 11 style enum

	SignalReplicationSetup();
}

void ATestUStructReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestUStructReplication::SendTestResponseRPCImpl()
{
	// Empty due to the deferred execution
}

void ATestUStructReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestUStructReplication::ValidateReplication_Client(const FSimpleTestStruct& TestPODUStruct,
														 const FNestedTestStruct& TestNestedUStruct,
														 const FStablyNamedObjectTestStruct& TestUStructWithStablyNamedObject,
														 const FDynamicallyCreatedActorTestStruct& TestUStructWithDynamicallyCreatedActor,
														 const FTestStructWithNetSerialize& TestUStructWithNetSerialize,
														 const FCArrayTestStruct& TestUStructWithCStyleArray,
														 const FTArrayTestStruct& TestUStructWithTArray,
														 const FUnrealStyleEnumTestStruct& TestUStructWithUnrealStyleEnum,
														 const FCStyleEnumTestStruct& TestUStructWithCppStyleEnum)
{
	//// Validate PODs
	//check(TestPODArray.Num() == 2);
	//check(TestPODArray[0] == 42);
	//check(TestPODArray[1] == 37);

	//// Validate the stably named object
	//check(TestStablyNamedArray.Num() == 2);

	//check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	//check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	//check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	//check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	//check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	//check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	//// Validate Dynamically created UObjects in the array
	//check(TestDynamicallyCreatedActors.Num() == 1);
	//// Assert on name rather than path name as the path name is different for each PIE instance.
	//check(TestDynamicallyCreatedActors[0]->ActorName == TestDynamicallyCreatedActors[0]->GetName());

	//// Validate TArray with structs
	//check(TestArrayOfStructs.Num() == 2);
	//check(TestArrayOfStructs[0].RootProp == 42);
	//check(TestArrayOfStructs[1].RootProp == 37);

	//// Validate TArray with structs and net serialize
	//check(TestArrayOfStructNetSerialize.Num() == 1);
	//check(TestArrayOfStructNetSerialize[0].MyInt == 42);
	//check(TestArrayOfStructNetSerialize[0].MyFloat == 25.0f);

	//// Validate TArray of C++ 11 style enums
	//check(TestEnumTArray.Num() == 2);
	//check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	//check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	//// Setup of array of Unreal style enums
	//check(TestUEnumTArray.Num() == 2);
	//check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	//check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}

void ATestUStructReplication::ValidateRPC_Server(const FSimpleTestStruct& TestPODUStruct,
												 const FNestedTestStruct& TestNestedUStruct,
												 const FStablyNamedObjectTestStruct& TestUStructWithStablyNamedObject,
												 const FDynamicallyCreatedActorTestStruct& TestUStructWithDynamicallyCreatedActor,
												 const FTestStructWithNetSerialize& TestUStructWithNetSerialize,
												 const FCArrayTestStruct& TestUStructWithCStyleArray,
												 const FTArrayTestStruct& TestUStructWithTArray,
												 const FUnrealStyleEnumTestStruct& TestUStructWithUnrealStyleEnum,
												 const FCStyleEnumTestStruct& TestUStructWithCppStyleEnum)
{
	// // Validate PODs
	// check(TestPODArray.Num() == 2);
	// check(TestPODArray[0] == 42);
	// check(TestPODArray[1] == 37);

	// // Validate the stably named object
	// int num = TestStablyNamedArray.Num();
	// check(num == 2);

	// check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	// check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	// check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	// check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	// check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// // Validate Dynamically created UObjects in the array
	// check(TestDynamicallyCreatedActors.Num() == 1);

	// //Get the net driver
	// USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	// check(NetDriver);
	// worker::EntityId RPCEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(TestDynamicallyCreatedActors[0]).ToSpatialEntityId();
	// worker::EntityId ServerEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(DynamicallyCreatedArray[0]).ToSpatialEntityId();
	// check(RPCEntityId == ServerEntityId);

	// // Validate TArray with structs
	// check(TestArrayOfStructs.Num() == 2);
	// check(TestArrayOfStructs[0].RootProp == 42);
	// check(TestArrayOfStructs[1].RootProp == 37);

	// // Validate TArray of C++ 11 style enums
	// check(TestEnumTArray.Num() == 2);
	// check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	// check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	// // Setup of array of Unreal style enums
	// check(TestUEnumTArray.Num() == 2);
	// check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	// check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}

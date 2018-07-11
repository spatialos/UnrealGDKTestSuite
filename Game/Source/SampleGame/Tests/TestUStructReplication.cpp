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
	PODUStruct.RootProp = 42;

	// Setup UStruct with a nested UStruct
	NestedUStruct.NestedStruct.RootProp = 42;

	// Setup UStruct with Stably named UObject
	UStructWithStablyNamedObject.StablyNamedObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/SampleGame.Default__TestUObject"));

	// Setup UStruct with a dynamically created actor
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	NewActor->ActorName = NewActor->GetName();
	UStructWithDynamicallyCreatedActor.DynamicallyCreatedActor = NewActor;

	// Setup UStruct with Netserialize
	UStructWithNetSerialize.MyInt = 42;
	UStructWithNetSerialize.MyFloat = 25.0f;

	// Setup UStruct with C-style array
	UStructWithCStyleArray.Array[0] = 42;
	UStructWithCStyleArray.Array[1] = 57;

	// Setup UStruct With TArray
	UStructWithTArray.Array.Add(42);
	UStructWithTArray.Array.Add(57);

	// Setup UStruct with Unreal style enum
	UStructWithUnrealStyleEnum.Test32Enum = ETest32Enum::Enum_1;

	// Setup UStruct with C++ 11 style enum
	UStructWithCppStyleEnum.UEnum = EnumNamespace::Enum_1;

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

void ATestUStructReplication::OnRep_UStructWithDynamicallyCreatedActor()
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
	// Validate PODs
	check(TestPODUStruct.RootProp == 42);

	// Validate UStruct with a nested UStruct
	check(TestNestedUStruct.NestedStruct.RootProp == 42);

	// Validate the stably named object
	check(TestUStructWithStablyNamedObject.StablyNamedObject->IsA(UTestUObject::StaticClass()));
	check(TestUStructWithStablyNamedObject.StablyNamedObject == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestUStructWithStablyNamedObject.StablyNamedObject->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));

	// Validate Dynamically created actors
	check(TestUStructWithDynamicallyCreatedActor.DynamicallyCreatedActor->IsA(ATestActor::StaticClass()));

	// Validate UStruct with Netserialize
	check(TestUStructWithNetSerialize.MyInt == 42);
	check(TestUStructWithNetSerialize.MyFloat == 25.0f);

	// Validate UStruct with C-style array
	check(TestUStructWithCStyleArray.Array[0] == 42);
	check(TestUStructWithCStyleArray.Array[1] == 57);

	// Validate UStruct With TArray
	check(TestUStructWithTArray.Array.Num() == 2);
	check(TestUStructWithTArray.Array[0] == 42);
	check(TestUStructWithTArray.Array[1] == 57);
	
	// Validate TArray of C++ 11 style enums
	check(TestUStructWithUnrealStyleEnum.Test32Enum == ETest32Enum::Enum_1);

	// Setup of array of Unreal style enums
	check(TestUStructWithCppStyleEnum.UEnum == EnumNamespace::Enum_1);
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
	// Validate PODs
	check(TestPODUStruct.RootProp == 42);

	// Validate UStruct with a nested UStruct
	check(TestNestedUStruct.NestedStruct.RootProp == 42);

	// Validate the stably named object
	check(TestUStructWithStablyNamedObject.StablyNamedObject->IsA(UTestUObject::StaticClass()));
	check(TestUStructWithStablyNamedObject.StablyNamedObject == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestUStructWithStablyNamedObject.StablyNamedObject->GetPathName() == TEXT("/Script/SampleGame.Default__TestUObject"));


	// Validate Dynamically created actors
	check(TestUStructWithDynamicallyCreatedActor.DynamicallyCreatedActor->IsA(ATestActor::StaticClass()));

	//Get the net driver
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	check(NetDriver);
	worker::EntityId RPCEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(TestUStructWithDynamicallyCreatedActor.DynamicallyCreatedActor).ToSpatialEntityId();
	worker::EntityId ServerEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(UStructWithDynamicallyCreatedActor.DynamicallyCreatedActor).ToSpatialEntityId();
	check(RPCEntityId == ServerEntityId);

	// Validate UStruct with Netserialize
	check(TestUStructWithNetSerialize.MyInt == 42);
	check(TestUStructWithNetSerialize.MyFloat == 25.0f);

	// Validate UStruct with C-style array
	check(TestUStructWithCStyleArray.Array[0] == 42);
	check(TestUStructWithCStyleArray.Array[1] == 57);

	// Validate UStruct With TArray
	check(TestUStructWithTArray.Array.Num() == 2);
	check(TestUStructWithTArray.Array[0] == 42);
	check(TestUStructWithTArray.Array[1] == 57);

	// Validate TArray of C++ 11 style enums
	check(TestUStructWithUnrealStyleEnum.Test32Enum == ETest32Enum::Enum_1);

	// Setup of array of Unreal style enums
	check(TestUStructWithCppStyleEnum.UEnum == EnumNamespace::Enum_1);
}

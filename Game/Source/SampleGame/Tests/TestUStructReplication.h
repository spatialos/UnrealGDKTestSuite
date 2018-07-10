// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "ReplicationTestUtils.h"
#include "TestUStructReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestUStructReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestUStructReplication()
		: bDynamicallyCreatedActorReplicated(false)
		, bReplicationRecievedOnClient(false)
	{ 
		TestName = TEXT("UStruct types"); 
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FSimpleTestStruct& RepPODUStruct,
								  const FNestedTestStruct& RepNestedUStruct,
								  const FStablyNamedObjectTestStruct& RepUStructWithStablyNamedObject,
								  const FDynamicallyCreatedActorTestStruct& RepUStructWithDynamicallyCreatedActor,
								  const FTestStructWithNetSerialize& RepUStructWithNetSerialize,
								  const FCArrayTestStruct& RepUStructWithCStyleArray,
								  const FTArrayTestStruct& RepUStructWithTArray,
								  const FUnrealStyleEnumTestStruct& RepUStructWithUnrealStyleEnum,
								  const FCStyleEnumTestStruct& RepUStructWithCppStyleEnum);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	// Test UStruct with POD
	UPROPERTY(Replicated)
	FSimpleTestStruct PODUStruct;

	// Test UStruct with a nested UStruct
	UPROPERTY(Replicated)
	FNestedTestStruct NestedUStruct;

	// Test UStruct with Stably named UObject
	UPROPERTY(Replicated)
	FStablyNamedObjectTestStruct UStructWithStablyNamedObject;

	// Test UStruct with a dynamically created actor
	UPROPERTY(Replicated)
	FDynamicallyCreatedActorTestStruct UStructWithDynamicallyCreatedActor;

	// Test UStruct with Netserialize
	UPROPERTY(Replicated)
	FTestStructWithNetSerialize UStructWithNetSerialize;

	// Test UStruct with C-style array
	UPROPERTY(Replicated)
	FCArrayTestStruct UStructWithCStyleArray;

	// Test UStruct with TArray
	UPROPERTY(Replicated)
	FTArrayTestStruct UStructWithTArray;

	// Test UStruct with Unreal style enum
	UPROPERTY(Replicated)
	FUnrealStyleEnumTestStruct UStructWithUnrealStyleEnum;

	// Test UStruct with C++ 11 style enum
	UPROPERTY(Replicated)
	FCStyleEnumTestStruct UStructWithCppStyleEnum;

private: 

	UFUNCTION()
	void OnRep_DynamicallyCreatedArray();

	void ValidateReplication_Client(const FSimpleTestStruct& TestPODUStruct,
									const FNestedTestStruct& TestNestedUStruct,
									const FStablyNamedObjectTestStruct& TestUStructWithStablyNamedObject,
									const FDynamicallyCreatedActorTestStruct& TestUStructWithDynamicallyCreatedActor,
									const FTestStructWithNetSerialize& TestUStructWithNetSerialize,
									const FCArrayTestStruct& TestUStructWithCStyleArray,
									const FTArrayTestStruct& TestUStructWithTArray,
									const FUnrealStyleEnumTestStruct& TestUStructWithUnrealStyleEnum,
									const FCStyleEnumTestStruct& TestUStructWithCppStyleEnum);

	void ValidateRPC_Server(const FSimpleTestStruct& TestPODUStruct,
							const FNestedTestStruct& TestNestedUStruct,
							const FStablyNamedObjectTestStruct& TestUStructWithStablyNamedObject,
							const FDynamicallyCreatedActorTestStruct& TestUStructWithDynamicallyCreatedActor,
							const FTestStructWithNetSerialize& TestUStructWithNetSerialize,
							const FCArrayTestStruct& TestUStructWithCStyleArray,
							const FTArrayTestStruct& TestUStructWithTArray,
							const FUnrealStyleEnumTestStruct& TestUStructWithUnrealStyleEnum,
							const FCStyleEnumTestStruct& TestUStructWithCppStyleEnum);

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;
};

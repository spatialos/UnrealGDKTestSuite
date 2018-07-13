// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "ReplicationTestUtils.h"
#include "TestUObjectReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestUObjectReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestUObjectReplication()
		: bDynamicallyCreatedActorReplicated(false)
		, bReplicationRecievedOnClient(false)
	{ 
		TestName = TEXT("UObjects types"); 
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(ATestActor* RepDynamicallyCreatedActor,
								  /*const TArray<UTestUObject*>& RepUObjectWithReplicatedComponent,*/
								  UTestUObject* RepStablyNamedUObject);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void Server_StartTestImpl() override;

	UFUNCTION()
	virtual void Server_TearDownImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

private: 

	UFUNCTION()
	void OnRep_DynamicallyCreatedActor();

	void ValidateReplication_Client(ATestActor* TestDynamicallyCreatedActor,
									/*const TArray<UTestUObject*>& TestUObjectWithReplicatedComponent,*/
									UTestUObject* TestStablyNamedUObject);

	void ValidateRPC_Server(ATestActor* TestDynamicallyCreatedActor,
							/*const TArray<UTestUObject*>& TestUObjectWithReplicatedComponent,*/
							UTestUObject* TestStablyNamedUObject);

	// Test Dynmaically created actor
	UPROPERTY(ReplicatedUsing = OnRep_DynamicallyCreatedActor)
	ATestActor* DynamicallyCreatedActor;

	// Test UObject with replicated component
	// TODO: UNR-238 Add tests.

	// Test Stably named UObject
	UPROPERTY(Replicated)
	UTestUObject* StablyNamedUObject;

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;
};

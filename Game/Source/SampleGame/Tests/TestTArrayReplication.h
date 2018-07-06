// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestTArrayReplication.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTestUObject : public UObject
{
	GENERATED_BODY()
public:

	UTestUObject() 
	{
		RootProp = 42;
	}

	UPROPERTY()
	int RootProp;
};

UCLASS()
class ATestActor  : public AActor
{
	GENERATED_BODY()
public:

	ATestActor();

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	UPROPERTY(Replicated)
	FString ActorName;

};

USTRUCT()
struct FTArrayTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int RootProp;
};

UCLASS()
class SAMPLEGAME_API ATestTArrayReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestTArrayReplication()
		: bDynamicallyCreatedActorReplicated(false)
	{ 
		TestName = TEXT("TArray with UObjects types"); 
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const TArray<UTestUObject*>& RepStablyNamedArray, const TArray<ATestActor*>& RepDynamicallyCreatedActors, const TArray<FTArrayTestStruct>& RepArrayOfStructs);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	//Test Array Stably name
	UPROPERTY(Replicated)
	TArray<UTestUObject*> StablyNamedArray;

	//Test array Dynamic
	UPROPERTY(ReplicatedUsing = OnRep_DynamicallyCreatedArray)
	TArray<ATestActor*> DynamicallyCreatedArray;

	UPROPERTY(Replicated)
	TArray<FTArrayTestStruct> ArrayOfStructs;

private: 

	UFUNCTION()
	void OnRep_DynamicallyCreatedArray();

	void ValidateReplication_Client(const TArray<UTestUObject*>& TestStablyNamedArray, const TArray<ATestActor*>& TestDynamicallyCreatedActors, const TArray<FTArrayTestStruct>& TestArrayOfStructs);
	void ValidateRPC_Server(const TArray<UTestUObject*>& TestStablyNamedArray, const TArray<ATestActor*>& TestDynamicallyCreatedActors, const TArray<FTArrayTestStruct>& TestArrayOfStructs);

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;
};

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "Components/ActorComponent.h"
#include "TestStaticComponentReplication.generated.h"

UCLASS()
class TESTSUITE_API UTestComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	UTestComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_TestProperty();


	UPROPERTY(ReplicatedUsing = OnRep_TestProperty)
	float TestProperty;
};

UCLASS()
class TESTSUITE_API ATestStaticComponentReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestStaticComponentReplication();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(float RepFloat);

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

	UPROPERTY()
	UTestComponent* TestComponent;
};

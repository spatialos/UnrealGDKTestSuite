// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestBoolReplication.generated.h"

UCLASS()
class TESTSUITE_API ATestBoolReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestBoolReplication() 
		: TestBool(false)
	{ 
		TestName = TEXT("Bool types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(bool RepBool);

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

	UPROPERTY(Replicated)
	bool TestBool;
};

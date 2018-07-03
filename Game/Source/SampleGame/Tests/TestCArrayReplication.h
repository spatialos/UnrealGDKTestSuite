// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestCArrayReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestCArrayReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestCArrayReplication()
		: FirstComparisonValue(-42)
		, SecondComparisonValue(56)
	{ 
		TestPOD[0] = 0;
		TestPOD[1] = 0;
		TestName = TEXT("C-Style Array types"); 
	}

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(/*int RepCArray[2]*/);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	UPROPERTY(Replicated)
	int TestPOD[2];

	int FirstComparisonValue;
	int SecondComparisonValue;
};

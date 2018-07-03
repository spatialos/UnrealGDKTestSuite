// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFloatReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestFloatReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFloatReplication() 
		: FloatComparisonValue(25.0f)
		, DoubleComparisonValue(50.0)
	{ 
		TestName = TEXT("Float types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(float RepFloat, double RepDouble);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	UPROPERTY(Replicated)
	float TestFloat;

	UPROPERTY(Replicated)
	double TestDouble;

	float FloatComparisonValue;
	double DoubleComparisonValue;
};

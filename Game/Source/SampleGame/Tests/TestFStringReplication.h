// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFStringReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestFStringReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFStringReplication() 
		: TestFString("")
	{ 
		TestName = "FString types"; 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FString& RepFString);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	UPROPERTY(Replicated)
	FString TestFString;
};

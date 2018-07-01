// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Char.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestCharReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestCharReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestCharReplication() { TestName == "Char types"; }

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_TestCharFunc();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;
};

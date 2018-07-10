// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFNameReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestFNameReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFNameReplication() 
	{ 
		TestName = TEXT("FName types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FName& RepFName);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	UPROPERTY(Replicated)
	FName TestFName;
};

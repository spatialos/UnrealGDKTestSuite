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
		: ValidationName(TEXT("Rosebud"))
	{ 
		TestName = TEXT("FName types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FName& RepFName);

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
	FName TestFName;

	FName ValidationName;
};

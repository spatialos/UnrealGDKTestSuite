// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

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
		: TestFString(TEXT(""))
		, ComparisonValue(TEXT("Here's Johnny!"))
	{ 
		TestName = TEXT("FString types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FString& RepFString);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void TearDownImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	FString TestFString;

	const FString ComparisonValue;
};

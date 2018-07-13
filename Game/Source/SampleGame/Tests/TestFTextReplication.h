// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFTextReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestFTextReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFTextReplication() 
		: ValidationText(FText::FromString(TEXT("You're gonna need a bigger boat.")))
	{ 
		TestName = TEXT("FText types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FText& RepFText);

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
	FText TestFText;

	FText ValidationText;
};

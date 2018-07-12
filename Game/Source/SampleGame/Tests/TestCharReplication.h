// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

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

	ATestCharReplication() { TestName = TEXT("Char types"); }

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void TearDownImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;
};

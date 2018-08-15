// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Misc/Char.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestCharReplication.generated.h"

UCLASS(SpatialType)
class TESTSUITE_API ATestCharReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestCharReplication() { TestName = TEXT("Char types"); }

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void Server_StartTestImpl() override;

	UFUNCTION()
	virtual void Server_TearDownImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;
};

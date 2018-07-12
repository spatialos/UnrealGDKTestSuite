// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.generated.h"

UCLASS(Abstract)
class SAMPLEGAME_API AReplicationTestCase : public AGDKTestCase
{
	GENERATED_BODY()

public:

	AReplicationTestCase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void StartTest() override;

	virtual void TearDown() override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_StartTest();

	UFUNCTION()
	void OnRep_TestBookend();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:

	UFUNCTION()
	void SignalReplicationSetup();

	UFUNCTION()
	void SignalResponseRecieved();

	UFUNCTION()
	virtual void StartTestImpl()
	PURE_VIRTUAL(AReplicationTestCase::StartTestImpl(), );

	UFUNCTION()
	virtual void TearDownImpl()
	PURE_VIRTUAL(AReplicationTestCase::TearDownImpl(), );

	UFUNCTION()
	virtual void ValidateClientReplicationImpl()
	PURE_VIRTUAL(AReplicationTestCase::ValidateClientReplicationImpl(), );

	UFUNCTION()
	virtual void SendTestResponseRPCImpl()
	PURE_VIRTUAL(AReplicationTestCase::SendTestResponseRPCImpl(), );

private:

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY()
	int RPCResponsecCount;

	bool bRunning;

	bool bSuccess;
};

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialGDKTests, Log, All);

UCLASS(Abstract)
class SAMPLEGAME_API AReplicationTestCase : public AActor
{
	GENERATED_BODY()

public:

	AReplicationTestCase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
	virtual void ValidateClientReplicationImpl()
	PURE_VIRTUAL(AReplicationTestCase::ValidateClientReplicationImpl(), );

	UFUNCTION()
	virtual void SendTestResponseRPCImpl()
	PURE_VIRTUAL(AReplicationTestCase::SendTestResponseRPCImpl(), );

	UPROPERTY()
	FString TestName;

private:

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY()
	int RPCResponsecCount;

	bool bRunning;

	bool bSuccess;
};

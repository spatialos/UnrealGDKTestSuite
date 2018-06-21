// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.generated.h"

UCLASS(Abstract)
class SAMPLEGAME_API AReplicationTestCase : public AActor
{
	GENERATED_BODY()

public:

	AReplicationTestCase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnRep_TestBookend();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:

	UFUNCTION()
	void SignalReplicationSetup();

	UFUNCTION()
	void SignalResponseRecieved();

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
};

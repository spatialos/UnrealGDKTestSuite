// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "TestUObjectContexts.generated.h"

class ATestActor;
class UTestUObject;

UCLASS(SpatialType)
class TESTSUITE_API ATestUObjectContexts : public AGDKTestCase
{
	GENERATED_BODY()

public:

	ATestUObjectContexts();

	virtual void Tick(float DeltaTime) override;

	virtual void Server_StartTest() override;

	virtual void Server_TearDown() override;

protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastRPC();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportResult();

private:

	UFUNCTION()
	void OnRep_StablyNamedUObject();

	UPROPERTY(Replicated)
	UObject* BasicUObject;

	UPROPERTY(Replicated)
    ATestActor* ActorPointer;

	UPROPERTY(ReplicatedUsing = OnRep_StablyNamedUObject)
    UTestUObject* StablyNamedUObjectC;


	UPROPERTY()
	ATestActor* TestActorArray[6];

	UPROPERTY()
	TArray<ATestActor*> TestDynamicActorArray;

	// TODO:
	// Staticly named object;
	// Sub object test
	// Handover test

	int32 BroadcastValue;

	uint32 RPCResponseCount;

	bool bRunning;

	bool bSuccess;
};

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

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportResult();

private:

	void Validate_Client();

	UFUNCTION()
	void OnRep_BasicUObject();

	UFUNCTION()
	void OnRep_ActorPointer();

	UFUNCTION()
	void OnRep_StablyNamedUObject();

	UPROPERTY(ReplicatedUsing = OnRep_BasicUObject)
	UObject* BasicUObject;

	UPROPERTY(ReplicatedUsing = OnRep_ActorPointer)
    ATestActor* ActorPointer;

	UPROPERTY(ReplicatedUsing = OnRep_StablyNamedUObject)
    UTestUObject* StablyNamedUObject;

	// TODO UNR-633
	// Array tests

	// TODO UNR-634
	// Handover tests

	int32 BroadcastValue;
	uint32 RPCResponseCount;

	bool bRunning;
	bool bSuccess;

	bool bBasicUObjectReceived;
	bool bActorPointerReceived;
	bool bStablyNamedUObjectReceived;
};

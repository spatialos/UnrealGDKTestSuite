// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestSuitePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTSUITE_API ATestSuitePlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

public:

	virtual void InitPlayerState() override;
};

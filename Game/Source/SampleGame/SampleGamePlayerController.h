// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SampleGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGamePlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

public:

	virtual void InitPlayerState() override;
};

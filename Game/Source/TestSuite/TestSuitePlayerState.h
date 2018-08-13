// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TestSuitePlayerState.generated.h"

UCLASS(Spatial)
class ATestSuitePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATestSuitePlayerState();
};

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Commander.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameTestClasses.generated.h"


UCLASS(config=Game)
class AS_TestUnderscoreClassName : public AActor
{
	GENERATED_BODY()

public:
	AS_TestUnderscoreClassName();

	UFUNCTION(Client, Reliable)
	void ClientUnderscoreRPC();
};


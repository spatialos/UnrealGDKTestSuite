// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Commander.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameTestClasses.generated.h"


USTRUCT()
struct FRootStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int RootProp;
};

USTRUCT()
struct FContainerStruct
{
	GENERATED_BODY()

	UPROPERTY()
	FRootStruct Struct_1;

	UPROPERTY()
	FRootStruct Struct_2;
};

UCLASS()
class ARepCmdConfusion : public AActor
{
	GENERATED_BODY()

public:
	ARepCmdConfusion();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	FContainerStruct MyStruct;
};

UCLASS(config=Game)
class AS_TestUnderscoreClassName : public AActor
{
	GENERATED_BODY()

public:
	AS_TestUnderscoreClassName();

	UFUNCTION(Client, Reliable)
	void ClientUnderscoreRPC();
};


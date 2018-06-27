// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "TestNestedStructs.generated.h"


USTRUCT(BlueprintType)
struct FRootStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int RootProp; // Root Prop int

	UPROPERTY()
	int Root_Array[2];
};

USTRUCT(BlueprintType)
struct FContainerStruct	 // Parent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FRootStruct Struct_Red;

	UPROPERTY()
	FRootStruct Struct_Blue;

	UPROPERTY()
	FRootStruct Struct_Array[2];

	UPROPERTY()
	FRootStruct Struct_Array_ANOTHER[2];

	UPROPERTY()
	int Container_Int_Array[2];

	UPROPERTY()
	TArray<FRootStruct> Dynamic_Struct_Array;
};

USTRUCT()
struct FContainerContainerStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FContainerStruct Struct_ContainerCar;

	UPROPERTY()
	FContainerStruct Struct_ContainerPlane;
};

USTRUCT()
struct FContainerContainerContainerStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FContainerContainerStruct Struct_ContainerContainerDog;

	UPROPERTY()
	FContainerContainerStruct Struct_ContainerContainerCat;
};

USTRUCT()
struct FTheOneStructToRuleThemAll
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FContainerContainerContainerStruct Struct_ContainerContainerContainer;

	UPROPERTY()
	FContainerContainerStruct Struct_ContainerContainer;

	UPROPERTY()
	FContainerStruct Struct_Container;

	UPROPERTY()
	FRootStruct Struct_Root;

	UPROPERTY()
	int RootProp;
};

UCLASS(config = Game)
class UTestNestedStructs : public UObject
{
	GENERATED_BODY()
public:
	UTestNestedStructs();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	FContainerStruct TestContainerStruct;

	UPROPERTY(Replicated)
	FContainerStruct TestContainerStructArray[2];

	UPROPERTY(Replicated)
	FContainerStruct TestContainerStructTheSecond;

	UPROPERTY(Replicated)
	FContainerContainerStruct TestContainerContainerStruct;

	UPROPERTY(Replicated)
	FContainerContainerContainerStruct TestContainerContainerContainerStruct;

	//UPROPERTY(Replicated)
	//FTheOneStructToRuleThemAll TestTheOneStructToRuleThemAll;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	//FTestStruct TheTestStruct;
};
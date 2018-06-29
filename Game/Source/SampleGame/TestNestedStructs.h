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

	UPROPERTY()
	FString String_Array[2];
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

// -- Custom struct definition with NetSerialize
USTRUCT(BlueprintType)
struct FTestStruct
{
	GENERATED_USTRUCT_BODY()

public:
	FTestStruct() : TestInt(0) {}
	FTestStruct(int32 ti) : TestInt(ti) {}
	FString ToString() const;

	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);

	bool operator==(const FTestStruct& Other) const
	{
		return TestInt == Other.TestInt;
	}

	UPROPERTY()
		int32 NonSerializedInt;

	int32 TestInt;
};

template<>
struct TStructOpsTypeTraits<FTestStruct> : public TStructOpsTypeTraitsBase2<FTestStruct>
{
	enum
	{
		WithNetSerializer = true,
		WithIdenticalViaEquality = true
	};
};
// -- End Custom struct definition with NetSerialize

// -- Custom struct definition without NetSerialize.
USTRUCT(BlueprintType)
struct FTestStructNoNetSerialize
{
	GENERATED_USTRUCT_BODY()

public:
	FTestStructNoNetSerialize() : TestIntNoNetSerialize(0) {}
	FTestStructNoNetSerialize(int32 ti) : TestIntNoNetSerialize(ti) {}
	FString ToString() const;

	bool operator==(const FTestStructNoNetSerialize& Other) const
	{
		return TestIntNoNetSerialize == Other.TestIntNoNetSerialize;
	}

	UPROPERTY(BlueprintReadWrite)
		int32 TestIntNoNetSerialize;

	UPROPERTY(BlueprintReadWrite)
		FString TestFStringNoNetSerialize;
};
// -- End Custom struct definition without NetSerialize

// -- Custom struct definition with c-style array.
USTRUCT(BlueprintType)
 struct FTestStructCStyleArray
 {
	GENERATED_USTRUCT_BODY()
		
	public:
		FTestStructCStyleArray() : TestInt(0) {}
		FTestStructCStyleArray(int32 ti) : TestInt(ti) {}
		FString ToString() const;

		bool operator==(const FTestStructCStyleArray& Other) const
		{
			return TestInt == Other.TestInt;
		}

		UPROPERTY(BlueprintReadWrite)
		int32 NonSerializedInt;

		UPROPERTY(BlueprintReadWrite)
		int32 TestInt;

		UPROPERTY()
		int32 TestIntArray[3];

		UPROPERTY()
		FTestStruct NetSerializeStruct[2];

		UPROPERTY()
		FTestStructNoNetSerialize NoNetSerializeStruct[2];
};
// -- End Custom struct definition with c-style array


UCLASS(config = Game)
class UTestNestedStructs : public UObject
{
	GENERATED_BODY()
public:
	UTestNestedStructs();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	FContainerStruct TestContainerStruct;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DoTheThing(const FString& PrintMe, const FTestStruct& TheTestStructRPC);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DoTheThingCStyleArray(const FString& PrintMe, const FTestStructCStyleArray& TheTestStructCStyleArrayRPC, const TArray<FTestStructCStyleArray>& DynamicStructArrayRPC);

	UPROPERTY(Replicated)
	class USkeletalMesh* m_equippedSkeletalMeshes[3];

	//UPROPERTY(Replicated)
	//FContainerStruct TestContainerStructArray[2];

	//UPROPERTY(Replicated)
	//FContainerStruct TestContainerStructTheSecond;

	//UPROPERTY(Replicated)
	//FContainerContainerStruct TestContainerContainerStruct;

	//UPROPERTY(Replicated)
	//FContainerContainerContainerStruct TestContainerContainerContainerStruct;

	//UPROPERTY(Replicated)
	//FTheOneStructToRuleThemAll TestTheOneStructToRuleThemAll;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	//FTestStruct TheTestStruct;
};

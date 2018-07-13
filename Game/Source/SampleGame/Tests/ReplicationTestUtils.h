// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "ReplicationTestUtils.generated.h"

// Enum test types begin
UENUM()
enum class ETest8Enum : uint8
{
	Enum_0,
	Enum_1,

	Enum_Count UMETA(Hidden),
};

UENUM()
enum class ETest16Enum : uint16
{
	Enum_0,
	Enum_1,

	Enum_Count UMETA(Hidden),
};

UENUM()
enum class ETest32Enum : uint32
{
	Enum_0,
	Enum_1,

	Enum_Count UMETA(Hidden),
};

UENUM()
enum class ETest64Enum : int64
{
	Enum_0,
	Enum_1,

	Enum_Count UMETA(Hidden),
};

UENUM()
namespace EnumNamespace
{
	enum EUnrealTestEnum
	{
		Enum_0,
		Enum_1,
	};
}
// Enum test types end

// Actor test types begin
UCLASS()
class ATestActor : public AActor
{
	GENERATED_BODY()
public:

	ATestActor();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	UPROPERTY(Replicated)
	FString ActorName;

};
// Actor test types end

// UObject test types begin
UCLASS(BlueprintType, Blueprintable)
class UTestUObject : public UObject
{
	GENERATED_BODY()
public:

	UTestUObject()
		: RootProp(0)
	{
	}

	UPROPERTY()
	int RootProp;
};
// UObject test types end

// Struct test types begin
USTRUCT()
struct FSimpleTestStruct
{
	GENERATED_BODY()

	FSimpleTestStruct() 
		: RootProp(-1)
	{
	}

	UPROPERTY()
	int RootProp;
};

USTRUCT()
struct FNestedTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	FSimpleTestStruct NestedStruct;
};

USTRUCT()
struct FStablyNamedObjectTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	UTestUObject* StablyNamedObject;
};

USTRUCT()
struct FConstStablyNamedObjectTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	const UTestUObject* StablyNamedObject;
};

USTRUCT()
struct FDynamicallyCreatedActorTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	ATestActor* DynamicallyCreatedActor;
};

USTRUCT()
struct FTestStructWithNetSerialize
{
	GENERATED_BODY();

	UPROPERTY()
	int MyInt;

	UPROPERTY()
	float MyFloat;

	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
	{
		Ar << MyInt;
		Ar << MyFloat;

		return true;
	}
};

template<>
struct TStructOpsTypeTraits<FTestStructWithNetSerialize> : public TStructOpsTypeTraitsBase2<FTestStructWithNetSerialize>
{
	enum
	{
		WithNetSerializer = true
	};
};

USTRUCT()
struct FCArrayTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int Array[2];
};

USTRUCT()
struct FTArrayTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int> Array;
};

USTRUCT()
struct FUnrealStyleEnumTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	ETest32Enum Test32Enum;
};

USTRUCT()
struct FCStyleEnumTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	TEnumAsByte<EnumNamespace::EUnrealTestEnum> UEnum;
};
// Struct test types end

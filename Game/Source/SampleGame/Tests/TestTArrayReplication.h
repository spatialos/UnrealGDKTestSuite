// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestEnumReplication.h"
#include "TestTArrayReplication.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTestUObject : public UObject
{
	GENERATED_BODY()
public:

	UTestUObject() 
	{
		RootProp = 42;
	}

	UPROPERTY()
	int RootProp;
};

UCLASS()
class ATestActor  : public AActor
{
	GENERATED_BODY()
public:

	ATestActor();

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	UPROPERTY(Replicated)
	FString ActorName;

};

USTRUCT()
struct FTArrayTestStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int RootProp;
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
		EStructFlags Flags = FTestStructWithNetSerialize::StaticStruct()->StructFlags;

		if (Flags & STRUCT_NetSerializeNative)
		{
			UE_LOG(LogTemp, Warning, TEXT("native flag - %x0x"), Flags)
		}

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
struct FTArrayTestStructWithNestedArrays
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<int> MyArray;
};


UCLASS()
class SAMPLEGAME_API ATestTArrayReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestTArrayReplication()
		: bDynamicallyCreatedActorReplicated(false)
	{ 
		TestName = TEXT("TArray with UObjects types"); 
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const TArray<UTestUObject*>& RepStablyNamedArray, 
								  const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
								  const TArray<FTArrayTestStruct>& RepArrayOfStructs,
								  const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
								  const TArray<ETest8Enum>& RepEnumTArray,
								  const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void StartTestImpl() override;

	UFUNCTION()
	virtual void ValidateClientReplicationImpl() override;

	UFUNCTION()
	virtual void SendTestResponseRPCImpl() override;

	// Test array Stably name
	UPROPERTY(Replicated)
	TArray<UTestUObject*> StablyNamedArray;

	// Test array Dynamic
	UPROPERTY(ReplicatedUsing = OnRep_DynamicallyCreatedArray)
	TArray<ATestActor*> DynamicallyCreatedArray;

	// Test array of structs
	UPROPERTY(Replicated)
	TArray<FTArrayTestStruct> ArrayOfStructs;

	// Test array of structs net serialize
	UPROPERTY(Replicated)
	TArray<FTestStructWithNetSerialize> ArrayOfStructNetSerialize;

	// Test array of C++ 11 style enums
	UPROPERTY(Replicated)
	TArray<ETest8Enum> EnumTArray;

	// Test array of Unreal style enums
	UPROPERTY(Replicated)
	TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>> UEnumTArray;

private: 

	UFUNCTION()
	void OnRep_DynamicallyCreatedArray();

	void ValidateReplication_Client(const TArray<UTestUObject*>& TestStablyNamedArray, 
									const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
									const TArray<FTArrayTestStruct>& TestArrayOfStructs,
									const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
									const TArray<ETest8Enum>& TestEnumTArray,
									const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray);

	void ValidateRPC_Server(const TArray<UTestUObject*>& TestStablyNamedArray, 
							const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
							const TArray<FTArrayTestStruct>& TestArrayOfStructs,
							const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
							const TArray<ETest8Enum>& TestEnumTArray,
							const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray);

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;
};
// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#pragma optimize("", off)

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "Tests/TestIntReplication.h"
#include "Tests/TestFloatReplication.h"
#include "Tests/TestBoolReplication.h"
#include "SampleGameCharacter.generated.h"

USTRUCT(BlueprintType)
struct FTestMixedStruct
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadOnly)
		APlayerState* PS;

	UPROPERTY()
		float FVar;

	UPROPERTY()
		float IVar;

	void Modify()
	{
		FVar += 1.f;
		IVar++;
	}
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
			UE_LOG( LogTemp, Warning, TEXT("native flag - %x0x"), Flags)
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

USTRUCT(BlueprintType)
struct FTestPODStruct
{
	GENERATED_BODY();

	UPROPERTY()
		float FVar;

	UPROPERTY()
		int IVar;

	UPROPERTY()
		double DVar;

	void Modify()
	{
		FVar += 1.f;
		IVar++;
		DVar += 1.0;
	}
};

USTRUCT()
struct FConstStruct
{
	GENERATED_BODY();

	UPROPERTY()
		const UObject* ConstObj;
};

USTRUCT()
struct FCArrayStruct
{
	GENERATED_BODY();

	UPROPERTY()
		int CIntArray[8];

	UPROPERTY()
		float CFloatArray[8];
};

// Enum tests start
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
// Enum tests end


USTRUCT(BlueprintType)
struct FFoo
{
	GENERATED_BODY()

    UPROPERTY()
    int FooMember;
};

USTRUCT(BlueprintType)
struct FBar
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FFoo> CantReplicateThisMember;

	UPROPERTY()
		FTestStructWithNetSerialize MyStruct;

	UPROPERTY()
	FRepMovement NetSerializeStruct;
};


UCLASS(config = Game)
class ASampleGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ASampleGameCharacter();

	virtual void BeginPlay() override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(ReplicatedUsing = OnRep_TestPODArray)
	TArray<float> TestPODArray;

	UPROPERTY(Replicated)
	TArray<FTestMixedStruct> TestMixedStructArray;

	UPROPERTY(Replicated)
	TArray<FTestPODStruct> TestPODStructArray;

	UPROPERTY(Replicated)
	TArray<FRepMovement> TestNetSerializeArray;

	UPROPERTY(Replicated)
	FTestMixedStruct TestMixedStruct;

	UPROPERTY(Replicated)
	FTestPODStruct TestPODStruct;

	UPROPERTY(Replicated)
	USkeletalMesh* StablyNamedObj;

	//UPROPERTY(Replicated)
	//TArray<UObject*> TestObjectArray;

	UPROPERTY(Replicated)
	int TestCArrayReplication[8];

	//UPROPERTY(Replicated)
	//FCArrayStruct TestCArrayStructReplication;

	//UPROPERTY(Replicated)
	//FTestMixedStruct TestMixedStructCArrayReplication[8];

	// Enum properties begin
	UPROPERTY(Replicated)
	ETest8Enum Test8Enum;

	UPROPERTY(Replicated)
	ETest16Enum Test16Enum;

	UPROPERTY(Replicated)
	ETest32Enum Test32Enum;

	UPROPERTY(Replicated)
	ETest64Enum Test64Enum;

	//UPROPERTY(Replicated)
	//ETest8Enum TestEnumCArray[16];

	UPROPERTY(Replicated)
	TArray<ETest8Enum> TestEnumTArray;

	UPROPERTY(Replicated)
	TEnumAsByte<EnumNamespace::EUnrealTestEnum> TestUEnum;

	//UPROPERTY(Replicated)
	//TEnumAsByte<EnumNamespace::EUnrealTestEnum> TestUEnumCArray[16];

	UPROPERTY(Replicated)
	TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>> TestUEnumTArray;
	// Enum properties end

	// POD properties begin
	UPROPERTY(Replicated)
	int8 Test8Int;

	UPROPERTY(Replicated)
	int16 Test16Int;

	UPROPERTY(Replicated)
	int32 Test32Int;

	UPROPERTY(Replicated)
	int64 Test64Int;

	UPROPERTY(Replicated)
	uint8 Test8UInt;

	UPROPERTY(Replicated)
	uint16 Test16UInt;

	UPROPERTY(Replicated)
	uint32 Test32UInt;

	UPROPERTY(Replicated)
	uint64 Test64UInt;

	UPROPERTY(Replicated)
	float TestFloat;

	UPROPERTY(Replicated)
	double TestDouble;
	// POD properties end

	UPROPERTY(Replicated)
	TArray<FBar> BarArray;

	UPROPERTY(Replicated)
	FBar TestBar;

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY(Replicated)
	ATestIntReplication* IntRepTest;

	UPROPERTY(Replicated)
	ATestFloatReplication* FloatRepTest;

	UPROPERTY(Replicated)
	ATestBoolReplication* BoolRepTest;

	UFUNCTION(Client, Reliable)
	void Client_TestConstArgs(FConstStruct ConstStruct);

	UFUNCTION(Server, Reliable, WithValidation)
	//void Server_TestFunc(const TArray<FTestMixedStruct>& StructArg);
	void Server_TestFunc();

	UFUNCTION(Client, Reliable)
	void Client_TestFunc();

	UFUNCTION()
	void OnRep_TestPODArray();

	UFUNCTION()
	void OnRep_TestBookend();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	void DebugCmd();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void Interact();

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

#pragma optimize("", on)
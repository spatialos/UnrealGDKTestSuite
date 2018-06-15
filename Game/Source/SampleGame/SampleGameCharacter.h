// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EngineMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameCharacter.generated.h"

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

UCLASS(config=Game)
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

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void BeginPlay() override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTestStruct TheTestStruct;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FTestStructCStyleArray TheTestStructCStyleArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FTestStructCStyleArray> TheTestStructDynamicStructArray;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DoTheThing(const FString& PrintMe, const FTestStruct& TheTestStructRPC);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void DoTheThingCStyleArray(const FString& PrintMe, const FTestStructCStyleArray& TheTestStructCStyleArrayRPC, const TArray<FTestStructCStyleArray>& DynamicStructArrayRPC);

	UFUNCTION(BlueprintCallable)
	void IncrementTestInt();

	UFUNCTION(BlueprintCallable)
	void IncrementTestIntArray();

	UFUNCTION(BlueprintCallable)
	void IncrementDynamicStructArray();

	UPROPERTY(Replicated)
	int32 CStyleTestIntArrayProperty[3];

	UPROPERTY(Replicated)
	FTestStructCStyleArray TheTestStructStaticStructArray[3];
	

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

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void Interact();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};


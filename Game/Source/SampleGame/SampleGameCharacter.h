// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameCharacter.generated.h"

//USTRUCT()
//struct FRootStruct
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY()
//	int RootProp; // Root Prop int
//};
//
//USTRUCT()
//struct FContainerStruct // Parent
//{
//	GENERATED_USTRUCT_BODY()
//
//	//UPROPERTY()
//	//FRootStruct Struct_Red; // Ignored
//
//	//UPROPERTY()
//	//FRootStruct Struct_Blue;
//
//	UPROPERTY()
//	FRootStruct Struct_Array[2];
//
//	UPROPERTY()
//	FRootStruct Struct_Array_ANOTHER[2];
//
//	UPROPERTY()
//	//TArray<FRootStruct> Dynamic_Struct_Array;
//};
//
//USTRUCT()
//struct FContainerContainerStruct
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY()
//	FContainerStruct Struct_ContainerCar;
//
//	UPROPERTY()
//	FContainerStruct Struct_ContainerPlane;
//};
//
//USTRUCT()
//struct FContainerContainerContainerStruct
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY()
//	FContainerContainerStruct Struct_ContainerContainerDog;
//
//	UPROPERTY()
//	FContainerContainerStruct Struct_ContainerContainerCat;
//};
//
//USTRUCT()
//struct FTheOneStructToRuleThemAll
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY()
//	FContainerContainerContainerStruct Struct_ContainerContainerContainer;
//
//	UPROPERTY()
//	FContainerContainerStruct Struct_ContainerContainer;
//
//	UPROPERTY()
//	FContainerStruct Struct_Container;
//
//	UPROPERTY()
//	FRootStruct Struct_Root;
//
//	UPROPERTY()
//	int RootProp;
//};

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

	//UPROPERTY(Replicated)
	//FContainerStruct TestContainerStruct;

	////UPROPERTY(Replicated)
	//FContainerStruct TestContainerStructTheSecond;

	//UPROPERTY(Replicated)
	//FContainerContainerStruct TestContainerContainerStruct;

	//UPROPERTY(Replicated)
	//FContainerContainerContainerStruct TestContainerContainerContainerStruct;

	//UPROPERTY(Replicated)
	//FTheOneStructToRuleThemAll TestTheOneStructToRuleThemAll;

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	//FTestStruct TheTestStruct;


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


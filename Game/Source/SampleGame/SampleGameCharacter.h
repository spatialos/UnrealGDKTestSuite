// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameCharacter.generated.h"

USTRUCT(BlueprintType)
struct FTestMixedStruct
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadOnly)
		APlayerState* PS;

	UPROPERTY()
		TWeakObjectPtr<UActorComponent> WeakPtr;

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

USTRUCT(BlueprintType)
struct FTestPODStruct
{
	GENERATED_BODY();

private:
	UPROPERTY()
		float FVar;

public:
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

UENUM()
enum class ETestEnum : uint8
{
	Enum_0,
	Enum_1,

	Enum_Count UMETA(Hidden),
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

	//UPROPERTY(Replicated)
	//TArray<ETestEnum> TestEnumArray;

	//UPROPERTY(Replicated)
	//TArray<UObject*> TestObjectArray;

	UPROPERTY(Replicated)
	int TestCArrayReplication[8];

	//UPROPERTY(Replicated)
	//FCArrayStruct TestCArrayStructReplication;

	//UPROPERTY(Replicated)
	//FTestMixedStruct TestMixedStructCArrayReplication[8];

	//UPROPERTY(Replicated)
	//ETestEnum TestEnum;

	UPROPERTY(Replicated)
	int TestBookend;

	UFUNCTION(Client, Reliable)
	void Client_TestConstArgs(USkeletalMesh* TestMesh);

	UFUNCTION(server, reliable, WithValidation)
	//void Server_TestFunc(const TArray<FTestMixedStruct>& StructArg);
	void Server_TestFunc(USkeletalMesh* TestMesh);

	UFUNCTION()
	void OnRep_TestPODArray();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
		USkeletalMesh* RepMesh;

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

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

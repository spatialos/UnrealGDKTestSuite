// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#pragma optimize("", off)

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "Tests/TestIntReplication.h"
#include "Tests/TestFloatReplication.h"
#include "Tests/TestBoolReplication.h"
#include "Tests/TestCharReplication.h"
#include "Tests/TestFStringReplication.h"
#include "Tests/TestCArrayReplication.h"
#include "Tests/TestTArrayReplication.h"
#include "Tests/TestEnumReplication.h"
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

	UPROPERTY(Replicated)
	TArray<FBar> BarArray;

	UPROPERTY(Replicated)
	FBar TestBar;

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY(ReplicatedUsing = OnRep_IntRepTest)
	ATestIntReplication* IntRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_FloatRepTest)
	ATestFloatReplication* FloatRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_BoolRepTest)
	ATestBoolReplication* BoolRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_CharRepTest)
	ATestCharReplication* CharRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_FStringRepTest)
	ATestFStringReplication* FStringRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_CArrayRepTest)
	ATestCArrayReplication* CArrayRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_TArrayUObjectsRepTest)
	ATestTArrayReplication* TArrayUObjectsRepTest;

	UPROPERTY(ReplicatedUsing = OnRep_EnumRepTest)
	ATestEnumReplication* EnumRepTest;

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

	UFUNCTION()
	void OnRep_IntRepTest();

	UFUNCTION()
	void OnRep_FloatRepTest();

	UFUNCTION()
	void OnRep_BoolRepTest();

	UFUNCTION()
	void OnRep_CharRepTest();

	UFUNCTION()
	void OnRep_FStringRepTest();

	UFUNCTION()
	void OnRep_CArrayRepTest();

	UFUNCTION()
	void OnRep_TArrayUObjectsRepTest();

	UFUNCTION()
	void OnRep_EnumRepTest();

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

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

	bool IntRepTestCreated;
	bool FloatRepTestCreated;
	bool BoolRepTestCreated;
	bool CharRepTestCreated;
	bool FStringRepTestCreated;
	bool CArrayRepTestCreated;
	bool TArrayUObjectsRepTestCreated;
	bool EnumRepTestCreated;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

#pragma optimize("", on)
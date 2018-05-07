// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "TestCube.h"
#include "SampleGameCharacter.generated.h"

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

	virtual void BeginPlay() override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

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

public:
	// Returns a position from which to start a line trace.
	// Use this so your line trace doesn't collide with the player character.
	FVector GetLineTraceStart();

	// Returns the direction in which to perform a line trace so it lines up with the center of the crosshair.
	FVector GetLineTraceDirection();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    void Interact();
	void SpawnCubePressed();
	void SpawnStarterWeapon();

	// [client] Triggers the equipped weapon to start firing.
	void StartFire();

	// [client] Triggers the equipped weapon to stop firing.
	void StopFire();

	// Returns the currently equipped weapon, or nullptr if there isn't one.
	class AWeapon* GetEquippedWeapon();

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerSpawnCube();

	// List of weapons the player currently has.
	//UPROPERTY(Replicated)
	//TArray<class AWeapon*> WeaponInventory;

	UPROPERTY(VisibleAnywhere, Replicated)
	class AWeapon* EquippedWeapon = nullptr;

	// Index of the currently equipped weapon.
	UPROPERTY(Replicated)
	int EquippedWeaponIndex = -1;

	UPROPERTY(EditAnywhere, Category = "Test")
	TSubclassOf<AWeapon> StarterWeapon;

	UPROPERTY(EditAnywhere, Category = "Test")
	TSubclassOf<ATestCube> TestActorTemplate;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};


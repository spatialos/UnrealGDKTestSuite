// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "PickUpAndRotateActor.h"
#include "SampleGameCharacter.generated.h"

UCLASS(config = Game)
class ASampleGameCharacter : public ACharacter
{
    GENERATED_BODY()

    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
              meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
              meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;

    /** Holding Component for items */
    UPROPERTY(EditAnywhere)
    class USceneComponent* HoldingComponent;

  public:
    ASampleGameCharacter();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseTurnRate;

    /** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseLookUpRate;

    // blueprint cube to spawn
    UPROPERTY(EditAnywhere)
    TSubclassOf<class AMyCube> CubeToSpawn;

    // pickup objects
    UPROPERTY(EditAnywhere, Replicated)
    class APickupAndRotateActor* CurrentItem;

    UFUNCTION()
    void RaycastSearchForItem();

	UFUNCTION(Server, Reliable, WithValidation)
    void SetCurrentItem(class APickupAndRotateActor* currItem);

    UPROPERTY(Replicated)
    bool bHoldingItem;  // server needs to know this

	// local camera variables
	bool bCanMove;
    bool bInspecting;
    float PitchMax;
    float PitchMin;

    FVector HoldingComp;
    FRotator LastRotation;

    virtual void OnRep_Controller() override;

    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const
    {
        return CameraBoom;
    }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const
    {
        return FollowCamera;
    }

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

    /** spawns a cube on input mapping */
    UFUNCTION(Server, Reliable, WithValidation)
    void SpawnCube();

    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    // End of APawn interface

	// interact and inspecting objects
    void Interact();
    void OnInspect();
    void OnInspectStopped();
    void ToggleMovement();

	UFUNCTION(Server, Reliable, WithValidation)
    void ToggleItemPickup();  // called on server within Interact() to correctly process item pickups

    UFUNCTION(Server, Reliable, WithValidation)
    void TestRPC();

    UFUNCTION(NetMulticast, Unreliable, WithValidation)
    void TestMulticast();
};

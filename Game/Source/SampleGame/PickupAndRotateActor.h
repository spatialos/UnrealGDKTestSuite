// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "PickupAndRotateActor.generated.h"

UCLASS()
class SAMPLEGAME_API APickupAndRotateActor : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    APickupAndRotateActor();

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* MyMesh;

	// make virtual getter function so derived classes can overwrite the mesh
	virtual UStaticMeshComponent* GetMesh();

    UPROPERTY(EditAnywhere, Replicated)
    USceneComponent* HoldingComp;

    UFUNCTION()
    void RotateActor();  // still unsure what this function does

	UPROPERTY(Replicated, EditAnywhere)
    bool bHolding;

    UPROPERTY(Replicated, EditAnywhere)
    ACharacter* MyCharacter;
    UPROPERTY(Replicated, EditAnywhere)
    UCameraComponent* PlayerCamera;

	UFUNCTION(Server, Reliable, WithValidation)
    void Pickup();

	UFUNCTION(Server, Reliable, WithValidation)
	void LinkToPlayer(ACharacter* myChar);

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestCube.generated.h"

UCLASS()
class SAMPLEGAME_API ATestCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void Interact(class ACharacter* Interactor);

protected:
    UFUNCTION(Server, Reliable, WithValidation)
    void ServerInteract();

    void ToggleColor();

	UFUNCTION()
	void OnRep_Color1();

    UPROPERTY(ReplicatedUsing = OnRep_Color1)
    bool bColor1 = false;

    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* MeshComponent = nullptr;

    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* BoxComponent = nullptr;

	class UMaterialInstanceDynamic* MaterialInstanceDynamic = nullptr;

	UPROPERTY(EditAnywhere)
	FLinearColor Color1 = FLinearColor::Blue;

	UPROPERTY(EditAnywhere)
	FLinearColor Color2 = FLinearColor::Yellow;
	
};

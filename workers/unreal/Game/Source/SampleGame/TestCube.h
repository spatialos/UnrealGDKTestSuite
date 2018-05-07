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
	ATestCube();

	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

    void Interact(class ACharacter* Interactor);

protected:
	virtual void BeginPlay() override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerInteract();

    void ToggleColor();

	UFUNCTION()
	void OnRep_Color1();

    UPROPERTY(ReplicatedUsing = OnRep_Color1)
    bool bColor1 = true;

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

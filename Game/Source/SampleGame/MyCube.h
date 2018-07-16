// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupAndRotateActor.h"
#include "MyCube.generated.h"

UCLASS()
class SAMPLEGAME_API AMyCube : public APickupAndRotateActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCube();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
    float transparency;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* CubeMesh;

	virtual UStaticMeshComponent* GetMesh() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

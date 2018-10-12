// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorProxyTestActor.generated.h"

UCLASS(SpatialType)
class TESTSUITE_API AActorProxyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorProxyTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
};

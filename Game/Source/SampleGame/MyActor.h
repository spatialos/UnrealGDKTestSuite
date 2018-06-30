// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SAMPLEGAME_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
    void Foo(int x);
    bool Foo_Validate(int x);
    void Foo_Implementation(int x);
	
	UFUNCTION(Client, Reliable, WithValidation)
    void Bar(double y);
    bool Bar_Validate(double y);
    void Bar_Implementation(double y);
};

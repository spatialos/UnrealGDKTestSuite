// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestIntReplication.generated.h"

UCLASS()
class SAMPLEGAME_API ATestIntReplication : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestIntReplication();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_TestIntFunc();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt);

	UFUNCTION()
	void OnRep_TestBookend();

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY(Replicated)
	int8 Test8Int;

	UPROPERTY(Replicated)
	int16 Test16Int;

	UPROPERTY(Replicated)
	int32 Test32Int;

	UPROPERTY(Replicated)
	int64 Test64Int;

	UPROPERTY(Replicated)
	uint8 Test8UInt;

	UPROPERTY(Replicated)
	uint16 Test16UInt;

	UPROPERTY(Replicated)
	uint32 Test32UInt;

	UPROPERTY(Replicated)
	uint64 Test64UInt;

	int RPCResponseType;
};

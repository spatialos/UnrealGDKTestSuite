// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "GDKTestRunner.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialGDKTests, Log, All);

UCLASS()
class SAMPLEGAME_API AGDKTestRunner : public AActor
{
	GENERATED_BODY()

public:

	AGDKTestRunner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_RunTests();

	UFUNCTION()
	bool IsRunning() const;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SignalClientReady();

	UFUNCTION()
	void SetupTestCases();

	UFUNCTION()
	void TearDownTestCases();

	UFUNCTION()
	void OnRep_TestCases();

	UPROPERTY(ReplicatedUsing = OnRep_TestCases)
	TArray<AGDKTestCase*> TestCases;

	UPROPERTY(Replicated)
	bool bIsRunning;

	UPROPERTY()
	int CurrentTestIndex;

	UPROPERTY()
	int ReadyClientsCount;
};

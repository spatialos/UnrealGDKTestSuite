// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDKTestCase.generated.h"

/*
* GDKTestCase is the interface for any test executed by the GDKTestRunner.
* It contains the two server RPCs for starting the test and tearing it down once it
* has finished its execution.
*/
UCLASS(Abstract)
class SAMPLEGAME_API AGDKTestCase : public AActor
{
	GENERATED_BODY()

public:

	AGDKTestCase();

	/* 
	* Indicates if the test has finished its execution. 
	*/
	UFUNCTION()
	bool IsFinished() const;

	/* 
	* This function is triggered by the GDK test runner to start the execution of the test.
	*/
	UFUNCTION()
	virtual void Server_StartTest()
	PURE_VIRTUAL(AGDKTestCase::Server_StartTest(), );

	/* 
	* This function is triggered by the GDK test runner to start the tear down process of the test after its completion. 
	*/
	UFUNCTION()
	virtual void Server_TearDown()
	PURE_VIRTUAL(AGDKTestCase::Server_TearDown(), );

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	UPROPERTY()
	FString TestName;

	UPROPERTY()
	bool bIsFinished;
};

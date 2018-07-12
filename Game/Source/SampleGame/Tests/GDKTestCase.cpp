// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GDKTestCase.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AGDKTestCase::AGDKTestCase()
	: bIsFinished(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

bool AGDKTestCase::IsFinished() const
{
	return bIsFinished;
}

FString AGDKTestCase::GetResultSummary() const
{
	return ResultString;
}

void AGDKTestCase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

}

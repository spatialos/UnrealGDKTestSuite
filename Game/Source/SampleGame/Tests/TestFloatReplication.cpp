// Fill out your copyright notice in the Description page of Project Settings.

#include "TestFloatReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFloatReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFloatReplication, TestFloat, COND_None);
	DOREPLIFETIME_CONDITION(ATestFloatReplication, TestDouble, COND_None);
}

bool ATestFloatReplication::Server_ReportReplication_Validate(float RepFloat, double RepDouble)
{
	return true;
}

void ATestFloatReplication::Server_ReportReplication_Implementation(float RepFloat, double RepDouble)
{
	check(FMath::IsNearlyEqual(RepFloat, 25.0f));
	check(FMath::IsNearlyEqual(RepDouble, 50.0));

	SignalResponseRecieved();
}


void ATestFloatReplication::StartTestImpl()
{
	TestFloat = 25.0f;
	TestDouble = 50.0;

	SignalReplicationSetup();
}

void ATestFloatReplication::ValidateClientReplicationImpl()
{
	check(FMath::IsNearlyEqual(TestFloat, 25.0f));
	check(FMath::IsNearlyEqual(TestDouble, 50.0));
}

void ATestFloatReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFloat, TestDouble);
}

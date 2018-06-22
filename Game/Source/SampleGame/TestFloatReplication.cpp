// Fill out your copyright notice in the Description page of Project Settings.

#include "TestFloatReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

bool ATestFloatReplication::Server_TestFloatFunc_Validate()
{
	return true;
}

void ATestFloatReplication::Server_TestFloatFunc_Implementation()
{
	TestFloat = TNumericLimits<float>::Max();
	TestDouble = TNumericLimits<double>::Max();

	SignalReplicationSetup();
}

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
	check(RepFloat == TNumericLimits<float>::Max());
	check(RepDouble == TNumericLimits<double>::Max());

	SignalResponseRecieved();
}

void ATestFloatReplication::ValidateClientReplicationImpl()
{
	check(TestFloat == TNumericLimits<float>::Max());
	check(TestDouble == TNumericLimits<double>::Max());
}

void ATestFloatReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFloat, TestDouble);
}

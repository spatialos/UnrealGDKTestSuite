// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCArrayReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestCArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, TestPOD, COND_None);
}

bool ATestCArrayReplication::Server_ReportReplication_Validate()
{
	return true;
}

void ATestCArrayReplication::Server_ReportReplication_Implementation()
{
	SignalResponseRecieved();
}

void ATestCArrayReplication::StartTestImpl()
{
	TestPOD[0] = FirstComparisonValue;
	TestPOD[1] = SecondComparisonValue;
 
	SignalReplicationSetup();
}

void ATestCArrayReplication::ValidateClientReplicationImpl()
{
	check(TestPOD[0] == FirstComparisonValue);
	check(TestPOD[1] == SecondComparisonValue);
}

void ATestCArrayReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}

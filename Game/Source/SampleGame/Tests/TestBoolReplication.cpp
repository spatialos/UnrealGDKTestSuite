// Fill out your copyright notice in the Description page of Project Settings.

#include "TestBoolReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

bool ATestBoolReplication::Server_TestBoolFunc_Validate()
{
	return true;
}

void ATestBoolReplication::Server_TestBoolFunc_Implementation()
{
	TestBool = true;

	SignalReplicationSetup();
}

void ATestBoolReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestBoolReplication, TestBool, COND_None);
}

bool ATestBoolReplication::Server_ReportReplication_Validate(bool RepBool)
{
	return true;
}

void ATestBoolReplication::Server_ReportReplication_Implementation(bool RepBool)
{
	check(RepBool == true);

	SignalResponseRecieved();
}

void ATestBoolReplication::ValidateClientReplicationImpl()
{
	check(TestBool == true);
}

void ATestBoolReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestBool);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TestFStringReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFStringReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFStringReplication, TestFString, COND_None);
}

bool ATestFStringReplication::Server_ReportReplication_Validate(const FString& RepFString)
{
	return true;
}

void ATestFStringReplication::Server_ReportReplication_Implementation(const FString& RepFString)
{
	check(RepFString == TEXT("Here's Johnny!"));

	SignalResponseRecieved();
}

void ATestFStringReplication::StartTestImpl()
{
	TestFString = TEXT("Here's Johnny!");

	SignalReplicationSetup();
}

void ATestFStringReplication::ValidateClientReplicationImpl()
{
	check(TestFString == TEXT("Here's Johnny!"));
}

void ATestFStringReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFString);
}

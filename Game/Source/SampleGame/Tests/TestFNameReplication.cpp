// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestFNameReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFNameReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFNameReplication, TestFName, COND_None);
}

bool ATestFNameReplication::Server_ReportReplication_Validate(const FName& RepFName)
{
	return true;
}

void ATestFNameReplication::Server_ReportReplication_Implementation(const FName& RepFName)
{
	// TODO: Add fname setup

	SignalResponseRecieved();
}

void ATestFNameReplication::StartTestImpl()
{
	//TestFName = true;

	SignalReplicationSetup();
}

void ATestFNameReplication::ValidateClientReplicationImpl()
{
	//check(TestFName == true);
}

void ATestFNameReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFName);
}

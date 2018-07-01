// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

bool ATestCharReplication::Server_TestCharFunc_Validate()
{
	return true;
}

void ATestCharReplication::Server_TestCharFunc_Implementation()
{
	SignalReplicationSetup();
}

void ATestCharReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

bool ATestCharReplication::Server_ReportReplication_Validate()
{
	return true;
}

void ATestCharReplication::Server_ReportReplication_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("TestCase %s: Not Supported by Unreal"), *TestName);

	SignalResponseRecieved();
}

void ATestCharReplication::ValidateClientReplicationImpl()
{
}

void ATestCharReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}

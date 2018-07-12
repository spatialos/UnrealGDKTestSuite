// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ReplicationTestCase.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AReplicationTestCase::AReplicationTestCase()
	: bRunning(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called every frame
void AReplicationTestCase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRunning)
	{
		if (UWorld* World = GetWorld())
		{
			if (AGameModeBase* GameMode = World->GetAuthGameMode())
			{
				if (RPCResponsecCount == GameMode->GetNumPlayers())
				{
					UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase: %s: Test complete!"), *TestName);
					bIsFinished = true;
					bRunning = false;
				}
			}
		}
	}
}

void AReplicationTestCase::StartTest()
{
	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase %s: Test started!"), *TestName);

	bIsFinished = false;
	bRunning = true;
	RPCResponsecCount = 0;

	StartTestImpl();
}

void AReplicationTestCase::TearDown()
{
	TearDownImpl();
}

bool AReplicationTestCase::Server_StartTest_Validate()
{
	return true;
}

void AReplicationTestCase::Server_StartTest_Implementation()
{
	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase %s: Test started!"), *TestName);

	bRunning = true;
	RPCResponsecCount = 0;

	StartTestImpl();
}

void AReplicationTestCase::OnRep_TestBookend()
{
	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase %s: Validating replication"), *TestName);

	ValidateClientReplicationImpl();

	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase %s: Replication successful on client, sending response RPC"), *TestName);

	SendTestResponseRPCImpl();
}

void AReplicationTestCase::SignalReplicationSetup()
{
	TestBookend += 1;

	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase: %s : Replication setup on Server"), *TestName);
}

void AReplicationTestCase::SignalResponseRecieved()
{
	RPCResponsecCount++;
	UE_LOG(LogSpatialGDKTests, Warning, TEXT("TestCase %s: Response RPC recieved from a client"), *TestName);
}

void AReplicationTestCase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AReplicationTestCase, TestBookend, COND_None);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "ReplicationTestCase.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AReplicationTestCase::AReplicationTestCase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called every frame
void AReplicationTestCase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (UWorld* World = GetWorld())
	{
		if (AGameModeBase* GameMode = World->GetAuthGameMode())
		{
			if (RPCResponsecCount == GameMode->GetNumPlayers())
			{
				UE_LOG(LogTemp, Warning, TEXT("TestCase: %s: Test complete!"), *TestName);
			}
		}
	}
}

void AReplicationTestCase::OnRep_TestBookend()
{
	UE_LOG(LogTemp, Warning, TEXT("TestCase %s: Validating replication"), *TestName);

	ValidateClientReplicationImpl();

	UE_LOG(LogTemp, Warning, TEXT("TestCase %s: Replication successful on client, sending response RPC"), *TestName);

	SendTestResponseRPCImpl();
}

void AReplicationTestCase::SignalReplicationSetup()
{
	TestBookend += 1;

	UE_LOG(LogTemp, Warning, TEXT("TestCase: %s : Replication setup on Server"), *TestName);
}

void AReplicationTestCase::SignalResponseRecieved()
{
	RPCResponsecCount++;
	UE_LOG(LogTemp, Warning, TEXT("TestCase %s: Response RPC recieved from a client"), *TestName);
}

void AReplicationTestCase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AReplicationTestCase, TestBookend, COND_None);
}

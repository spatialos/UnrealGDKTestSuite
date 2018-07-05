// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCArrayReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestCArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, TestPOD, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, FooStructArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, SkeletalMeshes, COND_None);
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

	// Test C array nested structs
	int32 Count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				FooStructArray[i].BarStructArray[j].FloatArray[k] = Count++;
			}
			FooStructArray[i].BarStructArray[j].IntOne = 27;
			FooStructArray[i].BarStructArray[j].IntTwo = 88;
		}
		FooStructArray[i].IntOne = 69;
		FooStructArray[i].IntTwo = 1337;
	}
 
	SignalReplicationSetup();
}

void ATestCArrayReplication::ValidateClientReplicationImpl()
{
	check(TestPOD[0] == FirstComparisonValue);
	check(TestPOD[1] == SecondComparisonValue);

	// Static array testing.
	int32 Count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				check(FooStructArray[i].BarStructArray[j].FloatArray[k] == Count++);
			}
		}
	}
	// Static array testing end.
}

void ATestCArrayReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}

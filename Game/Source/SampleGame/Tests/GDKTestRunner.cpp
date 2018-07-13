// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GDKTestRunner.h"

#include "UnrealNetwork.h"
#include "GameFramework/GameModeBase.h"

#include "Tests/TestIntReplication.h"
#include "Tests/TestFloatReplication.h"
#include "Tests/TestBoolReplication.h"
#include "Tests/TestCharReplication.h"
#include "Tests/TestFStringReplication.h"
#include "Tests/TestCArrayReplication.h"
#include "Tests/TestTArrayReplication.h"
#include "Tests/TestEnumReplication.h"
#include "Tests/TestFTextReplication.h"
#include "Tests/TestFNameReplication.h"
#include "Tests/TestUStructReplication.h"
#include "Tests/TestUObjectReplication.h"

DEFINE_LOG_CATEGORY(LogSpatialGDKTests);

AGDKTestRunner::AGDKTestRunner()
	: bIsRunning(false)
	, CurrentTestIndex(0)
	, ReadyClientsCount(0)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called every frame
void AGDKTestRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsRunning)
	{
		UWorld* World = GetWorld();
		AGameModeBase* GameMode = World->GetAuthGameMode();
		if (!World || !GameMode || !(ReadyClientsCount == GameMode->GetNumPlayers()))
		{
			return;
		}

		// execute the tests
		if (TestCases[CurrentTestIndex]->IsFinished())
		{
			CurrentTestIndex++;

			if (CurrentTestIndex == TestCases.Num())
			{
				bIsRunning = false;
				ReadyClientsCount = 0;
				CurrentTestIndex = 0;
				Server_TearDownTestCases();
				UE_LOG(LogSpatialGDKTests, Log, TEXT("TestRunner: All Test completed successfully!"));
			}
			else
			{
				TestCases[CurrentTestIndex]->Server_StartTest();
			}
		}
	}
}

bool AGDKTestRunner::Server_RunTests_Validate()
{
	return true;
}

void AGDKTestRunner::Server_RunTests_Implementation()
{
	if (!bIsRunning)
	{
		ReadyClientsCount = 0;
		bIsRunning = true;

		Server_SetupTestCases();
	}
	else
	{
		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestRunner: Could not start the test runner, it is already running."));
	}

}

bool AGDKTestRunner::IsRunning() const
{
	return bIsRunning;
}

void AGDKTestRunner::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AGDKTestRunner, TestCases, COND_None);
	DOREPLIFETIME_CONDITION(AGDKTestRunner, bIsRunning, COND_None);
}

bool AGDKTestRunner::Server_SignalClientReady_Validate()
{
	return true;
}

void AGDKTestRunner::Server_SignalClientReady_Implementation()
{
	ReadyClientsCount++;

	if (UWorld* World = GetWorld())
	{
		if (AGameModeBase* GameMode = World->GetAuthGameMode())
		{
			if (ReadyClientsCount == GameMode->GetNumPlayers())
			{
				// Start the new test case as we are ready
				CurrentTestIndex = 0;
				TestCases[CurrentTestIndex]->Server_StartTest();
			}
		}
	}
}

void AGDKTestRunner::Server_SetupTestCases()
{
	// Setup the testcases here.
	UWorld* World = GetWorld();
	if (World && GetNetMode() == NM_DedicatedServer)
	{
		ATestIntReplication* IntTest = World->SpawnActor<ATestIntReplication>();
		check(IntTest);
		TestCases.Add(IntTest);

		ATestFloatReplication* FloatTest = World->SpawnActor<ATestFloatReplication>();
		check(FloatTest);
		TestCases.Add(FloatTest);

		ATestBoolReplication* BoolTest = World->SpawnActor<ATestBoolReplication>();
		check(BoolTest);
		TestCases.Add(BoolTest);
		
		ATestCharReplication* CharTest = World->SpawnActor<ATestCharReplication>();
		check(CharTest);
		TestCases.Add(CharTest);

		ATestFStringReplication* FStringTest = World->SpawnActor<ATestFStringReplication>();
		check(FStringTest);
		TestCases.Add(FStringTest);

		ATestCArrayReplication* CArrayTest = World->SpawnActor<ATestCArrayReplication>();
		check(CArrayTest);
		TestCases.Add(CArrayTest);
		
		ATestTArrayReplication* TArrayTest = World->SpawnActor<ATestTArrayReplication>();
		check(TArrayTest);
		TestCases.Add(TArrayTest);

		ATestEnumReplication* EnumTest = World->SpawnActor<ATestEnumReplication>();
		check(EnumTest);
		TestCases.Add(EnumTest);

		ATestFTextReplication* FTextTest = World->SpawnActor<ATestFTextReplication>();
		check(FTextTest);
		TestCases.Add(FTextTest);

		ATestFNameReplication* FNameTest = World->SpawnActor<ATestFNameReplication>();
		check(FNameTest);
		TestCases.Add(FNameTest);

		ATestUObjectReplication* UObjectTest = World->SpawnActor<ATestUObjectReplication>();
		check(UObjectTest);
		TestCases.Add(UObjectTest);

		ATestUStructReplication* UStructTest = World->SpawnActor<ATestUStructReplication>();
		check(UStructTest);
		TestCases.Add(UStructTest);
	}
}

void AGDKTestRunner::Server_TearDownTestCases()
{
	for (AGDKTestCase* TestCase : TestCases)
	{
		TestCase->Server_TearDown();
	}

	TestCases.Empty();
}

void AGDKTestRunner::OnRep_TestCases()
{
	if (TestCases.Num() > 0)
	{
		Server_SignalClientReady();
	}
}

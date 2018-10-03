// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestUObjectContexts.h"

#include "GameFramework/GameModeBase.h"
#include "SpatialNetDriver.h"
#include "SpatialNetConnection.h"
#include "SpatialPackageMapClient.h"
#include "Tests/GDKTestRunner.h"
#include "UnrealNetwork.h"

#include "UnrealObjectRef.h"

#include "ReplicationTestHelperClasses.h"

ATestUObjectContexts::ATestUObjectContexts()
	: bRunning(false)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	TestName = TEXT("UObject contexts");
}

void ATestUObjectContexts::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetNetMode() == NM_Client)
	{
		if (bBasicUObjectReceived && bActorPointerReceived && bStablyNamedUObjectReceived)
		{
			bBasicUObjectReceived = false;
			bActorPointerReceived = false;
			bStablyNamedUObjectReceived = false;

			Validate_Client();

			Server_ReportResult();
		}

		return;
	}

	if (bRunning)
	{
		UWorld* World = GetWorld();
		if (!World)
		{
			return;
		}

		AGameModeBase* GameMode = World->GetAuthGameMode();
		if (!GameMode || !(RPCResponseCount == GameMode->GetNumPlayers()))
		{
			return;
		}

		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase: %s: Test complete!"), *TestName);
		bIsFinished = true;
		bRunning = false;
	}
}

void ATestUObjectContexts::Server_StartTest()
{
	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Test started!"), *TestName);

	bIsFinished = false;
	bRunning = true;
	RPCResponseCount = 0;

	// Test basic uobject pointers
	BasicUObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/TestSuite.Default__TestUObject"));
	check(BasicUObject_Context == SpatialConstants::NULL_OBJECT_REF);

	// Test actor pointers
	ActorPointer = GetWorld()->SpawnActor<ATestActor>();
	ActorPointer->ActorName = ActorPointer->GetName();
	check(ActorPointer_Context == SpatialConstants::NULL_OBJECT_REF);

	// Test Stably named object assignment
	StablyNamedUObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/TestSuite.Default__TestUObject"));
	check(StablyNamedUObject_Context == SpatialConstants::NULL_OBJECT_REF);
}

void ATestUObjectContexts::Server_TearDown()
{
	if (!ActorPointer->Destroy(true))
	{
		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Unable to tear down dynamically created actor"), *TestName);
	}

	StablyNamedUObject = nullptr;
}

bool ATestUObjectContexts::Server_ReportResult_Validate()
{
	return true;
}

void ATestUObjectContexts::Server_ReportResult_Implementation()
{
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetNetDriver());
	USpatialPackageMapClient* PackageMap = Cast<USpatialPackageMapClient>(NetDriver->GetSpatialOSNetConnection()->PackageMap);

	// Test basic uobject context assignment
	FNetworkGUID BasicUobjectNetGUID = PackageMap->GetNetGUIDFromObject(BasicUObject);
	FUnrealObjectRef BasicUobjectObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(BasicUobjectNetGUID);

	check(BasicUObject_Context == BasicUobjectObjectRef);

	// Test actor pointer context assignment
	FNetworkGUID ActorPointerNetGUID = PackageMap->GetNetGUIDFromObject(ActorPointer);
	FUnrealObjectRef ActorPointerObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(ActorPointerNetGUID);

	check(ActorPointer_Context == ActorPointerObjectRef);

	// Test Stably named object context assignment
	FNetworkGUID StablyNamedUObjectNetGUID = PackageMap->GetNetGUIDFromObject(StablyNamedUObject);
	FUnrealObjectRef StablyNamedUObjectObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(StablyNamedUObjectNetGUID);

	check(StablyNamedUObject_Context == StablyNamedUObjectObjectRef);

	RPCResponseCount++;
}

void ATestUObjectContexts::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, BasicUObject, COND_None);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, ActorPointer, COND_None);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, StablyNamedUObject, COND_None);
}

void ATestUObjectContexts::Validate_Client()
{
	// Assert that the basic uobject context is assigned correctly
	check(BasicUObject_Context != SpatialConstants::NULL_OBJECT_REF);
	check(BasicUObject_Context.Path.IsSet());
	check(BasicUObject_Context.Path.GetValue() == TEXT("Default__TestUObject"));
	check(BasicUObject_Context.Outer.GetValue().Path.GetValue() == TEXT("/Script/TestSuite"));

	// Assert that the actor pointer context is assigned correctly
	check(ActorPointer_Context != SpatialConstants::NULL_OBJECT_REF);
	check(!ActorPointer_Context.Path.IsSet());
	check(!ActorPointer_Context.Path.IsSet());
	check(!ActorPointer_Context.Outer.IsSet());

	// Assert that the stably named object context is assigned correctly
	check(StablyNamedUObject_Context != SpatialConstants::NULL_OBJECT_REF);
	check(StablyNamedUObject_Context.Path.IsSet());
	check(StablyNamedUObject_Context.Path.GetValue() == TEXT("Default__TestUObject"));
	check(StablyNamedUObject_Context.Outer.GetValue().Path.GetValue() == TEXT("/Script/TestSuite"));
}

void ATestUObjectContexts::OnRep_BasicUObject()
{
	bBasicUObjectReceived = true;
}

void ATestUObjectContexts::OnRep_ActorPointer()
{
	bActorPointerReceived = true;
}

void ATestUObjectContexts::OnRep_StablyNamedUObject()
{
	bStablyNamedUObjectReceived = true;
}

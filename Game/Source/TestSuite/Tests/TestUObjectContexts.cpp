// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestUObjectContexts.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

#include "improbable/unreal/gdk/core_types.h"

#include "SpatialNetDriver.h"
#include "SpatialNetConnection.h"
#include "SpatialPackageMapClient.h"

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

	if (bRunning)
	{
		UWorld* World = GetWorld();
		if (!World)
		{
			return;
		}

		AGameModeBase* GameMode = World->GetAuthGameMode();
		if (GetNetMode() != NM_DedicatedServer || !GameMode || !(RPCResponseCount == GameMode->GetNumPlayers()))
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

	StablyNamedUObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/TestSuite.Default__TestUObject"));
	check(StablyNamedUObject);

	//MulticastRPC();
}

void ATestUObjectContexts::Server_TearDown()
{
	// No tear down required for MultiCast RPC
}

void ATestUObjectContexts::MulticastRPC_Implementation()
{	
	// If we are the server then all we need to do is to validate that the call has been executed correctly. 
	if (GetNetMode() != NM_DedicatedServer)
	{
		Server_ReportResult();
	}
}

bool ATestUObjectContexts::Server_ReportResult_Validate()
{
	return true;
}

void ATestUObjectContexts::Server_ReportResult_Implementation()
{
	check(StablyNamedUObject_Context != nullptr);

	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetNetDriver());
	USpatialPackageMapClient* PackageMap = Cast<USpatialPackageMapClient>(NetDriver->GetSpatialOSNetConnection()->PackageMap);
	FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StablyNamedUObject);
	improbable::unreal::UnrealObjectRef ObjectRef = *(PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID));

	check(StablyNamedUObject_Context->entity() == ObjectRef.entity());

	//USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	//check(NetDriver);
	//worker::EntityId ServerEntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(StablyNamedUObject).ToSpatialEntityId();

	//// // Validate the stably named object
	//check(TestStablyNamedUObject->IsA(UTestUObject::StaticClass()));
	//check(TestStablyNamedUObject == UTestUObject::StaticClass()->GetDefaultObject());
	//check(TestStablyNamedUObject->GetPathName() == TEXT("/Script/TestSuite.Default__TestUObject"));

	RPCResponseCount++;
}

void ATestUObjectContexts::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, BasicUObject, COND_None);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, ActorPointer, COND_None);
	DOREPLIFETIME_CONDITION(ATestUObjectContexts, StablyNamedUObject, COND_None);
}

void ATestUObjectContexts::OnRep_StablyNamedUObject()
{
	//check(StablyNamedUObject_Context != nullptr);;
}

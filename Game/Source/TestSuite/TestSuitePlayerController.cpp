// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestSuitePlayerController.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"

#include <improbable/c_worker.h>

bool ATestSuitePlayerController::TestRPC_Validate()
{
	return true;
}

void ATestSuitePlayerController::TestRPC_Implementation()
{

}

bool ATestSuitePlayerController::TestMulticast_Validate()
{
	return true;
}

void ATestSuitePlayerController::TestMulticast_Implementation()
{
}

void ATestSuitePlayerController::InitPlayerState()
{
	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	UWorld* World = GetWorld();
	check(World);
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (NetDriver)
	{
		const Worker_EntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(this);
		UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %d"), EntityId);
		if (EntityId != 0)
		{
			// EntityId is not 0, which means that this PC has already been initialized.
			return;
		}
	}

	Super::InitPlayerState();
}

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"
#include "EntityId.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"

bool ASampleGamePlayerController::TestRPC_Validate()
{
	return true;
}

void ASampleGamePlayerController::TestRPC_Implementation()
{

}

bool ASampleGamePlayerController::TestMulticast_Validate()
{
	return true;
}

void ASampleGamePlayerController::TestMulticast_Implementation()
{
}

void ASampleGamePlayerController::InitPlayerState()
{
	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (World && NetDriver)
	{
		const FEntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(this);
		UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %d"), EntityId.ToSpatialEntityId());
		if (EntityId != 0)
		{
			// EntityId is not 0, which means that this PC has already been initialized.
			return;
		}
	}

	Super::InitPlayerState();
}

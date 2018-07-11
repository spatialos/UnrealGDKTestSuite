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
	FEntityId EntityId = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver())->GetEntityRegistry()->GetEntityIdFromActor(this);
	UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %d"), EntityId.ToSpatialEntityId());
	if (EntityId == 0)
	{
		// EntityId is 0, so this is the first time this PC has been init. Allow it to create a new PlayerState.
		Super::InitPlayerState();
	}
}

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"

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
	UE_LOG(LogTemp, Warning, TEXT("ASampleGamePlayerController::InitPlayerState"));
	if (GetNetMode() != NM_Client)
	{
		if (PlayerState != nullptr)
		{
			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("ASampleGamePlayerController::InitPlayerState - initial called"));
	Super::InitPlayerState();
}

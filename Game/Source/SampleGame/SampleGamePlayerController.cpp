// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"

#include "SampleGameCharacter.h"
#include "SampleGameLogging.h"
#include "UI/SampleGameUI.h"

#include "SpatialNetDriver.h"


ASampleGamePlayerController::ASampleGamePlayerController()
	: SampleGameUI(nullptr),
	PlayerRespawnDelay(5.0f),
	DeletePlayerDelay(15.0f),
	PlayerToDelete(nullptr)
{
	// Don't automatically switch the camera view when the pawn changes, to avoid weird camera jumps when a character dies.
	bAutoManageActiveCameraTarget = false;
}

void ASampleGamePlayerController::UpdateHealthUI(int32 NewHealth, int32 MaxHealth)
{
	if (SampleGameUI != nullptr)
	{
		SampleGameUI->UpdateHealth(NewHealth, MaxHealth);
	}
	else
	{
		UE_LOG(LogSampleGame, Log, TEXT("Couldn't find SampleGameUI for controller: %s"), *this->GetName());
	}
}

void ASampleGamePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (GetNetMode() == NM_Client)
	{
		SetPlayerUIVisible(InPawn != nullptr);

		ASampleGameCharacter* Character = Cast<ASampleGameCharacter>(InPawn);
		if (Character != nullptr)
		{
			UpdateHealthUI(Character->GetCurrentHealth(), Character->GetMaxHealth());

			// Make the new pawn's camera this controller's camera.
			SetViewTarget(InPawn);
		}
	}
}

void ASampleGamePlayerController::KillPlayer()
{
	check(GetNetMode() == NM_DedicatedServer);

	if (!HasAuthority())
	{
		return;
	}

	PlayerToDelete = GetPawn();
	UnPossess();

	// TODO: timers won't persist across worker boundary migrations, and neither will PlayerToDelete
	GetWorldTimerManager().SetTimer(DeletePlayerTimerHandle, this, &ASampleGamePlayerController::DeletePlayer, DeletePlayerDelay);
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ASampleGamePlayerController::RespawnPlayer, PlayerRespawnDelay);
}

void ASampleGamePlayerController::SetPlayerUIVisible(bool bIsVisible)
{
	check(GetNetMode() == NM_Client);

	if (bIsVisible)
	{
		if (SampleGameUI == nullptr)
		{
			check(UITemplate != nullptr);
			SampleGameUI = CreateWidget<USampleGameUI>(this, UITemplate);
			if (SampleGameUI == nullptr)
			{
				USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver());
				UE_LOG(LogSampleGame, Error, TEXT("Failed to create UI for controller %s on worker %s"),
					*this->GetName(),
					SpatialNetDriver != nullptr ? *SpatialNetDriver->GetSpatialOS()->GetWorkerId() : TEXT("Invalid SpatialNetDriver"));
				return;
			}
		}

		if (!SampleGameUI->IsVisible())
		{
			SampleGameUI->AddToViewport();
		}
	}
	else
	{
		if (SampleGameUI != nullptr && SampleGameUI->IsVisible())
		{
			SampleGameUI->RemoveFromViewport();
		}
	}
}

void ASampleGamePlayerController::RespawnPlayer()
{
	check(GetNetMode() == NM_DedicatedServer);
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	if (GameMode != nullptr && this != nullptr)
	{
		APawn* NewPawn = GameMode->SpawnDefaultPawnFor(this, StartSpot.Get());
		Possess(NewPawn);
	}
}

void ASampleGamePlayerController::DeletePlayer()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (PlayerToDelete != nullptr)
	{
		// TODO: what if the player is on a different worker?
		GetWorld()->DestroyActor(PlayerToDelete);
		PlayerToDelete = nullptr;
	}
}

// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SampleGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASampleGamePlayerController();

	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

	// Updates the health UI with a new value.
	void UpdateHealthUI(int32 NewHealth, int32 MaxHealth);

	// Overrides AController::SetPawn, which should be called on the client and server whenever the controller
	// possesses (or unpossesses) a pawn.
	virtual void SetPawn(APawn* InPawn) override;

	// [server] Kills the controller's player.
	void KillPlayer();

	// [client] Sets whether the player UI should be visible.
	void SetPlayerUIVisible(bool bIsVisible);

private:
	// [server] Causes the player to respawn.
	void RespawnPlayer();

	// [server] Deletes the player character.
	void DeletePlayer();

	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameUI> UITemplate;

	// The current game UI.
	UPROPERTY(Transient)
	class USampleGameUI* SampleGameUI;

	// Player respawn delay, in seconds.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float PlayerRespawnDelay;

	// Time for which to keep the player's body around before deleting it.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float DeletePlayerDelay;

	// Player to be deleted when the DeletePlayer timer expires.
	class APawn* PlayerToDelete;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle DeletePlayerTimerHandle;

};

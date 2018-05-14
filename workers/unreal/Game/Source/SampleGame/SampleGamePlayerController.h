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
	void UpdateHealthUI(float NewHealth, float MaxHealth);

protected:
	virtual void BeginPlay() override;

private:
	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameUI> UITemplate;

	class USampleGameUI* SampleGameUI = nullptr;

};

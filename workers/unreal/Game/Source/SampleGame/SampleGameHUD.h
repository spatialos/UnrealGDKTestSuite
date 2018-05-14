// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SampleGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere)
	float CrosshairWidth = 2.0f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairHeight = 2.0f;
	
protected:
	void DrawCrosshair();
	
};

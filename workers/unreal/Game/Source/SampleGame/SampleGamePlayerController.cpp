// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"

#include "UI/SampleGameUI.h"


void ASampleGamePlayerController::UpdateHealthUI(float NewHealth, float MaxHealth)
{
	if (SampleGameUI)
	{
		SampleGameUI->UpdateHealth(NewHealth, MaxHealth);
	}
}

void ASampleGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetNetMode() != NM_DedicatedServer && UITemplate != nullptr)
	{
		SampleGameUI = CreateWidget<USampleGameUI>(this, UITemplate);
		SampleGameUI->AddToViewport();
	}
}

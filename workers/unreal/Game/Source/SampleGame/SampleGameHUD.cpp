// Fill out your copyright notice in the Description page of Project Settings.

#include "SampleGameHUD.h"

#include "Engine/Canvas.h"


void ASampleGameHUD::DrawHUD()
{
	Super::DrawHUD();
	if (Canvas == nullptr)
	{
		return;
	}

	DrawCrosshair();
}

void ASampleGameHUD::DrawCrosshair()
{
	float centerX = Canvas->ClipX / 2.0f;
	float centerY = Canvas->ClipY / 2.0f;
	DrawRect(FLinearColor::White, centerX, centerY, CrosshairWidth, CrosshairHeight);
}

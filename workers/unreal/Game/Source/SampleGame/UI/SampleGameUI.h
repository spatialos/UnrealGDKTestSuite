// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SampleGameUI.generated.h"


UCLASS()
class SAMPLEGAME_API USampleGameUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Updates the UI's health value.
	void UpdateHealth(float NewHealth, float MaxHealth);

protected:
	// Blueprint event called whenever the current health value is updated.
	UFUNCTION(BlueprintImplementableEvent, Category = "SampleGameUI")
	void UpdateHealthBar();

	// Current UI health value, between 0 and 1.
	UPROPERTY(BlueprintReadOnly)
	float CurrentHealth = 0.0f;
	
};

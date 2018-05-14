// Fill out your copyright notice in the Description page of Project Settings.

#include "SampleGameUI.h"


void USampleGameUI::UpdateHealth(float NewHealth, float MaxHealth)
{
	CurrentHealth = NewHealth / MaxHealth;
	UpdateHealthBar();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAPAIDebugHud.h"
#include "GDWY3_Festival_Game/AI/GOAPAI.h"

void AGOAPAIDebugHud::DrawHUD()
{
	Super::DrawHUD();

	UGOAPAI* ai = Cast<UGOAPAI>(GetOwningPawn()->GetComponentByClass<UGOAPAI>());

	if (ai != nullptr)
	{
		
		// display debug info
	}
}

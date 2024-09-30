// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DebugHud.h"
#include "GOAPAIDebugHud.generated.h"

/**
 * 
 */
UCLASS()
class GDWY3_FESTIVAL_GAME_API AGOAPAIDebugHud : public ADebugHud
{
	GENERATED_BODY()

protected:

	// Draw the HUD.
	virtual void DrawHUD() override;
	
};

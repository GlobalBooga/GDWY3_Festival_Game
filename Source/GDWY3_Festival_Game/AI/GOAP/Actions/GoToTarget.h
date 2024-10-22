// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDWY3_Festival_Game/AI/GOAP/Action.h"
#include "GoToTarget.generated.h"

/**
 * 
 */
UCLASS()
class GDWY3_FESTIVAL_GAME_API UGoToTarget : public UAction
{
	GENERATED_BODY()

public:
	bool Perform();


protected:

private:
	FTransform targetTransform;
	
};

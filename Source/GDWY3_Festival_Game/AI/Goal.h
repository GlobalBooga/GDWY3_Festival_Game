// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"

/**
 * 
 */

class GDWY3_FESTIVAL_GAME_API Goal
{
public:
	Goal(const FName& name, const WorldState& desiredWorldState, bool desiredValue) : name(name), desiredWorldState(desiredWorldState)
	{
		this->desiredWorldState.value = desiredValue;
	}
	~Goal() {}

private:
	FName name;
	WorldState desiredWorldState;

public:
	WorldState* GetRequiredState() { return &desiredWorldState; }
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"
/**
 * 
 */

class WorldState;

class GDWY3_FESTIVAL_GAME_API Action
{
public:
	Action(const FName& name, WorldState requirement, bool requirementStateState, WorldState effectOfAction, bool effectStateState, int cost) : name(name), requiredWorldState(requirement), causesWorldState(effectOfAction), cost(cost)
	{
		requirement.value = requirementStateState;
		causesWorldState.value = effectStateState;
	}
	~Action() {}

private:
	FName name;

protected:
	WorldState causesWorldState;
	WorldState requiredWorldState;
	int cost;
	bool actionWorked;

public:
	bool PerformAction();
	bool WasActionSuccessful() const { return actionWorked; }
	int GetCost();
	FName GetName() const { return name; }
	const WorldState* GetResultWorldState() { return &causesWorldState; }
};

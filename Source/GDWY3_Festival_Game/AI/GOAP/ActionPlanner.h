// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Agent.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API ActionPlanner
{
public:
	ActionPlanner() {}
	~ActionPlanner();
	TArray<IAction*> plan;

	bool MakePlan(Agent* agent, WorldState* goal);
};

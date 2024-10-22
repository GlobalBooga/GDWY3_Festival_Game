// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Action.h"
#include "AStar/AStarGraph.h"

/**
 * 
 */
class Agent;
class GDWY3_FESTIVAL_GAME_API ActionPlanner
{
public:
	ActionPlanner() {}
	~ActionPlanner() {}
	TArray<IActionInterface*> plan;

	bool MakePlan(Agent* agent, WorldState* goal);

	int GetFCost(const NodeEdgePair& pair, const WorldState& target);
	int ComputeWorldStateHeuristic(const WorldState& current, const WorldState& target);
};

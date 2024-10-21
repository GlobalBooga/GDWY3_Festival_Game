// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AStarEdge.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API AStarGraph
{
public:
    AStarGraph();
    ~AStarGraph();
    void BuildForGoal(const std::pair<AStarNode, AStarEdge>& first, TArray<IAction*> allActions, WorldState startState);
    TArray<std::pair<AStarNode, AStarEdge>> graph;
    TArray<std::pair<AStarNode, AStarEdge>*> GetNodeEdgePairsThatPointTo(const AStarNode& node);
};

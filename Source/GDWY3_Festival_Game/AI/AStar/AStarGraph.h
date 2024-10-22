// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AStarEdge.h"

typedef TPair<AStarNode, AStarEdge> NodeEdgePair;

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API AStarGraph
{
public:
    AStarGraph();
    ~AStarGraph();
    void BuildForGoal(const NodeEdgePair& first, TArray<IActionInterface*> allActions, WorldState startState);
    TArray<NodeEdgePair> graph;
    TArray<NodeEdgePair*> GetNodeEdgePairsThatPointTo(const AStarNode& node);
};

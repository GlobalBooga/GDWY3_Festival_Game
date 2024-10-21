// Fill out your copyright notice in the Description page of Project Settings.


#include "AStarGraph.h"

AStarGraph::AStarGraph()
{
}

AStarGraph::~AStarGraph()
{
}

void AStarGraph::BuildForGoal(const std::pair<AStarNode, AStarEdge>& first, TArray<IAction*> allActions, WorldState startState)
{
}

TArray<std::pair<AStarNode, AStarEdge>*> AStarGraph::GetNodeEdgePairsThatPointTo(const AStarNode& node)
{
	return TArray<std::pair<AStarNode, AStarEdge>*>();
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDWY3_Festival_Game/AI/GOAP/WorldState.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API AStarNode
{
public:

public:
    AStarNode() : visited(false), state(WorldState()), fCost(0) {}
    AStarNode(WorldState rep) : visited(false), fCost(0), state(rep) {}
	~AStarNode();
    bool visited;
    int fCost;
    WorldState const& GetWorldState() const { return state; }

    // checks if the states match
    bool operator==(const AStarNode& other)
    {
        return this->state.name == other.state.name && this->state.IsEqualTo(other.state);
    }

private:
    WorldState state;

};

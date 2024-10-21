// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDWY3_Festival_Game/AI/GOAP/Action.h"
#include "AStarNode.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API AStarEdge
{
public:

public:
    AStarEdge() : origin(AStarNode()), destination(AStarNode()), action(nullptr) {}
    AStarEdge(class AStarNode origin, AStarNode destination, IAction* action) : origin(origin), destination(destination), action(action) {}
	~AStarEdge();
    AStarNode origin;
    AStarNode destination;

    bool IsValid() const { return action != nullptr; }
    bool IsRedundant(const WorldState& context);
    int GetCost() const { return action ? action->GetCost() : 0; }
    IAction* GetAction() const { return action; }

private:
    IAction* action;

};

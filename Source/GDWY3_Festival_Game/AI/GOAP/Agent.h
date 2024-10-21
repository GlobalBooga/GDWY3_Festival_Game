// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API Agent
{
public:
    Agent(FString name) : name(name) {}
	~Agent();
    FString name;
    WorldState currentWorldState;
    TArray<class IAction*> allActions;

    void AddAction(IAction* action) { allActions.Add(action); }

};

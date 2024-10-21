// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"

class GDWY3_FESTIVAL_GAME_API IAction
{
public:
    virtual bool Perform() = 0;
    virtual int GetCost() const = 0;
    virtual bool IsUsable(const WorldState& context) = 0;
    virtual FString GetName() const = 0;
    virtual const WorldState* GetPreRequisite() const = 0;
    virtual WorldState GetResult() const = 0;
    virtual bool SatisfiesStateVariable(WorldStateVariable const& variable) = 0;
};

class GDWY3_FESTIVAL_GAME_API Action: public IAction
{
public:
    Action(FString name, int cost, const WorldState& preReq, const WorldState& effect) : name(name), cost(cost), preReq(preReq), result(effect) {}

    // Interface Functions
    bool Perform();
    int GetCost() const { return cost; }
    bool IsUsable(const WorldState& context);
    FString GetName() const { return name; }
    virtual const WorldState* GetPreRequisite() const { return &preReq; }
    virtual WorldState GetResult() const { return result; }
    bool SatisfiesStateVariable(WorldStateVariable const& variable);

protected:
    // Base Variables
    int cost;
    FString name;
    WorldState preReq;
    WorldState result;
};

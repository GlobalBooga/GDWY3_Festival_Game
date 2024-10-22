// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldStateVariable.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API WorldState
{
public:
    WorldState() : name(FString()) {}
    WorldState(FString name) : name(name) {}
	~WorldState();
    FString name;
    TArray<WorldStateVariable> variables;

    void AddVar(EStateVars var, bool value);

    // do we have an exact match of this variable?
    bool Find(const WorldStateVariable& var) const
    {
        for (const WorldStateVariable& v : variables)
        {
            if (v.Equals(var)) return true;
        }
        return false;
    }

    // are all comparable variables the same
    bool IsEqualTo(const WorldState& other) const
    {
        for (const WorldStateVariable& v : other.variables)
        {
            if (!Find(v)) return false;
        }
        return true;
    }
};

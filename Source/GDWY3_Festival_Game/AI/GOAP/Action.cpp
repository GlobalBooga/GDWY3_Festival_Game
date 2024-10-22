// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

bool UAction::Perform()
{
	return false;
}

bool UAction::IsUsable(const WorldState& context)
{
    for (size_t i = 0; i < preReq.variables.Num(); i++)
    {
        for (size_t n = 0; n < context.variables.Num(); n++)
        {
            if (context.variables[n].type != preReq.variables[i].type) continue;
            if (context.variables[n].value != preReq.variables[i].value) return false;
        }
    }
    return true;
}

bool UAction::SatisfiesStateVariable(WorldStateVariable const& variable)
{
    for (size_t n = 0; n < result.variables.Num(); n++)
    {
        if (result.variables[n].Equals(variable)) return true;
    }
    return false;
}

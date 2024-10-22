// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStateVariable.h"
#include "StateVars.h"

WorldStateVariable::~WorldStateVariable()
{
}

FString WorldStateVariable::ToString() const
{
    FString valueStr = value ? "True" : "False";
    switch (type)
    {
    case EStateVars::None:
        return FString("None: " + valueStr);
    case EStateVars::NearTarget:
        return FString("IsNearEnemy: " + valueStr);
    default:
        return "Null";
    }
}

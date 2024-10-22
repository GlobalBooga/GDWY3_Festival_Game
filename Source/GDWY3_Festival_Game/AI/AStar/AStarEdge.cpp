// Fill out your copyright notice in the Description page of Project Settings.


#include "AStarEdge.h"

AStarEdge::~AStarEdge()
{
}

bool AStarEdge::IsRedundant(const WorldState& context)
{
    const WorldState& tryingToSatisfy = destination.GetWorldState();

    for (const WorldStateVariable& var : action->GetResult().variables)
    {
        // check if the variable we are changing is true within the given context
        if (!context.Find(var) && tryingToSatisfy.Find(var)) return false;
    }
    return true;
}

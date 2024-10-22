// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldState.h"

WorldState::~WorldState()
{
}

void WorldState::AddVar(EStateVars var, bool value)
{
	variables.Add(WorldStateVariable(var, value));
}

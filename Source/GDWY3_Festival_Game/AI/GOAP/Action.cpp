// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"

bool Action::Perform()
{
	return false;
}

bool Action::IsUsable(const WorldState& context)
{
	return false;
}

bool Action::SatisfiesStateVariable(WorldStateVariable const& variable)
{
	return false;
}

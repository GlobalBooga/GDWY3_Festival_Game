// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAPAI.h"
#include "GDWY3_Festival_Game/AI/Graph.h"

float UGOAPAI::GetTargetDistance(const AActor* target) const
{
	return FVector::Dist(target->GetActorLocation(), GetOwner()->GetTransform().GetLocation());
}

bool UGOAPAI::MakePlan(Goal goal)
{
	FName goalStateName = goal.GetRequiredState()->GetName();
	WorldState* state = GetState(goalStateName);
	
	if (!state) return false; // is valid
	if (state->GetName() != goalStateName) return false; // is it the same
	if (state->value == goal.GetRequiredState()->value) return false; // did it happen already

	// make plan for given goal
	TArray<Action*> closedList; // the path
	TArray<Action*> openList; 


	// get all actions that produce desired world state
	for (int i = 0; i < actions.Num(); i++)
	{
		if (actions[i].GetResultWorldState()->GetName() == goalStateName)
		{
			// calculate cost and heuristics?
			openList.Add(&actions[i]);
		}
	}

	// get all actions that produce required world state for selected actions
	for (int i = 0; i < actions.Num(); i++)
	{
		if (actions[i].GetResultWorldState()->GetName() == goalStateName) openList.Add(&actions[i]);
	}


	return true;
}

WorldState* UGOAPAI::GetState(const FName& stateName)
{
	for (WorldState& state : states)
	{
		if (state.GetName() == stateName)
		{
			return &state;
		}
	}
	return nullptr;
}

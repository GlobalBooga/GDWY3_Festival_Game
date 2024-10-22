// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlanner.h"
#include "GOAP/Agent.h"
#include "AStar/AStarGraph.h"

int ActionPlanner::ComputeWorldStateHeuristic(const WorldState& current, const WorldState& target)
{
    int h = 0;
    // how many vars in current are real?
    for (const WorldStateVariable& var : current.variables)
    {
        for (const WorldStateVariable& compVar : target.variables)
        {
            if (var.type != compVar.type) continue;
            if (var.value != compVar.value) h++;
        }
    }
    return h;
}

int ActionPlanner::GetFCost(const NodeEdgePair& pair, const WorldState& target)
{
    return ComputeWorldStateHeuristic(pair.Key.GetWorldState(), target) + pair.Value.GetCost();
}

bool ActionPlanner::MakePlan(Agent* agent, WorldState* goal)
{
    //typedef TPair<AStarNode, AStarEdge> NodeEdgePair;

    AStarGraph g;
    AStarNode goalNode{ *goal };
    NodeEdgePair start{ goalNode, AStarEdge() };
    g.BuildForGoal(start, agent->allActions, agent->currentWorldState);

    NodeEdgePair* current = &g.graph[0]; // start
    TArray<NodeEdgePair*> openList{ current }; // list of successors that we visited
    TArray<NodeEdgePair*> closedList; // list of explored nodes that we visited
    TArray<NodeEdgePair*> successors;
    int f = 0;

    while (openList.Num() > 0)
    {
        int pf = 1000000;
        for (NodeEdgePair* pair : openList)
        {
            pair->Key.visited = true;
            if (!pair->Value.IsValid()) continue;


            // get total cost for successor
            //f = GetFCost(*pair, agent->currentWorldState);

            // is it cheaper than the previous successor?
            if (pair->Key.fCost < pf)
            {
                pf = f;
                current = pair;
            }
        }

        // remove from open list
        for (size_t i = 0; i < openList.Num(); i++)
        {
            if (openList[i]->Key == current->Key)
            {
                openList.RemoveAt(i);
            }
        }

        closedList.Add(current);

        /*if (current->first == agent->currentWorldState)
        {
            cout << "Solution found!\n";
            break;
        }*/

        successors = g.GetNodeEdgePairsThatPointTo(current->Key);

        // if we have no successors, we reached the end of a branch.
        // if this isnt the solution backtrack and take another branch
        if (successors.Num() == 0)
        {
            successors = openList;
        }

        for (NodeEdgePair* pair : successors)
        {
            // skip if pair is already in closed list
            if (pair->Key.visited || pair->Value.IsRedundant(agent->currentWorldState)) continue;
            /*for (const NodeEdgePair* test : closedList)
            {
                if (&test->first == &pair->first) goto skip;
            }*/

            // set successor current cost 
            pair->Key.fCost = FMath::Abs(GetFCost(*pair, agent->currentWorldState) + current->Value.GetCost());

            //is in open list?
            /*for (const NodeEdgePair* test : openList)
            {
                if (&test->first == &pair->first && pair->second.GetCost() > test->second.GetCost())
                {
                    goto skip;
                }
            }*/

            openList.Add(pair);

            //skip:;
        }

    }

    // get actions from closedList
    for (NodeEdgePair* pair : closedList)
    {
        IActionInterface* action = pair->Value.GetAction();
        if (action) plan.Add(action);
    }

    return true;
}

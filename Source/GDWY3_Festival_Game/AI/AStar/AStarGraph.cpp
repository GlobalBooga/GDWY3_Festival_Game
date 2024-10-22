// Fill out your copyright notice in the Description page of Project Settings.


#include "AStarGraph.h"

AStarGraph::AStarGraph()
{
}

AStarGraph::~AStarGraph()
{
}

void AStarGraph::BuildForGoal(const NodeEdgePair& first, TArray<IActionInterface*> allActions, WorldState startState)
{
    // node + previous edge
    NodeEdgePair n = first;
    WorldState current = n.Key.GetWorldState();

    graph.Add(n);

    bool done;
    do
    {
        done = true;
        // for each action...
        for (IActionInterface* a : allActions)
        {
            // get action that satisfies our test node (n)
            for (const WorldStateVariable& var : current.variables)
            {
                if (!a->SatisfiesStateVariable(var)) continue;
                // this action satisfies this world state; follow this branch
                AStarNode node{ *a->GetPreRequisite() };
                AStarEdge edge{ node, n.Key, a };
                BuildForGoal(NodeEdgePair{ node, edge }, allActions, startState);
                done = false;
            }
        }
        n = graph.Last();
        current = n.Key.GetWorldState();
    } while (!done);
}

TArray<NodeEdgePair*> AStarGraph::GetNodeEdgePairsThatPointTo(const AStarNode& node)
{
    TArray<NodeEdgePair*> result;
    for (NodeEdgePair& n : graph)
    {
        if (n.Value.IsValid() && n.Value.destination == node) result.Add(&n);
    }

    return result;
}

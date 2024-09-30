// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API AStar
{
public:
	AStar();
	~AStar();

	struct Node {
		/* cost
		* previous node
		* previous edge
		* heuristic cost
		*/
	};

	struct Edge {
		/* Node origin
		* Node destination
		* bool isDestination
		* cost
		*/
	};


};

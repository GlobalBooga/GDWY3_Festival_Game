// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class NodeBase;

class GDWY3_FESTIVAL_GAME_API Graph
{
public:
	Graph();
	~Graph();
	
	void AddNode(NodeBase node);
	void RemoveNode(NodeBase node);

	TArray<NodeBase> nodes;
};

class GDWY3_FESTIVAL_GAME_API NodeBase
{
public:
	NodeBase() = delete;

private:
	NodeBase* previousNode;
};
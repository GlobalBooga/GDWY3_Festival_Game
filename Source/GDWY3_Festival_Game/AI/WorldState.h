// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API WorldState
{
public:
	WorldState() : name(FName("null")), value(false) {}
	WorldState(FName name, bool defaultValue = false) : name(name), value(defaultValue) {}
	~WorldState() {}

	bool value;

	FName GetName() const { return name; }
	
private:
	FName name;
};

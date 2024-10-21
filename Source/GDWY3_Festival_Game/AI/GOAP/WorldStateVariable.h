// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateVars.h"

/**
 * 
 */
class GDWY3_FESTIVAL_GAME_API WorldStateVariable
{
public:
    WorldStateVariable(EStateVars type, bool value) : type(type), value(value), solved(false) { }
	~WorldStateVariable();
    EStateVars type;
    bool value;
    bool solved;

    FString ToString() const;

    bool Equals(const WorldStateVariable& other) const { return other.type == type && other.value == value; }
};

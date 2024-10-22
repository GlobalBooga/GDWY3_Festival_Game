// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

enum class GDWY3_FESTIVAL_GAME_API EStateVars : uint8
{
    None UMETA(DisplayName = "NONE"),
    NearTarget UMETA(DisplayName = "IsNearTarget"),
    IsVulnerable,
    IsBreakMeterDepleted,
    IsActive,
    IsDPSThresholdSurpassed,
    IsEnemyInAttackRange,
    IsInEnemyAttackRange,
    IsPhaseSpecialCoolingDown,
    IsNormalAttackCoolingDown,
    IsHeavyAttackCoolingDown
};
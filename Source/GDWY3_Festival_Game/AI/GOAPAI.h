// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Action.h"
#include "Goal.h"
#include "GOAPAI.generated.h"

/**
 * 
 */


UCLASS()
class GDWY3_FESTIVAL_GAME_API UGOAPAI : public UActorComponent
{
	GENERATED_BODY()

public:
	enum EGoals
	{
		EG_None,
		EG_KillPlayer,
		EG_Powerup,
		EG_Converse,
		EG_Cooldown
	};

	enum EActions
	{
		EA_None,
		EA_Attack,
		EA_Retreat,
		EA_GotoTarget,
		EA_Pause,
		EA_Compliment,
		EA_Taunt
	};

private:

	// world states
	WorldState null{ FName{"null"}, true };
	WorldState isEnemyDead{ FName("IsEnemyDead"), false };
	WorldState isEnemyVisible{ FName("IsEnemyVisible"), false };
	WorldState wantsToPowerup{ FName("WantsToPowerup"), false };
	WorldState wantsToConverse{ FName("WantsToConverse"), false };
	WorldState isAttackCoolingDown{ FName("IsAttackCoolingDown"), false };
	WorldState isEnemyInAttackRange{ FName("IsEnemyInAttackRange"), false };
	WorldState isInEnemyAttackRange{ FName("IsInEnemyAttackRange"), false };
	WorldState isNearEnemy{ FName("IsNearEnemy"), false };

	TArray<WorldState> states{ isEnemyDead, isEnemyVisible, wantsToConverse, wantsToPowerup, 
		isAttackCoolingDown, isEnemyInAttackRange, isInEnemyAttackRange, isNearEnemy};

	// goals
	Goal killEnemy{FName("KillEnemy"), isEnemyDead, true};

	// actions
	Action attack{ FName("Attack"), isEnemyInAttackRange, true, isEnemyDead, true , 1};
	Action retreat{ FName("Retreat"), isInEnemyAttackRange, true, isNearEnemy, false, 5};
	Action gotoTarget{ FName("GotoTarget"), null, true, isEnemyInAttackRange, true, 3};

	TArray<Action> actions{ attack, retreat, gotoTarget };

	int totalDamage;
	int damageStacked;
	int numberOfAttacksSinceCooldown;
	int successfulHitsOnEnemySinceCooldown;
	
	float distanceToEnemy;


public:
	// Find a certain world state in WorldStates container
	float GetTargetDistance(const AActor* target) const;
	bool MakePlan(Goal goal);
	WorldState* GetState(const FName& stateName);
	friend class GOAPAIDebugHud;
};

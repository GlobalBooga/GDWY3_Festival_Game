// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldState.h"
#include "Action.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UActionInterface : public UInterface
{
    GENERATED_BODY()
};

class GDWY3_FESTIVAL_GAME_API IActionInterface
{
    GENERATED_BODY()
public:
    virtual bool Perform() = 0;
    virtual int GetCost() const = 0;
    virtual bool IsUsable(const WorldState& context) = 0;
    virtual FString GetName() const = 0;
    virtual const WorldState* GetPreRequisite() const = 0;
    virtual WorldState GetResult() const = 0;
    virtual bool SatisfiesStateVariable(WorldStateVariable const& variable) = 0;
};

UCLASS(Blueprintable, ClassGroup = "BossAction")
class GDWY3_FESTIVAL_GAME_API UAction: public UObject, public IActionInterface
{
    GENERATED_BODY()
public:
    UAction() {}
    UAction(FString name, int cost, const WorldState& preReq, const WorldState& effect) : name(name), cost(cost), preReq(preReq), result(effect) {}
    ~UAction() {};
    // Interface Functions
    
    UFUNCTION(BlueprintCallable)
    bool Perform();

    UFUNCTION(BlueprintCallable)
    int GetCost() const { return cost; }

    bool IsUsable(const WorldState& context);
    
    UFUNCTION(BlueprintCallable)
    FString GetName() const { return name; }

    virtual const WorldState* GetPreRequisite() const { return &preReq; }
    virtual WorldState GetResult() const { return result; }
    bool SatisfiesStateVariable(WorldStateVariable const& variable);

protected:
    // Base Variables
    UPROPERTY(EditAnywhere, Category = "Action Properties")
    FString name;

    UPROPERTY(EditAnywhere, Category = "Action Properties")
    int cost;

    WorldState preReq;
    WorldState result;
};

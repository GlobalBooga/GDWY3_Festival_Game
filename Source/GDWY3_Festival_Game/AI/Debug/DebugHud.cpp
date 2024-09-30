// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugHud.h"
#include "UObject/ConstructorHelpers.h"

ADebugHud::ADebugHud()
{
	static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/Roboto"));

	MainFont = Font.Object;
}
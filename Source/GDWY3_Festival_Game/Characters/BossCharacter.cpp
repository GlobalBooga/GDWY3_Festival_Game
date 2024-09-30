// Fill out your copyright notice in the Description page of Project Settings.


#include "BossCharacter.h"

// Sets default values
ABossCharacter::ABossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AIComponent = CreateDefaultSubobject<UGOAPAI>(FName("AI Component"));



}

// Called when the game starts or when spawned
void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Cyan, FString("test1"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Cyan, FString("test2"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Cyan, FString("test3"));
	}*/
}

// Called every frame
void ABossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABossCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


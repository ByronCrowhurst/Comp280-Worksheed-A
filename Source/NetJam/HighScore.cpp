// Fill out your copyright notice in the Description page of Project Settings.


#include "HighScore.h"

// Sets default values
AHighScore::AHighScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHighScore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHighScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AHighScore::GetScore()
{
	return score;
}

void AHighScore::SetScore(int _delta)
{

}


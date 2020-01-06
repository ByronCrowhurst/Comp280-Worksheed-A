// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HighScore.generated.h"

UCLASS()
class NETJAM_API AHighScore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHighScore();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int GetScore();
	void SetScore(int _delta);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int score;


};

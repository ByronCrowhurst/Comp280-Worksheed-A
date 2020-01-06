// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"

#include "HTTPRequest.generated.h"

USTRUCT()
struct FRequestScoreDetails
{
	GENERATED_BODY()

	UPROPERTY() FString name;
	UPROPERTY() int score;

	FRequestScoreDetails() {}

};

USTRUCT()
struct FResponceScoreDetails
{
	GENERATED_BODY()

	UPROPERTY() TArray<FRequestScoreDetails> details;

	FResponceScoreDetails() {}
};

UCLASS(Blueprintable)
class NETJAM_API AHTTPRequest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHTTPRequest();

	UFUNCTION(BlueprintCallable, Category = "HTTPRequest")
	void OnAddScore();
	UFUNCTION(BlueprintCallable, Category = "HTTPRequest")
	void PostScoreDetails_Responce(FHttpRequestPtr request, FHttpResponsePtr responce, bool bSuccess);
	UFUNCTION(BlueprintCallable, Category="HTTPRequest")
	void OnGetScoresButtonPress();
	UFUNCTION(BlueprintCallable, Category = "HTTPRequest")
	void GetScores_Responce(FHttpRequestPtr request, FHttpResponsePtr responce, bool bSuccess);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

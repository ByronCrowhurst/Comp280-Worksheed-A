// Fill out your copyright notice in the Description page of Project Settings.

#include "HTTPRequest.h"
#include "Engine/Engine.h"

// Sets default values
AHTTPRequest::AHTTPRequest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHTTPRequest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHTTPRequest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// This should add scores to the server
void AHTTPRequest::OnAddScore()
{
	GEngine->AddOnScreenDebugMessage(0, 100.0f, FColor::Green, TEXT("Add Score"));

	FString JsonString;
	FRequestScoreDetails score;

	score.name = "aaa";
	score.score = 100;

	GetJsonStringFromStruct<FRequestScoreDetails>(score, JsonString);
	TSharedRef<IHttpRequest> request = PostRequest("add_score", JsonString);
	request->OnProcessRequestComplete().BindUObject(this, &AHTTPRequest::PostScoreDetails_Responce);
	Send(request);
}

void AHTTPRequest::PostScoreDetails_Responce(FHttpRequestPtr request, FHttpResponsePtr responce, bool bSuccess)
{
	if (!ResponseIsValid(responce, bSuccess))
	{
		GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, TEXT("Post Score Failed"));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, TEXT("Post Score Success"));
}
// This should recieve scores from the server
void AHTTPRequest::OnGetScoresButtonPress()
{
	GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, TEXT("OnGetScoresButtonPress"));

	TSharedRef<IHttpRequest> Request = GetRequest("get_scores");
	Request->OnProcessRequestComplete().BindUObject(this, &AHTTPRequest::GetScores_Responce);
}

void AHTTPRequest::GetScores_Responce(FHttpRequestPtr request, FHttpResponsePtr responce, bool bSuccess)
{
	if (!ResponseIsValid(responce, bSuccess))
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Purple, TEXT("Failed to get response."));

		return;
	}

	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Green, TEXT("Success"));
	FString rawJson = responce->GetContentAsString();

	GEngine->AddOnScreenDebugMessage(0, 100.0f, FColor::Purple, rawJson);

	FResponceScoreDetails result;
	JsonObjectStringToUStruct<FResponceScoreDetails>(responce->GetContentAsString(), &result, 0, 0);

	for (int32 i = 0; i != result.details.Num(); ++i)
	{
		FString joinStr;
		joinStr += FString::FromInt(i);
		joinStr += TEXT(" ");
		joinStr += result.details[i].name;
		joinStr += TEXT(" ");
		joinStr += FString::FromInt(result.details[i].score);

	}
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PerceptionAIController.generated.h"

/**
 * 
 */
UCLASS()
class NEWDAKEY_API APerceptionAIController : public AAIController
{
	GENERATED_BODY()

public:
	APerceptionAIController();

	UPROPERTY(VisibleAnywhere, Category = "AI | Perception")
		class UAIPerceptionComponent* PerceptionComp;

	UPROPERTY(EditDefaultsOnly, Category = "AI | Perception")
		class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditDefaultsOnly, Category = "AI | Perception")
		class UAISenseConfig_Hearing* HearingConfig;	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "PerceptionAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"

APerceptionAIController::APerceptionAIController()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PErceptionComp"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));

	if (PerceptionComp && SightConfig && HearingConfig)
	{
		//Perception
		PerceptionComp->ConfigureSense(*SightConfig);
		PerceptionComp->ConfigureSense(*HearingConfig);
		PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());

		//Sight
		SightConfig->SightRadius = 2000.f;
		SightConfig->LoseSightRadius = 2250.f;
		SightConfig->PeripheralVisionAngleDegrees = 60.f;

		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		//Hearing
		HearingConfig->HearingRange = 3000.f;
		HearingConfig->bUseLoSHearing = false;
		HearingConfig->LoSHearingRange = 3500.f;

		HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
		HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
		HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	}
}
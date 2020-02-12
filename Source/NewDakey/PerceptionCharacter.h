// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PerceptionCharacter.generated.h"

UCLASS()
class NEWDAKEY_API APerceptionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APerceptionCharacter();

	UFUNCTION(BlueprintNativeEvent, Category = "AI | Perception")
		void GetPerceptionLocRot(FVector& Location, FRotator& Rotation) const;
		void GetPerceptionLocRot_Implementation(FVector& OutLocation, FRotator& OutRotation) const;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;
};

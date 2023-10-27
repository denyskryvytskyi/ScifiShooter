// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "ShooterAIController.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API AShooterAIController : public AAIController {
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

protected:
    UPROPERTY(EditDefaultsOnly)
    class UBehaviorTree* AIBehavior;
};

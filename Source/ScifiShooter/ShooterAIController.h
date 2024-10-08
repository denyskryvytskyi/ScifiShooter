// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"

#include "ShooterAIController.generated.h"

UCLASS()
class SCIFISHOOTER_API AShooterAIController : public AAIController {
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    bool IsAlive() const;

protected:
    UPROPERTY(EditDefaultsOnly)
    class UBehaviorTree* AIBehavior;

    bool bIsAlive { true };
};

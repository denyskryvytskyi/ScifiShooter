// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior) {
        RunBehaviorTree(AIBehavior);

        if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0)) {
            GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
            GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
        }
    }
}

bool AShooterAIController::IsAlive() const
{
    if (AShooterCharacter* OwnerPawn = Cast<AShooterCharacter>(GetPawn())) {
        return OwnerPawn->IsAlive();
    }

    return false;
}

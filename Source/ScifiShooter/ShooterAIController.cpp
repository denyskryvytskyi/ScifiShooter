// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet\GameplayStatics.h"

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

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0)) {
        if (LineOfSightTo(PlayerPawn)) {
            GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
            GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
        } else {
            GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        }
    }
}

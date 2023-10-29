// Fill out your copyright notice in the Description page of Project Settings.

#include "KillEmAll_GameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAll_GameMode::PawnKilled(APawn* Pawn)
{
    if (auto PlayerController = Cast<APlayerController>(Pawn->GetController())) {
        EndGame(false);
    }

    Super::PawnKilled(Pawn);

    // check whether we kill all enemies
    for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld())) {
        if (AIController->IsAlive()) {
            return;
        }
    }

    EndGame(true);
}

void AKillEmAll_GameMode::EndGame(bool bIsPLayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld())) {
        const bool bIsWinner = Controller->IsPlayerController() == bIsPLayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterPlayerController.h"
#include "Blueprint\UserWidget.h"
#include "TimerManager.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    UUserWidget* UserWidget = nullptr;
    if (bIsWinner) {
        UserWidget = CreateWidget(this, WinWidgetClass);
    } else {

        UserWidget = CreateWidget(this, GameOverWidgetClass);
    }

    if (UserWidget) {
        UserWidget->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &AShooterPlayerController::RestartLevel, RestartDelay);
}

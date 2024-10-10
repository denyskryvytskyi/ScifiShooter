// Copyright Denys Kryvytskyi. All Rights Reserved.

#include "ShooterPlayerController.h"
#include "Blueprint\UserWidget.h"
#include "TimerManager.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if (HUDWidget) {
        HUDWidget->RemoveFromParent();
    }

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

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HUDWidget = CreateWidget(this, HUDClass);
    HUDWidget->AddToViewport();
}

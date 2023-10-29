// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "ShooterPlayerController.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API AShooterPlayerController : public APlayerController {
    GENERATED_BODY()

public:
    virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
    UPROPERTY(EditAnywhere)
    float RestartDelay { 5.0f };

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<class UUserWidget> WinWidgetClass;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<class UUserWidget> GameOverWidgetClass;

    FTimerHandle RestartTimer;
};

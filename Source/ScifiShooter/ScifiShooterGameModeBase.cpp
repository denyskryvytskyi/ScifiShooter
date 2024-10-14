// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScifiShooterGameModeBase.h"
#include "ShooterCharacter.h"
#include "GameFramework/GameUserSettings.h"

void AScifiShooterGameModeBase::PawnKilled(APawn* Pawn)
{
    if (AShooterCharacter* Killed = Cast<AShooterCharacter>(Pawn)) {
        Killed->Die();

        if (AController* KilledController = Killed->GetController()) {
            KilledController->UnPossess();
        }
    }
}


void AScifiShooterGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    // change user settings
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    UserSettings->ScalabilityQuality.ViewDistanceQuality = 1;
    UserSettings->ScalabilityQuality.AntiAliasingQuality = 1;
    UserSettings->ScalabilityQuality.PostProcessQuality = 1;
    UserSettings->ScalabilityQuality.ShadowQuality = 1;
    UserSettings->ScalabilityQuality.GlobalIlluminationQuality = 2;
    UserSettings->ScalabilityQuality.ReflectionQuality = 2;
    UserSettings->ScalabilityQuality.TextureQuality = 2;
    UserSettings->ScalabilityQuality.EffectsQuality = 1;
    UserSettings->ScalabilityQuality.FoliageQuality = 0;
    UserSettings->ScalabilityQuality.ShadingQuality = 0;
    UserSettings->ScalabilityQuality.LandscapeQuality = 0;
    UserSettings->ApplySettings(false);
}
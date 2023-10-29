// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScifiShooterGameModeBase.h"
#include "ShooterCharacter.h"

void AScifiShooterGameModeBase::PawnKilled(APawn* Pawn)
{
    if (AShooterCharacter* Killed = Cast<AShooterCharacter>(Pawn)) {
        Killed->Die();

        if (AController* KilledController = Killed->GetController()) {
            KilledController->UnPossess();
        }
    }
}

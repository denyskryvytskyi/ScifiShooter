// Copyright Epic Games, Inc. All Rights Reserved.

#include "ScifiShooterGameModeBase.h"
#include "ShooterCharacter.h"

void AScifiShooterGameModeBase::ActorDied(AActor* Actor)
{
    if (AShooterCharacter* Killed = Cast<AShooterCharacter>(Actor)) {
        Killed->SetActorEnableCollision(false);
        Killed->OnDie();
        if (AController* KilledController = Killed->GetController()) {
            KilledController->UnPossess();
        }
    }
}

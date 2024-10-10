// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScifiShooterGameModeBase.h"

#include "KillEmAll_GameMode.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API AKillEmAll_GameMode : public AScifiShooterGameModeBase {
    GENERATED_BODY()

public:
    virtual void PawnKilled(APawn* Pawn);

private:
    void EndGame(bool bIsPLayerWinner);
};

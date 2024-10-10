// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "CoreMinimal.h"

#include "BTService_PlayerLocation.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API UBTService_PlayerLocation : public UBTService_BlackboardBase {
    GENERATED_BODY()

public:
    UBTService_PlayerLocation();

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

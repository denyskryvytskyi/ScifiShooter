// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "BehaviorTree/Services/BTService_BlackboardBase.h"

#include "BTService_PlayerLocationIfSeen.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API UBTService_PlayerLocationIfSeen : public UBTService_BlackboardBase {
    GENERATED_BODY()

public:
    UBTService_PlayerLocationIfSeen();

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

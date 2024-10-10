// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"

#include "BTTask_Shoot.generated.h"

/**
 *
 */
UCLASS()
class SCIFISHOOTER_API UBTTask_Shoot : public UBTTaskNode {
    GENERATED_BODY()

public:
    UBTTask_Shoot();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (AAIController* AIController = OwnerComp.GetAIOwner()) {
        if (AShooterCharacter* EnemyCharacter = Cast<AShooterCharacter>(AIController->GetPawn())) {
            EnemyCharacter->Shoot();
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}

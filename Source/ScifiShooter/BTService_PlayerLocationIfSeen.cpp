// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_PlayerLocationIfSeen.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet\GameplayStatics.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Player Location Is Seen?";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0)) {
        if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        } else {
            OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        }
    }
}

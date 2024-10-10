// Copyright Denys Kryvytskyi. All Rights Reserved.

#include "BTService_PlayerLocationIfSeen.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet\GameplayStatics.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Is Player Seen?";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0)) {
        if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
            OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), PlayerPawn);
        } else {
            OwnerComp.GetBlackboardComponent()->ClearValue(TEXT("Player"));
        }
    }
}

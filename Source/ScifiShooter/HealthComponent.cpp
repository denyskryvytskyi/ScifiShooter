// Copyright Denys Kryvytskyi. All Rights Reserved.

#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ScifiShooterGameModeBase.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    GetOwner()->OnTakePointDamage.AddDynamic(this, &UHealthComponent::OnDamageTaken);

    CurrentHealth = MaxHealth;

    ShooterGameMode = Cast<AScifiShooterGameModeBase>(UGameplayStatics::GetGameMode(this));
}

void UHealthComponent::OnDamageTaken(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser)
{
    CurrentHealth = FMath::Max(0.0f, CurrentHealth - Damage);

    if (FMath::IsNearlyZero(CurrentHealth)) {
        ShooterGameMode->PawnKilled(Cast<APawn>(DamagedActor));
    }
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ScifiShooterGameModeBase.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
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

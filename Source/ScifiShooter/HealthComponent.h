// Copyright Denys Kryvytskyi. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "HealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SCIFISHOOTER_API UHealthComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UHealthComponent();

    float GetMaxHealth() const { return MaxHealth; }
    float GetCurrentHealth() const { return CurrentHealth; }

protected:
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnDamageTaken(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser);

private:
    UPROPERTY(EditDefaultsOnly)
    float MaxHealth { 100.0f };

    float CurrentHealth { 0.0f };

    class AScifiShooterGameModeBase* ShooterGameMode;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SCIFISHOOTER_API UHealthComponent : public UActorComponent {
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UHealthComponent();

    float GetMaxHealth() const { return MaxHealth; }
    float GetCurrentHealth() const { return CurrentHealth; }

protected:
    // Called when the game starts
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

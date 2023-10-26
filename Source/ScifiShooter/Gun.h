// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SCIFISHOOTER_API AGun : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AGun();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void PullTrigger();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

protected:
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;

    UPROPERTY(VisibleAnywhere)
    USkeletalMeshComponent* MeshComp;

    UPROPERTY(EditAnywhere, category = "Gun")
    UParticleSystem* MuzzleFlash;

    UPROPERTY(EditAnywhere, category = "Gun")
    UParticleSystem* WorldHitEffect;

    UPROPERTY(EditAnywhere, category = "Gun")
    UParticleSystem* EnemyHitEffect;

    UPROPERTY(EditAnywhere, category = "Gun")
    float MaxShootDistance { 1000.0f };

    UPROPERTY(EditAnywhere, category = "Gun")
    float BulletDamage { 10.0f };
};

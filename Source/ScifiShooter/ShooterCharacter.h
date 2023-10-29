// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SCIFISHOOTER_API AShooterCharacter : public ACharacter {
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AShooterCharacter();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Shoot();

    void Die();

    bool IsAlive() const { return bIsAlive; }

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called for movement input
    void Move(const FInputActionValue& Value);

    // Called for looking input
    void Look(const FInputActionValue& Value);

    // Called for shooting input
    void ShootFromInput(const FInputActionValue& Value);

    // Implemented in blueprint
    UFUNCTION(BlueprintImplementableEvent)
    void OnDie();

protected:
    /** Components */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USpringArmComponent* SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UCameraComponent* CameraComp;

    /** Input Mapping Context */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputMappingContext* DefaultMappingContext;

    /** Jump Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputAction* JumpAction;

    /** Move Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputAction* MoveAction;

    /** Look Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputAction* LookAction;

    /** Shoot Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputAction* ShootAction;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AGun> GunClass;

    UPROPERTY()
    AGun* Gun;

    bool bIsAlive { true };
};

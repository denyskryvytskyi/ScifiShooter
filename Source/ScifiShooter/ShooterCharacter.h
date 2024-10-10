// Copyright Denys Kryvytskyi. All Rights Reserved.

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
    AShooterCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Shoot();

    void Die();

    bool IsAlive() const { return bIsAlive; }

    UFUNCTION(BlueprintCallable)
    float GetHealthPercent() const;

protected:
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
    AGun* Gun { nullptr };

    bool bIsAlive { true };
};

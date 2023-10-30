// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"

#include "Components\SkeletalMeshComponent.h"
#include "Kismet\GameplayStatics.h"

#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Root"));
    SetRootComponent(Root);

    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
    MeshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
    UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, MeshComp, TEXT("MuzzleFlashSocket"));
    UGameplayStatics::SpawnSoundAttached(MuzzleSound, MeshComp, TEXT("MuzzleFlashSocket"));

    if (APawn* PawnOwner = Cast<APawn>(GetOwner())) {
        if (AController* InstigatorController = PawnOwner->GetController()) {
            FVector Location;
            FRotator Rotation;
            InstigatorController->GetPlayerViewPoint(Location, Rotation);

            const FVector EndPoint = Location + Rotation.Vector() * MaxShootDistance;

            FCollisionQueryParams Params;
            Params.AddIgnoredActor(this);
            Params.AddIgnoredActor(GetOwner());

            FHitResult Hit;
            if (GetWorld()->LineTraceSingleByChannel(Hit, Location, EndPoint, ECollisionChannel::ECC_GameTraceChannel1, Params)) {
                const FVector HitFromDirection = -Rotation.Vector();

                if (AActor* DamagedActor = Hit.GetActor(); DamagedActor->ActorHasTag("Character")) {
                    // enemy hit
                    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
                                                             EnemyHitEffect,
                                                             Hit.Location,
                                                             HitFromDirection.Rotation());

                    UGameplayStatics::ApplyPointDamage(DamagedActor,
                                                       BulletDamage,
                                                       HitFromDirection,
                                                       Hit,
                                                       InstigatorController,
                                                       this, nullptr);

                } else {
                    // world hit
                    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
                                                             WorldHitEffect,
                                                             Hit.Location,
                                                             HitFromDirection.Rotation());
                }

                UGameplayStatics::SpawnSoundAtLocation(GetWorld(),
                                                       HitSound,
                                                       Hit.Location,
                                                       HitFromDirection.Rotation());
            }
        }
    }
}

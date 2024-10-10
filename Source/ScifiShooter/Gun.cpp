// Copyright Denys Kryvytskyi. All Rights Reserved.

#include "Gun.h"

#include "Components\SkeletalMeshComponent.h"
#include "Kismet\GameplayStatics.h"

#include "DrawDebugHelpers.h"

AGun::AGun()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Root"));
    SetRootComponent(Root);

    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
    MeshComp->SetupAttachment(RootComponent);
}

void AGun::BeginPlay()
{
    Super::BeginPlay();
}

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

                if (AActor* DamagedActor = Hit.GetActor()) {
                    if (DamagedActor->ActorHasTag("Character")) {
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
                }
                UGameplayStatics::SpawnSoundAtLocation(GetWorld(),
                                                       HitSound,
                                                       Hit.Location,
                                                       HitFromDirection.Rotation());
            }
        }
    }
}

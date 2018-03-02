// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaserComponent.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
// Sets default values for this component's properties
UPhaserComponent::UPhaserComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/BeamParticleSystem.BeamParticleSystem'"));
	phaserEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BeamParticleSystem"));
	phaserEffect->SetTemplate(PS.Object);
	phaserEffect->SetBeamSourcePoint(1, FVector(100,100,100), 0);
	phaserEffect->SetBeamTargetPoint(1, FVector(0,0,0), 0);
	phaserEffect->ToggleActive();
	//phaserEffect->Activate(true);
	// ...
}


// Called when the game starts
void UPhaserComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	TArray<USkeletalMeshComponent*> mesh;
	GetOwner()->GetComponents(mesh, true);

	if (mesh.Num() > 0)
	{
		skele_mesh = mesh[0];
		names = skele_mesh->GetAllSocketNames();

		for (int i = 0; i < names.Num(); i++)
		{
			FString name = names[i].ToString();
			if (name.Contains("Phaser"))
			{

			}
			else
			{
				names.RemoveAt(i);
			}
		}
	}

	if (skele_mesh)
	{
		for (int i = 0; i < names.Num(); i++)
		{
			//FVector ParticleSystemSource;
	
			//UWorld* const world = GetWorld();
			//ABullet* bullet = world->SpawnActor<ABullet>(ABullet::StaticClass(), spawningLocation, spawnRotation);
		}
	}

}


// Called every frame
void UPhaserComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UPhaserComponent::FirePhasers()
{
	if (skele_mesh)
	{
		for (int i = 0; i < names.Num(); i++)
		{
			spawningLocation = skele_mesh->GetSocketLocation(names[i]);
			UWorld* const world = GetWorld();
		}
	}
}


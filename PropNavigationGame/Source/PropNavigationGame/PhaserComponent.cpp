// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaserComponent.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyShip.h"
// Sets default values for this component's properties
UPhaserComponent::UPhaserComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Load particle system made in folders
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/BeamParticleSystem.BeamParticleSystem'"));
	phaserEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BeamParticleSystem"));
	phaserEffect->SetActive(false);
	//set the template 
	phaserEffect->SetTemplate(PS.Object);

	// ...
}

//initialise phaser weapons initial values
//*first param- How much damage in one phaser duration
//*second param- How long between each phaser blast
void UPhaserComponent::InitialiseComponent(float damageOverDurationValue, float coolDownInSeconds)
{
	m_damageOverDurationValue = damageOverDurationValue;
	m_coolDownInSeconds = coolDownInSeconds;
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
}


// Called every frame
void UPhaserComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


//Fire Phasers function
//*first param- Target that we are firing at 
void UPhaserComponent::FirePhasers(AEnemyShip* target)
{
	//if the skeletal mesh exists on the object
	if (skele_mesh)
	{
		//for each socket found in the skeletal mesh in the constructor
		for (int i = 0; i < names.Num(); i++)
		{
			//store the world location and rotation of the socket
			FRotator rotation;
			skele_mesh->GetSocketWorldLocationAndRotation(names[i], spawningLocation, rotation);

			//make the source point the socket 
			phaserEffect->SetBeamSourcePoint(0, spawningLocation, 0);
			phaserEffect->SetBeamSourcePoint(1, spawningLocation, 0);
			//make the target point the target object
			phaserEffect->SetBeamTargetPoint(0, target->GetActorLocation(), 0);
			phaserEffect->SetBeamTargetPoint(1, target->GetActorLocation(), 0);

			//enable phasers
			phaserEffect->ToggleActive();

			//cast to enemy ship
			target->ApplyDamageTaken(m_damageOverDurationValue);
			//target = nullptr;

		}
	}
}


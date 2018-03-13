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
	phaserEffect->SetVisibility(false);
	//set the template 
	phaserEffect->SetTemplate(PS.Object);

	// ...
}

//initialise phaser weapons initial values
//*first param- How much damage in one phaser duration
//*second param- How long between each phaser blast
void UPhaserComponent::InitialiseComponent(float damageOverDurationValue, float coolDownInSeconds, FName name, USkeletalMeshComponent* skelMesh)
{
	m_damageOverDurationValue = damageOverDurationValue;
	m_coolDownInSeconds = coolDownInSeconds;
	socketName = name;
	skele_mesh = skelMesh;
}


// Called when the game starts
void UPhaserComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UPhaserComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator rotation;
	skele_mesh->GetSocketWorldLocationAndRotation(socketName, spawningLocation, rotation);
	phaserEffect->SetBeamSourcePoint(0, spawningLocation, 0);


	if (bPhaserActive)
	{
		ToggleForSeconds(120);
	}
}


//Fire Phasers function
//*first param- Target that we are firing at 
void UPhaserComponent::FirePhasers(AEnemyShip* target)
{
	//if the skeletal mesh exists on the object
	if (skele_mesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Skeleton mesh=: %s."), *skele_mesh->GetName());

		//store the world location and rotation of the socket
		FRotator rotation;
		skele_mesh->GetSocketWorldLocationAndRotation(socketName, spawningLocation, rotation);

		//make the source point the socket 
		phaserEffect->SetBeamSourcePoint(0, spawningLocation, 0);
		phaserEffect->SetBeamSourcePoint(1, spawningLocation, 0);

		//make the target point the target object and store latest target location
		lastKnownTarget = target;
		phaserEffect->SetBeamTargetPoint(0, target->GetActorLocation(), 0);
		phaserEffect->SetBeamTargetPoint(1, target->GetActorLocation(), 0);

		//Enable phasers
		bPhaserActive = true;

		//cast to enemy ship
		target->ApplyDamageTaken(m_damageOverDurationValue);
	}
}

//Toggle Phasers for duration
//@first parameter: Seconds for timer
void UPhaserComponent::ToggleForSeconds(float seconds)
{
	if (timerSeconds < seconds)
	{
		//phaserEffect->SetActive(true);
		phaserEffect->SetBeamTargetPoint(0, lastKnownTarget->GetActorLocation(), 0);
		phaserEffect->SetVisibility(true);
		timerSeconds++;
	}
	else
	{
		//phaserEffect->SetActive(false);
		phaserEffect->SetVisibility(false);
		timerSeconds = 0.0f;
		bPhaserActive = false;
	}
}


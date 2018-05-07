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
	//PrimaryComponentTick.bStartWithTickEnabled = true;

	//Load particle system made in folders
	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/BeamParticleSystem.BeamParticleSystem'"));
	phaserEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BeamParticleSystem"));

	//Register the components made dynamically
	phaserEffect->RegisterComponent();
	phaserEffect->SetTemplate(PS.Object);
}

//initialise phaser weapons initial values
//*first param- How much damage in one phaser duration
//*second param- How long between each phaser blast
void UPhaserComponent::InitialiseComponent(float damageOverDurationValue, float coolDownInSeconds, FName name, USkeletalMeshComponent* skelMesh)
{
	m_damageOverDurationValue = damageOverDurationValue;
	m_coolDownInSeconds = coolDownInSeconds;
	m_socketName = name;
	//skele_mesh = skelMesh;
}


// Called when the game starts
void UPhaserComponent::BeginPlay()
{
	Super::BeginPlay();
	phaserEffect->SetVisibility(false);
	// ...v	
	TArray<USkeletalMeshComponent*> mesh;
	GetOwner()->GetComponents(mesh, true);
	
	if (mesh.Num() > 0)
	{
		skele_mesh = mesh[0];
		m_names = skele_mesh->GetAllSocketNames();
	}
}


// Called every frame
void UPhaserComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator rotation;
	skele_mesh->GetSocketWorldLocationAndRotation(m_socketName, m_spawningLocation, rotation);
	phaserEffect->SetBeamSourcePoint(0, m_spawningLocation, 0);

	if (m_bPhaserActive)
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

		//store the world location and rotation of the socket
		FRotator rotation;
		skele_mesh->GetSocketWorldLocationAndRotation(m_socketName, m_spawningLocation, rotation);
		
		//make the source point the socket 
		phaserEffect->SetBeamSourcePoint(0, m_spawningLocation, 0);
		phaserEffect->SetBeamSourcePoint(1, m_spawningLocation, 0);

		//make the target point the target object and store latest target location
		m_lastKnownTarget = target;
		phaserEffect->SetBeamTargetPoint(0, target->GetActorLocation(), 0);
		phaserEffect->SetBeamTargetPoint(1, target->GetActorLocation(), 0);

		//Enable phasers
		m_bPhaserActive = true;

		//cast to enemy ship
		target->ApplyDamageTaken(m_damageOverDurationValue, skele_mesh->GetComponentLocation());
	}
}

//Toggle Phasers for duration
//@first parameter: Seconds for timer
void UPhaserComponent::ToggleForSeconds(float seconds)
{
	//if the time hasn't elasped 
	if (m_timerSeconds < seconds)
	{
		//turn on the phaser effect
		phaserEffect->SetVisibility(true);

		//Set the beams target point to the last known target selected
		phaserEffect->SetBeamTargetPoint(0, m_lastKnownTarget->GetActorLocation(), 0);
	
		//increment timer
		m_timerSeconds++;
		//UE_LOG(LogTemp, Warning, TEXT("last Known Target location=: %s."), *lastKnownTarget->GetActorLocation().ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Visibible"));
	
	}
	//if the time has elapsed
	else
	{
		//Turn off the phaser effect
		phaserEffect->SetVisibility(false);

		//Reset timer for the next phaser fired
		m_timerSeconds = 0.0f;

		//set the phaser active to false
		m_bPhaserActive = false;

		UE_LOG(LogTemp, Warning, TEXT("invisible"));
	}
}


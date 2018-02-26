// Fill out your copyright notice in the Description page of Project Settings.

#include "FiringComponent.h"
#include "Bullet.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//

	// ...
}

void UFiringComponent::InitialiseComponent()
{

}



// Called when the game starts
void UFiringComponent::BeginPlay()
{
	Super::BeginPlay();


	TArray<USkeletalMeshComponent*> mesh;
	GetOwner()->GetComponents(mesh);
	
	if (mesh.Num() > 0)
	{
		skele_mesh = mesh[0];
	
		spawningLocation = skele_mesh->GetSocketLocation("ShootingSocketRight");
	}
}


// Called every frame
void UFiringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFiringComponent::FireMissile()
{
	if (skele_mesh)
	{

		FRotator spawnRotation;
		skele_mesh->GetSocketWorldLocationAndRotation("RightFiringSocket", spawningLocation, spawnRotation);
	
		UWorld* const world = GetWorld();
		ABullet* bullet = world->SpawnActor<ABullet>(ABullet::StaticClass(), spawningLocation, spawnRotation);
	}
}



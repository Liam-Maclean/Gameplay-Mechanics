// Fill out your copyright notice in the Description page of Project Settings.

#include "FiringComponent.h"


// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//TArray<USkeletalMeshComponent*> mesh;
	//GetOwner()->GetComponents(mesh);
	//
	//if (mesh.Num() > 0)
	//{
	//	USkeletalMeshComponent* foundSkeletalMesh = mesh[0];
	//
	//	spawningLocation = foundSkeletalMesh->GetSocketLocation("ShootingSocketRight");
	//}

	// ...
}


// Called when the game starts
void UFiringComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFiringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFiringComponent::FireMissile()
{
	//TArray<USkeletalMeshComponent*> mesh;
	//GetOwner()->GetComponents(mesh);
	//
	//if (mesh.Num() > 0)
	//{
	//	USkeletalMeshComponent* foundSkeletalMesh = mesh[0];
	//
	//	spawningLocation = foundSkeletalMesh->GetSocketLocation("ShootingSocketRight");
	//
	//	UWorld* world = GetWorld();
	//	//ABullet* bullet = world->SpawnActor<ABullet>(bulletClass, spawnLocation, spawnRotation);
	//
	//}
}



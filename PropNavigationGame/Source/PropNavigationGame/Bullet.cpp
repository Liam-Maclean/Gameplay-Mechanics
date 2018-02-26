// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/SphereComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* sphereMesh = CreateDefaultSubobject<USphereComponent>(TEXT("Mesh"));
	RootComponent = sphereMesh;
	sphereMesh->InitSphereRadius(5.0f);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newActorPosition = GetActorLocation();
	//move the actor forward using the actors' forward vector and multiplying by speed
	newActorPosition += (GetActorForwardVector() * speed);

	SetActorLocation(newActorPosition);

}


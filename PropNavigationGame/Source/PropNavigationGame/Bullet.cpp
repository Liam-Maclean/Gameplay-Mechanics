// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Engine/World.h"
// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	//Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereMesh.Object)
		staticMesh->SetStaticMesh(SphereMesh.Object);
	RootComponent = staticMesh;
	staticMesh->SetWorldScale3D(FVector(0.10, 0.10, 0.10));
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

	//if the Actor's duration hasn't expired
	if (!DurationEnded())
	{
		DurationCountdown(DeltaTime);
		//get actors current location
		FVector newActorPosition = GetActorLocation();

		//move the actor forward using the actors' forward vector and multiplying by speed
		newActorPosition += (GetActorForwardVector() * speed);
		SetActorLocation(newActorPosition);
	}
	else
	{
		//Kill Object
		AActor::K2_DestroyActor();
	}
}

//Countdown Duration of missile
void ABullet::DurationCountdown(float DeltaTime)
{
	//use delta time (time elapsed)
	durationInSeconds -= DeltaTime;
}

//Check if the duration of the missile has ended
bool ABullet::DurationEnded()
{
	//if the timer is still going
	if (durationInSeconds > 0.0f)
	{
		//not ended
		return false;
	}
	//if the timer has stopped (bellow 0)
	else
	{
		//has ended
		return true;
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyShip.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Bullet.h"
// Sets default values
AEnemyShip::AEnemyShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	shieldComponent = CreateDefaultSubobject<UShieldComponent>(TEXT("Shield Component"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));

	sphereMesh = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Mesh Component"));
	sphereMesh->InitSphereRadius(100.0f);
	sphereMesh->SetCollisionProfileName("Trigger");

	RootComponent = sphereMesh;

	//staticMesh->SetupAttachment(RootComponent);

	sphereMesh->OnComponentBeginOverlap.AddDynamic(this, &AEnemyShip::OnOverlapBegin);
	
}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyShip::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (OtherActor->IsA(ABullet::StaticClass()))
		{

			if (shieldComponent)
			{
				shieldComponent->DecrementShield(20);
			}
			else if (healthComponent)
			{
				healthComponent->DecrementHealth(50);
			}
			
			if ((!shieldComponent->IsValidLowLevel()) && (!healthComponent->IsValidLowLevel()))
			{
				Destroy();
			}
			OtherActor->Destroy();
		}
		//Destroy();
		//OtherActor->Destroy();
		//if (OtherActor->Tags.Find("Bullet"))
		//{
		//	OtherActor->Destroy();
		//	Destroy();
		//}
	}
}



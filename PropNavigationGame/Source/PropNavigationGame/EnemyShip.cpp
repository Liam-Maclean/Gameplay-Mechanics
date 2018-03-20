// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyShip.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Bullet.h"
#include "ConstructorHelpers.h"

// Sets default values
AEnemyShip::AEnemyShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90'"));


	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	shieldComponent = CreateDefaultSubobject<UShieldComponent>(TEXT("Shield Component"));
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	sphereMesh = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Mesh Component"));
	sphereMesh->InitSphereRadius(100.0f);
	sphereMesh->SetCollisionProfileName("Trigger");
	RootComponent = sphereMesh;
	sphereMesh->OnComponentBeginOverlap.AddDynamic(this, &AEnemyShip::OnOverlapBegin);
	//shieldComponent->AddToRoot();

	

	frontShield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontShield"));
	leftBroadSideShield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("leftBroadSideShield"));
	rightBroadSideShield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rightBroadSideShield"));
	reerShield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReerShield"));



	frontShield->SetStaticMesh(SM.Object);
	leftBroadSideShield->SetStaticMesh(SM.Object);
	rightBroadSideShield->SetStaticMesh(SM.Object);
	reerShield->SetStaticMesh(SM.Object);

	frontShield->SetWorldLocation(FVector(0, 0, -12.5));
	leftBroadSideShield->SetWorldLocation(FVector(0, 0, -12.5));
	rightBroadSideShield->SetWorldLocation(FVector(0, 0, -12.5));
	reerShield->SetWorldLocation(FVector(0, 0, -12.5));


	frontShield->AttachTo(RootComponent);
	leftBroadSideShield->AttachTo(RootComponent);
	rightBroadSideShield->AttachTo(RootComponent);
	reerShield->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();
	FRotator rotation;
	rotation.Yaw = 45;
	frontShield->SetWorldRotation(rotation);

	rotation.Yaw = 135;
	rightBroadSideShield->SetWorldRotation(rotation);

	rotation.Yaw = 225;
	reerShield->SetWorldRotation(rotation);

	rotation.Yaw = 315;
	leftBroadSideShield->SetWorldRotation(rotation);

	StartScale = FVector(1, 1, 1);
	frontShield->AddWorldOffset(FVector(0, 40, 0));
	rightBroadSideShield->AddWorldOffset(FVector(-40,0, 0));
	leftBroadSideShield->AddWorldOffset(FVector(40, 0, 0));
	reerShield->AddWorldOffset(FVector(0, -40, 0));
}

//Times down the incombat reset timer to check if the shop is still in combat
//@Checks for 5 seconds if the ship has taken any damage or performed any attacking action
void AEnemyShip::IncrementInCombatTimer()
{
	//if in combat
	if (InCombat)
	{
		//increment timer 
		if (timer < 300.0f)
		{
			timer++;
		}
		//if timer has elapsed fully
		else
		{
			//set in combat to false
			SetInCombat(false);
			timer = 0.0f;
		}
	}
}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	IncrementInCombatTimer();
}

//toggle ship in combat to apply regeneration and change components
void AEnemyShip::SetInCombat(bool inCombat)
{
	//store if ship is in combat
	InCombat = inCombat;

	//toggle components that require in combat information
	shieldComponent->ToggleInCombat(inCombat);

	//if in combat again
	if (inCombat == true)
	{
		//reset the timer 
		timer = 0.0f;
	}

}

//Take damage from hit/actor
void AEnemyShip::ApplyDamageTaken(int value, FVector AttackerLocation)
{
	//toggle the ship is in combat after taking damage
	SetInCombat(true);

	//if the shields are higher than 0 
	if (shieldComponent->GetShieldStrength() > 0.0f)
	{
		//decrease shield values
		shieldComponent->DecrementShield(20, AttackerLocation);
	}
	//otherwise check if health values are greater than 0 
	else if (healthComponent->GetHealthStrength() > 0.0f)
	{
		//decrease health values
		healthComponent->DecrementHealth(50);
	}

	//if both values are bellow or equal to 0
	if (shieldComponent->GetShieldStrength() <= 0.0f && healthComponent->GetHealthStrength() <= 0.0f)
	{
		//destroy the object
		Destroy();
	}

	ScaleShields();
}

void AEnemyShip::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (OtherActor->IsA(ABullet::StaticClass()))
		{

			//if (shieldComponent)
			//{
			//	shieldComponent->DecrementShield(20);
			//}
			//else if (healthComponent)
			//{
			//	healthComponent->DecrementHealth(50);
			//}
			
			if ((!shieldComponent->IsValidLowLevel()) && (!healthComponent->IsValidLowLevel()))
			{
				Destroy();
			}
			OtherActor->Destroy();
		}
	}
}

//scale shield sizes with values
void AEnemyShip::ScaleShields()
{
	if (shieldComponent)
	{
		float ReerShieldPercentage = (float)shieldComponent->GetReerShieldStrength() / 100;
		float FrontShieldPercentage = (float)shieldComponent->GetFrontShieldStrength() / 100;
		float LeftShieldPercentage = (float)shieldComponent->GetLeftShieldStrength() / 100;
		float RightShieldPercentage = (float)shieldComponent->GetRightShieldStrength() / 100;

		UE_LOG(LogTemp, Warning, TEXT("Reer percent=: %f."), ReerShieldPercentage);
		UE_LOG(LogTemp, Warning, TEXT("Front Percent=: %f."), FrontShieldPercentage);
		UE_LOG(LogTemp, Warning, TEXT("Left Percent=: %f."), LeftShieldPercentage);
		UE_LOG(LogTemp, Warning, TEXT("Right Percent=: %f."), RightShieldPercentage);

		FVector frontShieldScale, leftShieldScale, rightShieldScale, reerShieldScale;
		
		frontShieldScale = StartScale * FrontShieldPercentage;
		reerShieldScale = StartScale * ReerShieldPercentage;
		leftShieldScale = StartScale * LeftShieldPercentage;
		rightShieldScale = StartScale * RightShieldPercentage;

		UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *frontShieldScale.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *reerShieldScale.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *leftShieldScale.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *rightShieldScale.ToString());

		frontShield->SetWorldScale3D(frontShieldScale);
		leftBroadSideShield->SetWorldScale3D(leftShieldScale);
		rightBroadSideShield->SetWorldScale3D(rightShieldScale);
		reerShield->SetWorldScale3D(reerShieldScale);
	}
}



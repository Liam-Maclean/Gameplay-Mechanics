// Fill out your copyright notice in the Description page of Project Settings.

#include "HomingRocket.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyShip.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AHomingRocket::AHomingRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	sphereMesh = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Mesh"));
	//Mesh

	sphereMesh->InitSphereRadius(1.0f);
	sphereMesh->SetCollisionProfileName("Trigger");

	RootComponent = sphereMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereMesh.Object)
		staticMesh->SetStaticMesh(SphereMesh.Object);

	staticMesh->AttachTo(RootComponent);
	staticMesh->SetWorldScale3D(FVector(0.10, 0.10, 0.10));
	//collect target information
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyShip::StaticClass(), FoundActors);
}

// Called when the game starts or when spawned
void AHomingRocket::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHomingRocket::InitialiseRocket(AActor* target)
{
	targetActor = target;
	//skele_mesh = skelMesh;
}

// Called every frame
void AHomingRocket::Tick(float DeltaTime)
{
	//thisPreviousActorLocation = thisActorLocation;
	//targetPreviousActorLocation = targetActorLocation;
	Seek();
	Super::Tick(DeltaTime);
	if (thisPreviousActorLocation != thisActorLocation)
	{
		thisPreviousActorLocation = GetActorLocation();
		targetPreviousActorLocation = targetActor->GetActorLocation();
	}
}

//seeks the target down using proportional navigation
void AHomingRocket::Seek()
{
	if (targetActor)
	{
	
		thisActorLocation = GetActorLocation();
		FRotator thisActorRotation = GetActorRotation();
		targetActorLocation = targetActor->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("LOS Delta: %s."), *targetActor->GetActorLocation().ToString());
		if (thisPreviousActorLocation != FVector(0, 0, 0))
		{
			LoS = targetActorLocation - thisActorLocation;
			PreviousLos = targetPreviousActorLocation - thisPreviousActorLocation;

			UE_LOG(LogTemp, Warning, TEXT("Target Location: %s."), *thisActorLocation.ToString());
			UE_LOG(LogTemp, Warning, TEXT("Previous Target location: %s"), *thisPreviousActorLocation.ToString());

			//UE_LOG(LogTemp, Warning, TEXT("LOS: %s."), *LoS.ToString());
			//UE_LOG(LogTemp, Warning, TEXT("Previous LOS: %s"), *PreviousLos.ToString());

			LoS.Normalize();
			PreviousLos.Normalize();

			//UE_LOG(LogTemp, Warning, TEXT("Normalized LOS: %s."), *LoS.ToString());
			//UE_LOG(LogTemp, Warning, TEXT("Normalized Previous LOS: %s"), *PreviousLos.ToString());

			LoSDelta = LoS - PreviousLos;
			LoSRate = LoSDelta.Size();
			//UE_LOG(LogTemp, Warning, TEXT("last Known Target location=: %s."), *lastKnownTarget->GetActorLocation().ToString());
			//UE_LOG(LogTemp, Warning, TEXT("LOS Delta: %s."), *LoSDelta.ToString());
			//UE_LOG(LogTemp, Warning, TEXT("LOS Rate: %i."), LoSRate);

			thisActorRotation.RotateVector(LoSDelta * 2);

			SetActorRotation(thisActorRotation);

			SetActorLocation(thisActorLocation += (GetActorForwardVector() * 0.6f));
		}

		PreviousLos = LoS;

		

	}
}


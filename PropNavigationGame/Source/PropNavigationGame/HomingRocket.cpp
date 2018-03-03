// Fill out your copyright notice in the Description page of Project Settings.

#include "HomingRocket.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyShip.h"
#include "GenericPlatform/GenericPlatformMath.h"

// Sets default values
AHomingRocket::AHomingRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//collect target information
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyShip::StaticClass(), FoundActors);
}

// Called when the game starts or when spawned
void AHomingRocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHomingRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//seeks the target down using proportional navigation
void AHomingRocket::Seek()
{
	if (FoundActors.Num() > 0)
	{
		//FVector thisLocation = GetActorLocation();
		//PreviousLos = LoS;
		//LoS = FGenericPlatformMath::Atan2((float)thisLocation.Y - Target.Y, thisLocation.X - Target.X);
		//LoS = FMath::RadiansToDegrees(LoS);
		//LoSRate = LoS - PreviousLos;
		//FRotator rotation;
		//rotation = GetActorRotation();
		//
		//rotation = FRotator(LoS, LoS, LoS);
		//
		//SetActorRotation(rotation.Quaternion);
		//SetActorLocation(GetActorForwardVector() * 0.6f);
		//rotation = GetActorRotation();
		//rotation += (LoS * NavigationalConstant);

		//seek down target using nav
		//FoundActors[0]->GetActorLocation();
	}
}


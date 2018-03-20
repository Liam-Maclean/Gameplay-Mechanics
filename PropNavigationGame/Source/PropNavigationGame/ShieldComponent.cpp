// Fill out your copyright notice in the Description page of Project Settings.

#include "ShieldComponent.h"
#include "GameFramework/Actor.h"
#include "ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UShieldComponent::UShieldComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_90'"));
	//
	//frontShield = CreateDefaultSubobject<UStaticMesh>(TEXT("FrontShield"));
	//leftBroadSideShield = CreateDefaultSubobject<UStaticMesh>(TEXT("leftBroadSideShield"));
	//rightBroadSideShield = CreateDefaultSubobject<UStaticMesh>(TEXT("rightBroadSideShield"));
	//reerShield = CreateDefaultSubobject<UStaticMesh>(TEXT("ReerShield"));
	
	//frontShield->SetStaticMesh(SM.Object);
	//leftBroadSideShield->SetStaticMesh(SM.Object);
	//rightBroadSideShield->SetStaticMesh(SM.Object);
	//reerShield->SetStaticMesh(SM.Object);


	//
	//
	//frontShield->RegisterComponent();
	//leftBroadSideShield->RegisterComponent();
	//rightBroadSideShield->RegisterComponent();
	//reerShield->RegisterComponent();
	// ...
}

int UShieldComponent::GetFrontShieldStrength()
{
	return frontShieldValue;
}

// Called when the game starts
void UShieldComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}

//returns shield strength
int UShieldComponent::GetShieldStrength()
{
	return shieldStrength;
}

//returns the health percentage of the component
int UShieldComponent::GetShieldPercentage()
{
	//return percentage using max health strength and health strength as values
	return (shieldStrength / maxShieldStrength);
}

//toggle if the ship is in combat or not 
void UShieldComponent::ToggleInCombat(bool inCombat)
{
	//assign in combat boolean
	InCombat = inCombat;
}

//Regenerate shield method
//@Calculates shield regeneration values when in and out of combat
void UShieldComponent::RegenerateShields()
{
	//if in combat 
	if (InCombat)
	{
		//if the timer hasn't lasted 5 seconds
		if (timer < 300)
		{
			//Increment timer
			timer++;
		}
		else
		{
			//if the shield strength isn't at it's upper limit
			if (shieldStrength < maxShieldStrength)
			{
				//Increment shield strength with in combat regen values
				IncrementShield(regenInCombatP5);
				timer = 0.0f;
			}
		}
	}
	//if not in combat
	else if (!InCombat)
	{
		//if the timer hasn't lasted 5 seconds
		if (timer < 300)
		{
			//Increment Timer
			timer++;
		}
		else
		{
			//if the shield strength isn't at it's upper limit
			if (shieldStrength < maxShieldStrength)
			{
				//increment the shield strength with out of combat regen values
				IncrementShield(regenOutOfCombatP5);
				timer = 0.0f;
			}
		}
	}
}

// Called every frame
void UShieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	RegenerateShields();
}

//Decrement the shield value
void UShieldComponent::DecrementShield(int value, FVector SourceOfFire)
{
	//Actor rotation
	FRotator ownerActorRotation = GetOwner()->GetActorRotation();

	//Actor location
	FVector ownerActorLocation = GetOwner()->GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *SourceOfFire.ToString());
	

	//get the direction of the fire 
	FVector direction = ownerActorLocation - SourceOfFire;
	//Get the angle of the directional vector

	UE_LOG(LogTemp, Warning, TEXT("Direction=: %s."), *direction.ToString());

	double angleOfFire = (FMath::Atan2(direction.X, direction.Y));
	angleOfFire = angleOfFire * 360 / (3.14 * 2);
	if (angleOfFire < 0)
	{
		angleOfFire = angleOfFire + 360;
	}


	UE_LOG(LogTemp, Warning, TEXT("Angle of Fire =: %f."), angleOfFire);
	//clamp the rotation values of the ship between 0 and 360 (for calculations)
	FRotator clampedRotation = ownerActorRotation.Clamp();

	UE_LOG(LogTemp, Warning, TEXT("Clamped Rotation =: %s."), *clampedRotation.ToString());


	//if damage lies on the front angle of the ship (between -45 and 45 degrees)
	if (angleOfFire > 315 + clampedRotation.Pitch && angleOfFire < 360 + clampedRotation.Pitch || angleOfFire > 0 + clampedRotation.Pitch && angleOfFire < 45 + clampedRotation.Pitch)
	{
		//Front Shield Damage
		frontShieldValue -= value;
		if (frontShieldValue <= 0)
		{
			frontShieldValue = 0;
		}
	}
	//if damage lies on the right angle of the ship (between 45 and 135 degrees
	else if (angleOfFire > 45 + clampedRotation.Pitch && angleOfFire < 135 + clampedRotation.Pitch)
	{
		//Right Broadside Damage
		rightShieldValue -= value;
		if (rightShieldValue <= 0)
		{
			rightShieldValue = 0;
		}
	}
	//if the damage lies on the reer angle of the ship (between 135 and 225 degrees)
	else if (angleOfFire > 135 + clampedRotation.Pitch && angleOfFire < 225 + clampedRotation.Pitch)
	{
		//Reer Damage
		reerShieldValue -= value;
		if (reerShieldValue <= 0)
		{
			reerShieldValue = 0;
		}
	}
	//if the damage lies on the left angle of the ship (between 225 and 315 degrees)
	else if (angleOfFire > 225 + clampedRotation.Pitch && angleOfFire < 325 + clampedRotation.Pitch)
	{
		//Left Broadside Damage
		leftShieldValue -= value;
		if (leftShieldValue <= 0)
		{
			leftShieldValue = 0;
		}
	}
}

//Increment shield value
void UShieldComponent::IncrementShield(int value)
{
	//Increase shield value
	shieldStrength += value;
}



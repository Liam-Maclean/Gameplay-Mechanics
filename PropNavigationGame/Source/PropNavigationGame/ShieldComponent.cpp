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

	//Initialise the divided shield value by dividing the total value by 4
	dividedShieldValue = maxShieldStrength / 4;

	//Set the values of the shields to the equal divided value
	reerShieldValue = dividedShieldValue;
	leftShieldValue = dividedShieldValue;
	rightShieldValue = dividedShieldValue;
	frontShieldValue = dividedShieldValue;

	// ...
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
float UShieldComponent::GetShieldPercentage()
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
			//if front shield value is less than the max shield value
			if (frontShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::front);

				//if the value has exceeded the divided shield value after incrementing
				if (frontShieldValue > dividedShieldValue)
				{
					//assign it the max value
					frontShieldValue = dividedShieldValue;
				}
			}

			//if left shield value is less than the max shield value
			if (leftShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::left);

				//if the value has exceeded the divided shield value after incrementing
				if (leftShieldValue > dividedShieldValue)
				{
					//assign it the max value
					leftShieldValue = dividedShieldValue;
				}
			}

			//if right shield value is less than the max shield value
			if (rightShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::right);

				//if the value has exceeded the divided shield value after incrementing
				if (rightShieldValue > dividedShieldValue)
				{
					//assign it the max value
					rightShieldValue = dividedShieldValue;
				}
			}

			//if reer shield value is less than the max shield value
			if (reerShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::reer);

				//if the value has exceeded the divided shield value after incrementing
				if (reerShieldValue > dividedShieldValue)
				{
					//assign it the max value
					reerShieldValue = dividedShieldValue;
				}
			}

			//reset regen timer
			timer = 0.0f;
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
			//if front shield value is less than the max shield value
			if (frontShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::front);

				//if the value has exceeded the divided shield value after incrementing
				if (frontShieldValue > dividedShieldValue)
				{
					//assign it the max value
					frontShieldValue = dividedShieldValue;
				}
			}

			//if left shield value is less than the max shield value
			if (leftShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::left);

				//if the value has exceeded the divided shield value after incrementing
				if (leftShieldValue > dividedShieldValue)
				{
					//assign it the max value
					leftShieldValue = dividedShieldValue;
				}
			}

			//if right shield value is less than the max shield value
			if (rightShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::right);

				//if the value has exceeded the divided shield value after incrementing
				if (rightShieldValue > dividedShieldValue)
				{
					//assign it the max value
					rightShieldValue = dividedShieldValue;
				}
			}

			//if reer shield value is less than the max shield value
			if (reerShieldValue < dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::reer);

				//if the value has exceeded the divided shield value after incrementing
				if (reerShieldValue > dividedShieldValue)
				{
					//assign it the max value
					reerShieldValue = dividedShieldValue;
				}
			}

			timer = 0.0f;
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

	//UE_LOG(LogTemp, Warning, TEXT("Source of fire=: %s."), *SourceOfFire.ToString());
	

	//get the direction of the fire 
	FVector direction = ownerActorLocation - SourceOfFire;
	//Get the angle of the directional vector

	//UE_LOG(LogTemp, Warning, TEXT("Direction=: %s."), *direction.ToString());

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
		reerShieldValue -= value;
		if (reerShieldValue <= 0)
		{
			reerShieldValue = 0;
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
		frontShieldValue -= value;
		if (frontShieldValue <= 0)
		{
			frontShieldValue = 0;
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
void UShieldComponent::IncrementShield(int value, ShieldSide side)
{
	//switch statement for shield side
	switch (side)
	{
	//if front
	case ShieldSide::front:
		//increment front shields
		frontShieldValue += value;
		break;
	//if left
	case ShieldSide::left:
		//increment left shields
		leftShieldValue += value;
		break;
	//if right
	case ShieldSide::right:
		//increment right shields
		rightShieldValue += value;
		break;
	//if reer
	case ShieldSide::reer:
		//increment reer shields
		reerShieldValue += value;
		break;
	}
}



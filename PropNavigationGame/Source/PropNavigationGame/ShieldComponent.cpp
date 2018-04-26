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
	m_dividedShieldValue = maxShieldStrength / 4;

	//Set the values of the shields to the equal divided value
	m_reerShieldValue = m_dividedShieldValue;
	m_leftShieldValue = m_dividedShieldValue;
	m_rightShieldValue = m_dividedShieldValue;
	m_frontShieldValue = m_dividedShieldValue;

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
	m_InCombat = inCombat;
}

//Regenerate shield method
//@Calculates shield regeneration values when in and out of combat
void UShieldComponent::RegenerateShields()
{
	//if in combat 
	if (m_InCombat)
	{
		//if the timer hasn't lasted 5 seconds
		if (m_timer < 300)
		{
			//Increment timer
			m_timer++;
		}
		else
		{
			//if front shield value is less than the max shield value
			if (m_frontShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::front);

				//if the value has exceeded the divided shield value after incrementing
				if (m_frontShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_frontShieldValue = m_dividedShieldValue;
				}
			}

			//if left shield value is less than the max shield value
			if (m_leftShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::left);

				//if the value has exceeded the divided shield value after incrementing
				if (m_leftShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_leftShieldValue = m_dividedShieldValue;
				}
			}

			//if right shield value is less than the max shield value
			if (m_rightShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::right);

				//if the value has exceeded the divided shield value after incrementing
				if (m_rightShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_rightShieldValue = m_dividedShieldValue;
				}
			}

			//if reer shield value is less than the max shield value
			if (m_reerShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenInCombatP5, ShieldSide::reer);

				//if the value has exceeded the divided shield value after incrementing
				if (m_reerShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_reerShieldValue = m_dividedShieldValue;
				}
			}

			//reset regen timer
			m_timer = 0.0f;
		}
	}
	//if not in combat
	else if (!m_InCombat)
	{
		//if the timer hasn't lasted 5 seconds
		if (m_timer < 300)
		{
			//Increment Timer
			m_timer++;
		}
		else
		{
			//if front shield value is less than the max shield value
			if (m_frontShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::front);

				//if the value has exceeded the divided shield value after incrementing
				if (m_frontShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_frontShieldValue = m_dividedShieldValue;
				}
			}

			//if left shield value is less than the max shield value
			if (m_leftShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::left);

				//if the value has exceeded the divided shield value after incrementing
				if (m_leftShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_leftShieldValue = m_dividedShieldValue;
				}
			}

			//if right shield value is less than the max shield value
			if (m_rightShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::right);

				//if the value has exceeded the divided shield value after incrementing
				if (m_rightShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_rightShieldValue = m_dividedShieldValue;
				}
			}

			//if reer shield value is less than the max shield value
			if (m_reerShieldValue < m_dividedShieldValue)
			{
				//increment
				IncrementShield(regenOutOfCombatP5, ShieldSide::reer);

				//if the value has exceeded the divided shield value after incrementing
				if (m_reerShieldValue > m_dividedShieldValue)
				{
					//assign it the max value
					m_reerShieldValue = m_dividedShieldValue;
				}
			}

			m_timer = 0.0f;
		}
	}
}

// Called every frame
void UShieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	RegenerateShields();
	shieldStrength = (m_leftShieldValue + m_rightShieldValue + m_reerShieldValue + m_frontShieldValue);
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

	clampedRotation.Yaw += angleOfFire;

	UE_LOG(LogTemp, Warning, TEXT("Clamped Rotation + angleOfFire =: %s."), *clampedRotation.ToString());

	clampedRotation = clampedRotation.Clamp();


	UE_LOG(LogTemp, Warning, TEXT("Clamped Rotation + angleOfFire (clamped) =: %s."), *clampedRotation.ToString());

	//if damage lies on the front angle of the ship (between -45 and 45 degrees)
	if (clampedRotation.Yaw > 315 && clampedRotation.Yaw < 360 || clampedRotation.Yaw > 0  && clampedRotation.Yaw < 45)
	{
		//Front Shield Damage
		m_reerShieldValue -= value;
		if (m_reerShieldValue <= 0)
		{
			m_reerShieldValue = 0;
		}
	}
	//if damage lies on the right angle of the ship (between 45 and 135 degrees
	else if (clampedRotation.Yaw > 45 && clampedRotation.Yaw < 135)
	{
		//Right Broadside Damage
		m_rightShieldValue -= value;
		if (m_rightShieldValue <= 0)
		{
			m_rightShieldValue = 0;
		}
	}
	//if the damage lies on the reer angle of the ship (between 135 and 225 degrees)
	else if (clampedRotation.Yaw > 135 && clampedRotation.Yaw < 225)
	{
		//Reer Damage
		m_frontShieldValue -= value;
		if (m_frontShieldValue <= 0)
		{
			m_frontShieldValue = 0;
		}
	}
	//if the damage lies on the left angle of the ship (between 225 and 315 degrees)
	else if (clampedRotation.Yaw > 225 && clampedRotation.Yaw < 325)
	{
		//Left Broadside Damage
		m_leftShieldValue -= value;
		if (m_leftShieldValue <= 0)
		{
			m_leftShieldValue = 0;
		}
	}

	////if damage lies on the front angle of the ship (between -45 and 45 degrees)
	//if (angleOfFire > 315 + clampedRotation.Pitch && angleOfFire < 360 + clampedRotation.Pitch || angleOfFire > 0 + clampedRotation.Pitch && angleOfFire < 45 + clampedRotation.Pitch)
	//{
	//	//Front Shield Damage
	//	m_reerShieldValue -= value;
	//	if (m_reerShieldValue <= 0)
	//	{
	//		m_reerShieldValue = 0;
	//	}
	//}
	////if damage lies on the right angle of the ship (between 45 and 135 degrees
	//else if (angleOfFire > 45 + clampedRotation.Pitch && angleOfFire < 135 + clampedRotation.Pitch)
	//{
	//	//Right Broadside Damage
	//	m_rightShieldValue -= value;
	//	if (m_rightShieldValue <= 0)
	//	{
	//		m_rightShieldValue = 0;
	//	}
	//}
	////if the damage lies on the reer angle of the ship (between 135 and 225 degrees)
	//else if (angleOfFire > 135 + clampedRotation.Pitch && angleOfFire < 225 + clampedRotation.Pitch)
	//{
	//	//Reer Damage
	//	m_frontShieldValue -= value;
	//	if (m_frontShieldValue <= 0)
	//	{
	//		m_frontShieldValue = 0;
	//	}
	//}
	////if the damage lies on the left angle of the ship (between 225 and 315 degrees)
	//else if (angleOfFire > 225 + clampedRotation.Pitch && angleOfFire < 325 + clampedRotation.Pitch)
	//{
	//	//Left Broadside Damage
	//	m_leftShieldValue -= value;
	//	if (m_leftShieldValue <= 0)
	//	{
	//		m_leftShieldValue = 0;
	//	}
	//}
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
		m_frontShieldValue += value;
		break;
	//if left
	case ShieldSide::left:
		//increment left shields
		m_leftShieldValue += value;
		break;
	//if right
	case ShieldSide::right:
		//increment right shields
		m_rightShieldValue += value;
		break;
	//if reer
	case ShieldSide::reer:
		//increment reer shields
		m_reerShieldValue += value;
		break;
	}
}



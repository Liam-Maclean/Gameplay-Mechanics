// Fill out your copyright notice in the Description page of Project Settings.

#include "ShieldComponent.h"


// Sets default values for this component's properties
UShieldComponent::UShieldComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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
void UShieldComponent::DecrementShield(int value)
{
	//decrease shield value
	shieldStrength -= value;
}

//Increment shield value
void UShieldComponent::IncrementShield(int value)
{
	//Increase shield value
	shieldStrength += value;
}



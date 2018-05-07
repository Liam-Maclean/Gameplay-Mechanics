// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponSlotComponent.h"


// Sets default values for this component's properties
UWeaponSlotComponent::UWeaponSlotComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponSlotComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UWeaponSlotComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UWeaponSlotComponent::InitialiseWeaponSlot(FName * socketName, WeaponDirection weaponDirection)
{
	//Set class structure values
	SetSocketName(socketName);
	SetWeaponDirection(weaponDirection);

	//search if socket name has keywords in it (phaser, turret, torpedo etc)
}


void UWeaponSlotComponent::FireWeaponInSlot(ABaseShip* targetShip)
{
	m_targetShip = targetShip;
	
	if (m_targetShip)
	{
		if (weaponInSlot)
		{
			weaponInSlot->FireWeapon(targetShip);
		}
		else
		{
			//No weapon in slot (nullptr)
		}
	}
	else
	{
		//No ship targetted (nullptr)
	}
}

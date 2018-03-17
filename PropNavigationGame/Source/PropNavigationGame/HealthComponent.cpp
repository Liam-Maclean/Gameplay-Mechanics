// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...	
}

//returns shield strength
int UHealthComponent::GetHealthStrength()
{
	return healthStrength;
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	//if (healthStrength <= 0)
	//{
	//	this->SetActive(false);
	//}
	// ...
}

//Decrease health method by passed value
void UHealthComponent::DecrementHealth(int value)
{
	healthStrength -= value;
}

//increase health method by passed value
void UHealthComponent::IncrementHealth(int value)
{
	healthStrength += value;
}



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShieldComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UShieldComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShieldComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float timer;


	void ToggleInCombat(bool inCombat);
	bool InCombat;

	//Return shield Strength
	int GetShieldStrength();

	//Decrease Shield Strength function
	void DecrementShield(int value);

	//Increase Shield Strength function
	void IncrementShield(int value);

	//Regenerate Shield Strength
	void RegenerateShields();

	//Regen out of combat per second
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenOutOfCombatP5;

	//Regen of shield in combat
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenInCombatP5;

	//directional shield values (front)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	int frontShieldValue;

	//directional shield values (left)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	int leftShieldValue;

	//directional shield values (right)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	int rightShieldValue;

	//directional shield values (reer)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	int reerShieldValue;

	//Total Shield Strength
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	int shieldStrength = 300;

	UPROPERTY(EditAnywhere, Category = "Shield Values|Max Values")
	int maxShieldStrength = 500;

	
};

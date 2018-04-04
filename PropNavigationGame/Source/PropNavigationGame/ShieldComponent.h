// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShieldComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UShieldComponent : public UActorComponent
{
	GENERATED_BODY()
	
	enum ShieldSide
	{
		front,
		left,
		right,
		reer
	};

public:	
	// Sets default values for this component's properties
	UShieldComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//timer for checking how long in combat for 
	float timer;

	//Method to toggle if in combat or not
	void ToggleInCombat(bool inCombat);

	//bool to check if in combat
	bool InCombat;

	//Return shield Strength
	int GetShieldStrength();
	float GetShieldPercentage();
	
	//Regen out of combat per second
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenOutOfCombatP5 = 22.0f;

	//Regen of shield in combat
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenInCombatP5 = 5.0f;

	//directional shield values (front)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	float frontShieldValue;

	//directional shield values (left)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	float leftShieldValue;

	//directional shield values (right)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	float rightShieldValue;

	//directional shield values (reer)
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
	float reerShieldValue;

	//Total Shield Strength
	UPROPERTY(EditAnywhere, Category = "Shield Values|Strength")
		float shieldStrength = 200;

	//Max total shield strength
	UPROPERTY(EditAnywhere, Category = "Shield Values|Max Values")
	float maxShieldStrength = 1000;

	//divided shield value (max shield value / 4)
	float dividedShieldValue = 0.0f;



	//Returns the front shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetFrontShieldStrength()
	{
		return frontShieldValue / dividedShieldValue;
	}

	//Returns the left shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetLeftShieldStrength()
	{
		return leftShieldValue / dividedShieldValue;
	}

	//Returns the right shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetRightShieldStrength()
	{
		return rightShieldValue / dividedShieldValue;
	}

	//Returns the reer shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetReerShieldStrength()
	{
		return reerShieldValue / dividedShieldValue;
	}

	//Decrease Shield Strength function
	void DecrementShield(int value, FVector SourceOfFire);

	//Increase Shield Strength function
	void IncrementShield(int value, ShieldSide side);

	//Regenerate Shield Strength
	void RegenerateShields();

	
};

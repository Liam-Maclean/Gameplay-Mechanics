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

private:
	//directional shield values (front)
	float m_frontShieldValue;

	//directional shield values (left)
	float m_leftShieldValue;

	//directional shield values (right)
	float m_rightShieldValue;

	//directional shield values (reer)
	float m_reerShieldValue;

	//timer for checking how long in combat for 
	float m_timer;

	//bool to check if in combat
	bool m_InCombat;

	//divided shield value (max shield value / 4)
	float m_dividedShieldValue = 0.0f;

	//Regenerate Shield Strength
	void RegenerateShields();
public:	
	// Sets default values for this component's properties
	UShieldComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Return shield Strength
	int GetShieldStrength();
	float GetShieldPercentage();
	
	//Method to toggle if in combat or not
	void ToggleInCombat(bool inCombat);

	//Decrease Shield Strength function
	void DecrementShield(int value, FVector SourceOfFire);

	//Increase Shield Strength function
	void IncrementShield(int value, ShieldSide side);

	//Regen out of combat per second
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenOutOfCombatP5 = 22.0f;

	//Regen of shield in combat
	UPROPERTY(EditAnywhere, Category = "Shield Values|Regeneration")
	float regenInCombatP5 = 5.0f;

	//Total Shield Strength
	UPROPERTY(VisibleAnywhere, Category = "Shield Values|Strength")
	float totalShieldStrength;

	//Max total shield strength
	UPROPERTY(EditAnywhere, Category = "Shield Values|Max Values")
	float maxShieldStrength = 1000;

	//Returns the front shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetFrontShieldStrength()
	{
		return m_frontShieldValue / m_dividedShieldValue;
	}

	//Returns the left shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetLeftShieldStrength()
	{
		return m_leftShieldValue / m_dividedShieldValue;
	}

	//Returns the right shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetRightShieldStrength()
	{
		return m_rightShieldValue / m_dividedShieldValue;
	}

	//Returns the reer shield strength for HUD blueprint
	UFUNCTION(BlueprintPure, Category = "Shield Values")
	float GetReerShieldStrength()
	{
		return m_reerShieldValue / m_dividedShieldValue;
	}
};

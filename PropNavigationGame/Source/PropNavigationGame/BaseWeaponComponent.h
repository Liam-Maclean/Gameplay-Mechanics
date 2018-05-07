// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseShip.h"
#include "BaseWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UBaseWeaponComponent : public UActorComponent
{
	
	GENERATED_BODY()
		
	enum DamageType
	{
		damageOverTime,
		instant
	};

public:	
	// Sets default values for this component's properties
	UBaseWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	DamageType GetDamageType()
	{
		return m_damageType;
	}

	void SetDamageType(DamageType damageType)
	{
		m_damageType = damageType;
	}

	float GetAngleOfFire()
	{
		return m_angleOfFire;
	}

	void SetAngleOfFire(float angleOfFire)
	{
		m_angleOfFire = angleOfFire;
	}

	float GetDamageValue()
	{
		return m_damageValue;
	}

	void SetDamageValue(float damageValue)
	{
		m_damageValue = damageValue;
	}
	
	virtual void FireWeapon(ABaseShip* targetShip);

private:
	DamageType m_damageType;
	ABaseShip* m_targetShip;
	float m_angleOfFire;
	float m_damageValue;
};

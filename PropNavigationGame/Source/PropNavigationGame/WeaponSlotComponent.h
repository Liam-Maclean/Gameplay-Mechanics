// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeaponComponent.h"
#include "BaseShip.h"
#include "WeaponSlotComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UWeaponSlotComponent : public UActorComponent
{
	GENERATED_BODY()
	enum WeaponDirection
	{
		front,
		reer
	};
public:	
	// Sets default values for this component's properties
	UWeaponSlotComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitialiseWeaponSlot(FName* socketName, WeaponDirection weaponDirection);

	//Get (weapon component)
	UBaseWeaponComponent* GetWeaponComponent()
	{
		return weaponInSlot;
	}

	//Set (weapon component)
	void SetWeaponComponent(UBaseWeaponComponent* weaponComponent)
	{
		weaponInSlot = weaponComponent;
	}

	//Get (Weapon Direction)
	WeaponDirection GetWeaponDirection()
	{
		return weaponDirection;
	}

	//Set (Weapon Direction)
	void SetWeaponDirection(WeaponDirection weaponDir)
	{
		weaponDirection = weaponDir;
	}

	FName* GetSocketName()
	{
		return m_socketName;
	}

	void SetSocketName(FName* socketName)
	{
		m_socketName = socketName;
	}

	void FireWeaponInSlot(ABaseShip* targetShip);

private:
	UBaseWeaponComponent* weaponInSlot;
	WeaponDirection weaponDirection;
	FName* m_socketName;
	ABaseShip* m_targetShip;

};

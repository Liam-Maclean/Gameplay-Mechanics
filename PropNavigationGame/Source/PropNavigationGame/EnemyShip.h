// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ShieldComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "HealthComponent.h"
#include "EnemyShip.generated.h"

UCLASS()
class PROPNAVIGATIONGAME_API AEnemyShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//private functions 
	//function to set in combat 
	void SetInCombat(bool inCombat);

	//function to increment combat timer and check state of combat
	void IncrementInCombatTimer();

	float m_timer;
	bool m_InCombat;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);


	void ApplyDamageTaken(int value, FVector location);

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* skeleMesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* sphereMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere)
	UShieldComponent* shieldComponent;

	UPROPERTY(EditAnywhere)
	UHealthComponent* healthComponent;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "ShieldComponent.h"
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float timer;
	bool InCombat;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
	void ApplyDamageTaken(int value, FVector location);
	void SetInCombat(bool inCombat);
	void IncrementInCombatTimer();

	void ScaleShields();
	FVector StartScale;


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* frontShield;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* leftBroadSideShield;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* rightBroadSideShield;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* reerShield;

	UPROPERTY(EditAnywhere)
	USphereComponent* sphereMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere)
	UShieldComponent* shieldComponent;

	UPROPERTY(EditAnywhere)
	UHealthComponent* healthComponent;
	
};

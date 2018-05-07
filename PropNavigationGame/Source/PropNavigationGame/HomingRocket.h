// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "HomingRocket.generated.h"

UCLASS()
class PROPNAVIGATIONGAME_API AHomingRocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHomingRocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InitialiseRocket(AActor* target);
	void Seek();


	AActor* targetActor;
	TArray<AActor*> FoundActors;

	FVector thisPreviousActorLocation, thisActorLocation;
	FVector targetPreviousActorLocation, targetActorLocation;
	FVector PreviousLos, LoS;
	FVector LoSDelta;
	float LoSRate;
	UStaticMeshComponent* staticMesh;
	USphereComponent* sphereMesh;


	float NavigationalConstant = 3.0f;
	FVector Target;
};

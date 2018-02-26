// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Rotator.h"
#include "FiringComponent.generated.h"
using namespace std;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UFiringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFiringComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitialiseComponent();
	void FireMissile();
	TArray<FName> names;
	FRotator spawnRotation;
	FVector spawningLocation;
	TArray<USkeletalMeshSocket*> sockets;
	USkeletalMeshComponent* skele_mesh;
	
};

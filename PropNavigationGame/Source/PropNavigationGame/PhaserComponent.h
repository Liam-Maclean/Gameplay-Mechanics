// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhaserComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROPNAVIGATIONGAME_API UPhaserComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPhaserComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* phaserEffect;

	TArray<FName> names;
	FVector spawningLocation;
	TArray<USkeletalMeshSocket*> sockets;
	USkeletalMeshComponent* skele_mesh;

	void InitialiseComponent(float damageOverDurationValue, float coolDownInSeconds);
	void FirePhasers(FVector Target);
		
private:
	float m_damageOverDurationValue;
	float m_coolDownInSeconds;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

UCLASS()
class PROPNAVIGATIONGAME_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ImpulseForwardBack(float axis);
	void TurnRightLeft(float axis);

	UPROPERTY(EditAnywhere)
	float maxForwardSpeed;

	UPROPERTY(EditAnywhere)
	float maxTurningSpeed;

	float newForwardVelocity;
	float turningSpeed;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;
	
	UCameraComponent* camera;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;
};

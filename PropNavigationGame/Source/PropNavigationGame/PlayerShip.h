// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FiringComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "PhaserComponent.h"
#include "ShieldComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

UCLASS()
class PROPNAVIGATIONGAME_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:

	enum ImpulseSpeed
	{
		None = 0,
		OneQuarter = 1,
		Half = 2,
		ThreeQuarter = 3,
		Full = 4
	};

	// Sets default values for this pawn's properties
	APlayerShip();
private:

	UFUNCTION(BlueprintPure, Category = "Target functions")
		int GetTargetShieldStrength();

	UFUNCTION(BlueprintPure, Category = "Target functions")
		int GetTargetHealthStrength();

	UFUNCTION(BlueprintPure, Category = "Target functions")
		FName GetTargetName();

	UFUNCTION(BlueprintPure, Category = "Target functions")
		FName GetImpulseSpeed();

	UFUNCTION(BlueprintPure, Category = "Personal Attributes")
		float GetShieldPercentage();

	UFUNCTION(BlueprintPure, Category = "Personal Attributes")
		float GetTargetShieldPercentage();

	UPROPERTY(EditAnywhere, Category = "Shooting|Shooting Speed")
		float timeBetweenShots = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Movement|Rotation and turning")
		float maxTurningAngle = 40.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Acceleration and deceleration")
		float maxForwardSpeed;

	UPROPERTY(EditAnywhere, Category = "Movement|Rotation and turning")
		float maxTurningSpeed;

	UPROPERTY(EditAnywhere, category = "Camera|Zoom")
		float minCameraZoom;

	UPROPERTY(EditAnywhere, category = "Camera|Zoom")
		float maxCameraZoom;

	UPROPERTY(EditAnywhere, category = "Camera|Zoom")
		float zoomSensitivity;


	FVector2D mouseInput;
	float currentMaxImpulseSpeed;
	float newForwardVelocity;
	float turningSpeed;
	float turningSpeedUpDown;

	TArray<FName> names;

	//impulse speed, initialise as none so we're not moving
	ImpulseSpeed impulseSpeed = None;
	AEnemyShip* TargetedActor;

	void IncreaseImpulseSpeed();
	void DecreaseImpulseSpeed();
	void ImpulseForwardBack(float axis);
	void TurnRightLeft(float axis);
	void MousePitch(float axis);
	void MouseYaw(float axis);
	void FirePhasers();
	void FireMissile();
	void ZoomCameraOut();
	void ZoomCameraIn();
	void CalculateCameraTurningWithMouse();
	void CalculateShipMovement();
	void CalculateShipTurningAngles();
	void TurnShipUpDown(float axis);
	void SendSocketsToFireComponents();

	void TargetActorWithMouse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure, Category = "Target functions")
	AActor* GetTargetActor()
	{
		return TargetedActor;
	}


	USceneComponent* sceneRoot;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* springArm;

	UCameraComponent* camera;

	UShieldComponent* shieldComponent;

	UPROPERTY(EditAnywhere)
	TArray<UPhaserComponent*> phaserComponent;

	UFiringComponent* firingComponent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* skeleMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;
};

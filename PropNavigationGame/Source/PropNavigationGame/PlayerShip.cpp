// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShip.h"
#include "Components/inputComponent.h"
// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initialise components in hierarchy
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	//set root component
	RootComponent = mesh;

	//set up spring arm attachment for camera
	springArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	springArm->TargetArmLength = 350.0f;
	springArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));

	//attach camera to spring arm
	camera->AttachToComponent(springArm, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//auto possess player so we can use player functions
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator newTurnAngle = GetActorRotation();
	FVector newActorPosition = GetActorLocation();


	//if the turning speed is to the right
	if (turningSpeed > 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed;

		//if the "roll" of the ship is not at it's max angle
		if (newTurnAngle.Roll < maxTurningAngle)
		{
			//start turning right
			newTurnAngle.Roll += turningSpeed;
		}
	}
	//if the turning speed is to the left 
	else if (turningSpeed < 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed;

		//if the "roll" of the ship is not at it's negative max angle
		if (newTurnAngle.Roll > (maxTurningAngle*-1))
		{
			//start turning left
			newTurnAngle.Roll += turningSpeed;
		}
	}
	
	//if the turn speed hasn't changed
	if (turningSpeed == 0.0f)
	{
		//if the roll angle is less than neutral
		if (newTurnAngle.Roll < 0.0f)
		{
			//add untill neutral (0 degrees)
			newTurnAngle.Roll += 2.0f;
		}
		//if roll angle is more than neutral
		if (newTurnAngle.Roll > 0.0f)
		{
			//remove untill neutral (0 degrees)
			newTurnAngle.Roll -= 2.0f;
		}
	}


	//move the actor forward using the actors' forward vector and multiplying by speed
	newActorPosition += (GetActorForwardVector() * newForwardVelocity);

	//set the actors rotation and position
	SetActorRotation(newTurnAngle);
	SetActorRelativeLocation(newActorPosition);




	//if the velocity is small enough for the player not to notice
	if (newForwardVelocity <= 0.1f && newForwardVelocity >= -0.1f)
	{
		//kill velocity
		newForwardVelocity = 0.0f;
	}
	//if the player's ship is still moving forward
	else if (newForwardVelocity > 0.0f)
	{
		//Decrease innertia
		newForwardVelocity -= 0.01f;
	}
	//if the players ship is still moving backwards
	else if (newForwardVelocity < 0.0f)
	{
		//Decrease innertia
		newForwardVelocity += 0.01f;
	}

}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//bind functions to input keys for movement
	PlayerInputComponent->BindAxis("ImpulseMove", this, &APlayerShip::ImpulseForwardBack);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerShip::TurnRightLeft);
}

void APlayerShip::ImpulseForwardBack(float axis)
{
	//increase forward velocity
	newForwardVelocity += axis;

	//clamp forward speed with max terminal speed
	if (newForwardVelocity > 0.0f)
	{
		if (newForwardVelocity >= maxForwardSpeed)
		{
			newForwardVelocity = maxForwardSpeed;
		}
	}
}

void APlayerShip::TurnRightLeft(float axis)
{
	turningSpeed = axis;

	//clamp turning speed with max turning speed;
	//if (turningSpeed >= maxTurningSpeed)
	//{
	//	turningSpeed = maxTurningSpeed;
	//}
}



// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShip.h"
#include "Components/inputComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initialise components in hierarchy
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArm"));
	sceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	firingComponent = CreateDefaultSubobject<UFiringComponent>(TEXT("FiringComponent"));
	phaserComponent = CreateDefaultSubobject<UPhaserComponent>(TEXT("PhaserComponent"));
	skeleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeleton Mesh"));
	particleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));

	//set root component
	RootComponent =  mesh;

	//set up spring arm attachment for camera
	springArm->AttachToComponent(skeleMesh, FAttachmentTransformRules::KeepWorldTransform);
	springArm->TargetArmLength = 400.0f;
	springArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));

	FRotator StartRotation = FRotator(0, 0, -180.0f);
	skeleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	skeleMesh->SetRelativeRotation(StartRotation);

	//attach camera to spring arm
	camera->AttachToComponent(springArm, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//auto possess player so we can use player functions
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	firingComponent->InitialiseComponent();
	
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator newTurnAngle = skeleMesh->GetComponentRotation();
	FVector newActorPosition = skeleMesh->GetComponentLocation();

	if (timeBetweenShots < 0.5f)
	{
		timeBetweenShots += DeltaTime;
	}


	//if the turning speed is to the right
	if (turningSpeed > 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed;


		//if the "roll" of the ship is not at it's negative max angle
		if (newTurnAngle.Roll >(maxTurningAngle*-1))
		{
			//start turning left
			newTurnAngle.Roll -= (turningSpeed * 0.8f);
		}
		
	}
	//if the turning speed is to the left 
	else if (turningSpeed < 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed;


		//if the "roll" of the ship is not at it's max angle
		if (newTurnAngle.Roll < maxTurningAngle)
		{
			//start turning right
			newTurnAngle.Roll -= (turningSpeed * 0.8f);
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
	newActorPosition += (-skeleMesh->GetForwardVector() * newForwardVelocity);


	
	//set the actors rotation and position
	skeleMesh->SetWorldRotation(newTurnAngle);
	skeleMesh->SetWorldLocation(newActorPosition);

	//SetActorLocation(newActorPosition);



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

	FRotator newPitch = springArm->GetComponentRotation();
	newPitch.Pitch = FMath::Clamp(newPitch.Pitch + mouseInput.Y, -180.0f, 180.0f);
	newPitch.Yaw = FMath::Clamp(newPitch.Yaw + mouseInput.X, -180.0f, 180.0f);
	newPitch.Roll = 0.0f;
	springArm->SetWorldRotation(newPitch);


}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//bind functions to input keys for movement
	PlayerInputComponent->BindAxis("ImpulseMove", this, &APlayerShip::ImpulseForwardBack);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerShip::TurnRightLeft);
	PlayerInputComponent->BindAction("FireMissile", IE_Pressed, this, &APlayerShip::FireMissile);
	PlayerInputComponent->BindAxis("MousePitch", this, &APlayerShip::MousePitch);
	PlayerInputComponent->BindAxis("MouseYaw", this, &APlayerShip::MouseYaw);
	PlayerInputComponent->BindAction("FirePhasers", IE_Pressed, this, &APlayerShip::FirePhasers);
}

void APlayerShip::FirePhasers()
{
	if (Controller != NULL)
	{
		//get the mouse world position + direction
		FVector mouseLocation, mouseDirection;
		APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
		playerController->DeprojectMousePositionToWorld(mouseLocation, mouseDirection);
	
		//normalise it and multiply it by a distance
		mouseDirection.Normalize();
		mouseDirection * 1000.0f;

		//do a raycast using mouse location and cirection
		FHitResult hit(ForceInit);
		playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, hit);

		FString TraceString;

		if (hit.GetActor() != nullptr)
		{
			//TraceString += FString::Printf(TEXT("Trace Actor %s."), *hit.GetActor()->GetName());
			phaserComponent->FirePhasers(hit.GetActor()->GetActorLocation());
			UE_LOG(LogTemp, Warning, TEXT("Trace Actor %s."), *hit.GetActor()->GetName());
		}

		
		//if (GetWorld()->LineTraceSingleByObjectType(hit, mouseLocation, mouseDirection, FCollisionObjectQueryParams::AllObjects))
		//{
		//	if (hit.GetActor()->Tags.Find("Target"))
		//	{
		//		phaserComponent->FirePhasers(hit.GetActor()->GetActorLocation());
		//		UE_LOG(LogTemp, Warning, TEXT("Hit something"));
		//	}
		//}

		//if the actor hit contained the tag targettable
		//if (hit.GetActor())
		//{
			//Create Particle system for phasers
			
		//}
	}
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

void APlayerShip::MousePitch(float axis)
{
	mouseInput.Y = axis;
}

void APlayerShip::MouseYaw(float axis)
{
	mouseInput.X = axis;
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

void APlayerShip::FireMissile()
{
	if (timeBetweenShots >= 0.5f)
	{
		firingComponent->FireMissile();
	}
}



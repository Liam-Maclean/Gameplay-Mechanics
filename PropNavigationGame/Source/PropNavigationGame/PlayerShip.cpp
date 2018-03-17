// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShip.h"
#include "Components/inputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/HUD.h"
#include "ShieldComponent.h"
#include "HealthComponent.h"
#include "SpaceHUD.h"
#include "ConstructorHelpers.h"

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
	skeleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeleton Mesh"));

	//set root component
	RootComponent =  mesh;

	//set up spring arm attachment for camera
	springArm->AttachToComponent(skeleMesh, FAttachmentTransformRules::KeepWorldTransform);
	springArm->TargetArmLength = 400.0f;
	springArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));
	springArm->bAbsoluteRotation = true;

	//Initialise skeletal mesh to be the correct way around
	FRotator StartRotation = FRotator(0, 0, -180.0f);
	skeleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	skeleMesh->SetRelativeRotation(StartRotation);

	//attach camera to spring arm
	camera->AttachToComponent(springArm, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//auto possess player so we can use player functions
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}



//returns the shield strength of the target object
int APlayerShip::GetTargetShieldStrength()
{
	//if a targetted actor exists 
	if (TargetedActor)
	{
		//if the targetted actor has a shield component 
		UShieldComponent* shields = (UShieldComponent*)TargetedActor->GetComponentByClass(UShieldComponent::StaticClass());
		if (shields != nullptr)
		{
			//return the actors shield component value
			return shields->GetShieldStrength();
		}
	}
	//if a targetted actor does not exist
	else
	{
		//return a value of 0
		return 0;
	}

	//return a value of 0 (Default)
	return 0;
}

//returns the health of the target object
int APlayerShip::GetTargetHealthStrength()
{
	//if a targetted actor exists
	if (TargetedActor)
	{
		//if the targetted actor has a health component attached 
		UHealthComponent* health = (UHealthComponent*)TargetedActor->GetComponentByClass(UShieldComponent::StaticClass());
		if (health != nullptr)
		{
			//return the targets health values 
			return health->GetHealthStrength();
		}
	}
	//if a targetted actor does not exist
	else
	{
		//return a value of 0
		return 0;
	}

	//return a value of 0  (Default)
	return 0;
}

//Returns the name of the actor targeted
FName APlayerShip::GetTargetName()
{
	//if a targetted actor exists
	if (TargetedActor)
	{
		//return it's name
		return TargetedActor->GetFName();
	}
	//if a targetted actor doesn't exist
	else
	{
		//return that no actor was found or targetted
		return FName("No actor found");
	}
	//return that no actor was found or targetted (Default)
	return FName("No actor found");
}

//Returns a string of the impulse speed currently active
FName APlayerShip::GetImpulseSpeed()
{
	switch (impulseSpeed)
	{
		//if the impulse speed is set to none
	case ImpulseSpeed::None:
		return FName("No Impulse");
		break;
		//if the impulse speed is set to one quarter
	case ImpulseSpeed::OneQuarter:
		return FName("One Quarter Impulse");
		break;
		//if the impulse speed is set to a half
	case ImpulseSpeed::Half:
		return FName("Half Impulse");
		break;
		//if the impulse speed is set to three quarters 
	case ImpulseSpeed::ThreeQuarter:
		return FName("Three Quarter Impulse");
		break;
		//if the impulse speed is set to full
	case ImpulseSpeed::Full:
		return FName("Full Impulse");
		break;
	default:
		return FName("No Impulse");
		break;
	}
}

//Sets up the fire components with the sockets to fire from
void APlayerShip::SendSocketsToFireComponents()
{
	//if the skeletal mesh is initialised properly
	if (skeleMesh)
	{
		//get all the socket names from the mesh
		names = skeleMesh->GetAllSocketNames();
		UE_LOG(LogTemp, Warning, TEXT("Doesn't Contain: %f."), names.Num());

		//for every name gathered
		for (int i = 0; i < names.Num(); i++)
		{
			//check the name contains the substring "phaser", if so
			FString name = names[i].ToString();
			if (name.Contains("Phaser"))
			{
				//Dynamically create a new component called phaser component
				UPhaserComponent* createdComp = NewObject<UPhaserComponent>(this);// ");// NewObject<UPhaserComponent>(this, "Phaser");
				if (createdComp)
				{
					//Register the component (because we're creating it dynamically it must be registered)
					createdComp->RegisterComponent();
					
					//initialise the component, handing it the skeletal mesh, the name of the socket and a damage value for the phaser bank
					createdComp->InitialiseComponent(100, 1, names[i], skeleMesh);

					//add the phaser component to the list of phaser components
					phaserComponent.Add(createdComp);
				}
				UE_LOG(LogTemp, Warning, TEXT("Targeted Actor: %s."), *names[i].ToString());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Doesn't Contain: %s."), *names[i].ToString());
			}
		}
	}
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	SendSocketsToFireComponents();
	firingComponent->InitialiseComponent();
	//phaserComponent->InitialiseComponent(100, 1);
	APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();
	playerController->bShowMouseCursor = true;
	playerController->bEnableClickEvents = true;

}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timeBetweenShots < 0.5f)
	{
		timeBetweenShots += DeltaTime;
	}

	//seperated logic in different methods (for cleanliness)
	CalculateShipTurningAngles();
	CalculateShipMovement();
	CalculateCameraTurningWithMouse();

}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//bind functions to input keys for movement
	PlayerInputComponent->BindAxis("ImpulseMove", this, &APlayerShip::ImpulseForwardBack);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerShip::TurnRightLeft);
	PlayerInputComponent->BindAxis("TurnShipUpDown", this, &APlayerShip::TurnShipUpDown);
	PlayerInputComponent->BindAction("FireMissile", IE_Pressed, this, &APlayerShip::FireMissile);
	PlayerInputComponent->BindAxis("MousePitch", this, &APlayerShip::MousePitch);
	PlayerInputComponent->BindAxis("MouseYaw", this, &APlayerShip::MouseYaw);
	PlayerInputComponent->BindAction("FirePhasers", IE_Pressed, this, &APlayerShip::FirePhasers);
	PlayerInputComponent->BindAction("Target", IE_Pressed, this, &APlayerShip::TargetActorWithMouse);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &APlayerShip::ZoomCameraIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &APlayerShip::ZoomCameraOut);
	PlayerInputComponent->BindAction("IncreaseImpulseSpeed", IE_Pressed, this, &APlayerShip::IncreaseImpulseSpeed);
	PlayerInputComponent->BindAction("DecreaseImpulseSpeed", IE_Pressed, this, &APlayerShip::DecreaseImpulseSpeed);
}

//Calculates how the spring arm will turn with mouse
//-Contains code to rotate spring arm with camera attached
void APlayerShip::CalculateCameraTurningWithMouse()
{
	FRotator newPitch = springArm->GetComponentRotation();
	newPitch.Pitch = FMath::Clamp(newPitch.Pitch + mouseInput.Y, -180.0f, 180.0f);
	newPitch.Yaw = FMath::Clamp(newPitch.Yaw + mouseInput.X, -180.0f, 180.0f);
	newPitch.Roll = 0.0f;
	springArm->SetWorldRotation(newPitch);
}

//Calculates the ships movement in game
//-Contains calculations for impulse speed settings
//-Contains calculations for increasing and decreasing between impulse settings
//-Contains setting world Position for skeletal mesh
void APlayerShip::CalculateShipMovement()
{
	//Get the skeletal mesh's location in world space
	FVector newActorPosition = skeleMesh->GetComponentLocation();

	//Do a statement for changing impulse speed
	switch (impulseSpeed)
	{
		//if the impulse speed is set to none
	case ImpulseSpeed::None:
		//set the max current impulse speed to 0 (we will slow to a stop)
		currentMaxImpulseSpeed = 0.0f;
		break;
		//if the impulse speed is set to one quarter
	case ImpulseSpeed::OneQuarter:
		//Set the max current impulse speed to a quarter of the max speed we can travel at
		currentMaxImpulseSpeed = (maxForwardSpeed / 4);
		break;
		//if the impulse speed is set to a half
	case ImpulseSpeed::Half:
		//Set the max current impulse speed to one half of the max speed we can travel at 
		currentMaxImpulseSpeed = (maxForwardSpeed / 2);
		break;
		//if the impulse speed is set to three quarters 
	case ImpulseSpeed::ThreeQuarter:
		//Set the max current impulse speed to three quarters of the max speed we can travel at
		currentMaxImpulseSpeed = ((maxForwardSpeed / 4) * 3);
		break;
		//if the impulse speed is set to full
	case ImpulseSpeed::Full:
		//Set the max current impulse speed to the max speed we can travel at 
		currentMaxImpulseSpeed = maxForwardSpeed;
		break;
	default:
		break;
	}

	//if the velocity is close enough to the max impulse speed for this setting
	if (newForwardVelocity <= currentMaxImpulseSpeed + 0.1f && newForwardVelocity >= currentMaxImpulseSpeed - 0.1f)
	{
		//manually correct impulse speed 
		newForwardVelocity = currentMaxImpulseSpeed;
	}
	//if the player's ship has exceeded the max impulse speed for this setting
	if (newForwardVelocity > currentMaxImpulseSpeed)
	{
		//Decrease forward velocity
		newForwardVelocity -= 0.01f;
	}
	//if the players ship has not reached max impulse speed for this impulse setting
	else if (newForwardVelocity < currentMaxImpulseSpeed)
	{
		//Increase forward velocity
		newForwardVelocity += 0.01f;
	}


	//move the actor forward using the actors' forward vector and multiplying by speed
	newActorPosition += (-skeleMesh->GetForwardVector() * newForwardVelocity);

	//set the actors rotation and position
	skeleMesh->SetWorldLocation(newActorPosition);
}

//Calculates the ships rotation angles in game
//-Contains calculations for turning the ship
//-Contains calculations for "Rolling" the ship while turning
//-Contains calculations for turning the ship "up and down"
void APlayerShip::CalculateShipTurningAngles()
{
	FRotator newTurnAngle = skeleMesh->GetComponentRotation();

	//if the turning speed is to the right
	if (turningSpeed > 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed * 0.5f;

		if (newForwardVelocity > 0.0f)
		{
			//if the "roll" of the ship is not at it's negative max angle
			if (newTurnAngle.Roll > (maxTurningAngle*-1))
			{
				//start turning left
				newTurnAngle.Roll -= (turningSpeed * 0.6f);
			}
		}

	}
	//if the turning speed is to the left 
	else if (turningSpeed < 0.0f)
	{
		//add the turning speed angle
		newTurnAngle.Yaw += turningSpeed * 0.5f;
		if (newForwardVelocity > 0.0f)
		{
			//if the "roll" of the ship is not at it's max angle
			if (newTurnAngle.Roll < maxTurningAngle)
			{
				//start turning right
				newTurnAngle.Roll -= (turningSpeed * 0.6f);
			}
		}
	}

	//if we are turning up
	if (turningSpeedUpDown > 0.0f)
	{
		//if the pithch hasn't hit the max turn angle for pitch turning
		if (newTurnAngle.Pitch < 30.0f)
		{
			//add the turn angle on
			newTurnAngle.Pitch += turningSpeedUpDown * 0.5f;
		}
	}
	//if we are turning down
	else if (turningSpeedUpDown < 0.0f)
	{
		//if the pitch hasn't hit the min turn angle for pitch turning
		if (newTurnAngle.Pitch > -30.0f)
		{
			//add the turn angle on
			newTurnAngle.Pitch += turningSpeedUpDown * 0.5f;
		}
	}

	//if the turn speed hasn't changed
	if (turningSpeed == 0.0f)
	{
		//if the roll angle is less than neutral
		if (newTurnAngle.Roll < 0.0f)
		{
			//add untill neutral (0 degrees)
			newTurnAngle.Roll += 0.5f;
		}
		//if roll angle is more than neutral
		if (newTurnAngle.Roll > 0.0f)
		{
			//remove untill neutral (0 degrees)
			newTurnAngle.Roll -= 0.5f;
		}
	}

	//Set the world rotation of the mesh 
	skeleMesh->SetWorldRotation(newTurnAngle);
}

//Target an actor in the scene with the mouse
void APlayerShip::TargetActorWithMouse()
{
	//if a controller exists
	if (Controller != NULL)
	{
		//get the player controller
		APlayerController* playerController = (APlayerController*)GetWorld()->GetFirstPlayerController();

		//do a raycast using mouse location and cirection
		FHitResult hit(ForceInit);
		playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, hit);
		ASpaceHUD* hud = (ASpaceHUD*)playerController->GetHUD();
		
		
		FString TraceString;

		//if there was a target hit by the mouse
		if (hit.GetActor() != nullptr)
		{
			//if the target actor is targetable
			if (hit.GetActor()->Tags.Find("Targetable") != INDEX_NONE)
			{
				//contain that targetted actor
				TargetedActor = (AEnemyShip*)hit.GetActor();
				UE_LOG(LogTemp, Warning, TEXT("Targeted Actor: %s."), *hit.GetActor()->GetName());
			}
		}
		//if mouse has not collided with anything
		else if (hit.GetActor() == nullptr)
		{
			//untarget actor
			TargetedActor = nullptr;
		}
	}
}

//Fire phasers at the targetted actor
void APlayerShip::FirePhasers()
{
	//if a targetted actor exists
	if (TargetedActor)
	{
		//TraceString += FString::Printf(TEXT("Trace Actor %s."), *hit.GetActor()->GetName());
		for (int i = 0; i < phaserComponent.Num(); i++)
		{
			phaserComponent[i]->FirePhasers(TargetedActor);
		}

		UE_LOG(LogTemp, Warning, TEXT("Trace Actor %s."), *TargetedActor->GetName());
	}
	//if there is no actor targetted
	else if (!TargetedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO ACTOR TARGETED"));
	}
}

//fires missiles from the firing component
void APlayerShip::FireMissile()
{
	if (timeBetweenShots >= 0.5f)
	{
		firingComponent->FireMissile();
	}
}

//mouse pitch controlled by mouse position (rotates camera in pitch axis)
void APlayerShip::MousePitch(float axis)
{
	mouseInput.Y = axis;
}

//mouse yaw controlled by mouse position (rotates camera in yaw axis)
void APlayerShip::MouseYaw(float axis)
{
	mouseInput.X = axis;
}

//Camera zoom in with mouse wheel up
void APlayerShip::ZoomCameraIn()
{
	//if the camera hasn't reached the minimum zoom location
	if (springArm->TargetArmLength > minCameraZoom)
	{
		//zoom in
		springArm->TargetArmLength -= zoomSensitivity;
	}
}

//Camera zoom out with mouse wheel down
void APlayerShip::ZoomCameraOut()
{
	//if the camera hasn't reached the maximum camera zoom
	if (springArm->TargetArmLength < maxCameraZoom)
	{
		//zoom out
		springArm->TargetArmLength += zoomSensitivity;
	}

}

//Increase the impulse speed we are currently going at 
void APlayerShip::IncreaseImpulseSpeed()
{
	//if we're not at full speed
	if (impulseSpeed != ImpulseSpeed::Full)
	{
		//cast to an int and increment the value of the enum
		int impulse = static_cast<int>(impulseSpeed) + 1;
		impulseSpeed = static_cast<ImpulseSpeed>(impulse);
	}
}

//Decrease the impulse speed we are currently going at 
void APlayerShip::DecreaseImpulseSpeed()
{
	//if we're not at full speed
	if (impulseSpeed != ImpulseSpeed::None)
	{
		//cast to an int and decrease the value of the enum
		int impulse = static_cast<int>(impulseSpeed) - 1;
		impulseSpeed = static_cast<ImpulseSpeed>(impulse);
	}
}

//turns the ship left and right dependant on axis value (negative for left, positive for right in input menu)
void APlayerShip::TurnRightLeft(float axis)
{
	turningSpeed = axis;
}

//turns the ship upwards
void APlayerShip::TurnShipUpDown(float axis)
{
	turningSpeedUpDown = axis;
}

//manual Impulse Forward (REDUNDANT CODE ONLY FOR TESTING PURPOSES)
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




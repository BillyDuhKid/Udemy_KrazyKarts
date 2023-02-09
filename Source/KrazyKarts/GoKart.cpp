// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"

#include "EnhancedInputComponent.h"



/* Block of includes only added to try and get SetupPlayerInputComponent working
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
*/

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Translation = Velocity * 100 * DeltaTime;

	AddActorWorldOffset(Translation);

}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);

/* from AThirdPersonCPPCharacter, but is a ACharacter not an APawn
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AThirdPersonCPPCharacter::Move);
	}

	*/
}

void AGoKart::MoveForward(float Value)
{
	Velocity = GetActorForwardVector() * 20 * Value;
}


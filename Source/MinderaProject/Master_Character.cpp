// Fill out your copyright notice in the Description page of Project Settings.


#include "Master_Character.h"
#include "Components/InputComponent.h"

// Sets default values
AMaster_Character::AMaster_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaster_Character::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AMaster_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMaster_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMaster_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMaster_Character::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &AMaster_Character::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMaster_Character::LookUp);


}

void AMaster_Character::MoveForward(float Axis)
{
	if (Axis != 0.f)
	{
		const FRotator ControlDirection = GetControlRotation();
		const FRotator YawDirection = FRotator(0, ControlDirection.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawDirection).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}

void AMaster_Character::MoveRight(float Axis)
{
	if (Axis != 0.f)
	{
		const FRotator ControlDirection = GetControlRotation();
		const FRotator YawDirection = FRotator(0, ControlDirection.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawDirection).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

void AMaster_Character::LookUp(float Axis)
{
	AddControllerPitchInput(Axis);
	
}

void AMaster_Character::LookRight(float Axis)
{
	AddControllerYawInput(Axis);
}
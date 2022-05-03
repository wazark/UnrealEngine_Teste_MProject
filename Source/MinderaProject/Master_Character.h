// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Master_Character.generated.h"

UCLASS()
class MINDERAPROJECT_API AMaster_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMaster_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
		
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void LookUp(float Axis);
	void LookRight(float Axis);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

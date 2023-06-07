// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShakeActor.h"

// Sets default values
AMyShakeActor::AMyShakeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyShakeActor::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AMyShakeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(getCurrentLocation());

}

void AMyShakeActor::ShakeThisActor(float deltaTime){

	FVector NewLocation = GetActorLocation();

////////X coordinate
if(NewLocation.X > (getPosition.X + MotionX)){
		isMovingRight = false;
	}else if(NewLocation.X < (getPosition.X + -MotionX)){
		isMovingRight = true;
	}

	float factorX = (isMovingRight ? 20.f : -20.f);
	NewLocation.X = factorX * deltaTime * strength;

////////Y coordinate
if(NewLocation.Y > (getPosition.X + MotionY)){
		isMovingForward = false;
	}else if(NewLocation.Y < (getPosition.Y + -MotionY)){
		isMovingForward = true;
	}

	float factorY = (isMovingForward ? 20.f : -20.f);
	NewLocation.Y = factorY * deltaTime * strength;

////////Z coordinate
	if(NewLocation.Z > (getPosition.Z + MotionZ)){
		isMovingUp = false;
	}else if(NewLocation.Z < (getPosition.Z + -MotionZ)){
		isMovingUp = true;
	}

	float factorZ = (isMovingUp ? 20.f : -20.f);
	NewLocation.Z = factorZ * deltaTime * strength;
}

FVector AMyShakeActor::getCurrentLocation(){
	getPosition = GetActorLocation();
	return getPosition;
}

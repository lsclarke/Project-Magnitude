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
	SetActorLocation(MyPosition);
	//PosX = MyPosition.X;
	//PosY = MyPosition.Y;
	//PosZ = MyPosition.Z;

}

// Called every frame
void AMyShakeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetMyPosition();


///X Magnitude
FVector NewPositionX = GetActorLocation();

  if (NewPositionX.X > PosX) {
    IsMovingRight = false;
  } else if (NewPositionX.X < -PosX) {
    IsMovingRight = true;
  }
  float factorX = (IsMovingRight ? 20.0f : -20.0f);
  NewPositionX.X += factorX * DeltaTime * Strength * Velocity;
  SetActorLocation(NewPositionX);

//Y Magnitude
FVector NewPositionY = GetActorLocation();

  if (NewPositionY.Y > PosY) {
    IsMovingForward = false;
  } else if (NewPositionY.Y < -PosY) {
    IsMovingForward = true;
  }
  float factorY = (IsMovingForward ? 20.0f : -20.0f);
  NewPositionY.Y += factorY * DeltaTime * Strength * Velocity;
  SetActorLocation(NewPositionY);

//Z Magnitude
FVector NewPositionZ = GetActorLocation();

  if (NewPositionZ.Z > PosZ) {
    IsMovingUp = false;
  } else if (NewPositionZ.Z < -PosZ) {
    IsMovingUp = true;
  }
  float factorZ = (IsMovingUp ? 20.0f : -20.0f);
  NewPositionZ.Z += factorZ * DeltaTime * Strength * Velocity;
  SetActorLocation(NewPositionZ);
}

FVector AMyShakeActor::GetMyPosition()
{
	MyPosition = GetActorLocation();
	return MyPosition;
}


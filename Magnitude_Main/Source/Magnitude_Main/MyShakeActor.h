// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyShakeActor.generated.h"

UCLASS()
class MAGNITUDE_MAIN_API AMyShakeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyShakeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector MyPosition;

	UPROPERTY(EditAnywhere)
	float PosX = 0.0f;
	UPROPERTY(EditAnywhere)
	float PosY = 0.0f;
	UPROPERTY(EditAnywhere)
	float PosZ = 0.0f;

	UPROPERTY(EditAnywhere)
	float Strength;
	UPROPERTY(EditAnywhere)
	float Velocity;

	bool bImGoingUp = true;
	bool IsMovingUp = true;
	bool IsMovingRight = true;
	bool IsMovingForward = true;


	void StartEarthQuake(float DeltaTime);

	FVector GetMyPosition();



};

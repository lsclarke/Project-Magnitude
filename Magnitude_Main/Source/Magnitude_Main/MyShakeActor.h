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

	//Functions
	UFUNCTION(BlueprintCallable)
	void ShakeThisActor(float deltaTime);
	UFUNCTION(BlueprintCallable)
	FVector getCurrentLocation();

	//Variable for the magnitude strength
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float strength;

	//Variables for the position change
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MotionX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MotionY; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MotionZ;

	//Vector-Location Variable
	UPROPERTY(EditAnywhere)
	FVector getPosition;


	//Bool Variables
	UPROPERTY(EditAnywhere)
	bool isMovingUp;
	UPROPERTY(EditAnywhere)
	bool isMovingRight;
	UPROPERTY(EditAnywhere)
	bool isMovingForward;



};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	void Elevate(float RelativeSpeed);
	
	UPROPERTY(EditDefaultsOnly, Category=Setup)
		float MaxDegreesPerSeconds = 15;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevation = 30;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevation = 0;
};

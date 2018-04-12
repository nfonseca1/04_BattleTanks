// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Player possessing: %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Possessed"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		

	}

}

// Get World location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	// Find crosshair position in pixel coordinates
	int32 ViewportSizeX, viewportSizeY;
	GetViewportSize(ViewportSizeX, viewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, viewportSizeY * CrosshairYLocation);
	
	// De-project screen position of crosshair to world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation; 
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

	return true;
}

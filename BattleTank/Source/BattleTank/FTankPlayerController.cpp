// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "FTankPlayerController.h"


void AFTankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *ControlledTank->GetName());
	}
}
	
void AFTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* AFTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AFTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Get world location through crosshair (Line trace)
	//If it hits the landscape
		//Tell controlled tank to aim at this point
}
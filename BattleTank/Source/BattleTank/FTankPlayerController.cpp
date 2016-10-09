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

ATank* AFTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


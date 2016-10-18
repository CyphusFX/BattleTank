// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "FTankPlayerController.generated.h" //Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AFTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	void Tick(float DeltaTime) override;
	void BeginPlay() override;


private:
	//Move barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};

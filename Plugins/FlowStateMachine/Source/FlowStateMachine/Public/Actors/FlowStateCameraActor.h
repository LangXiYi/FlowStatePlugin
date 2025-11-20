// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Utility/FlowStateUtility.h"
#include "FlowStateCameraActor.generated.h"

UCLASS()
class FLOWSTATEMACHINE_API AFlowStateCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	AFlowStateCameraActor();

public:
	virtual void BeginPlay() override;

	virtual void PreBecomeViewTarget(float FOV, bool bIsForceReset = true, ECameraRotationMode RotationMode = ECameraRotationMode::None, FVector OriginPos = FVector::ZeroVector);

	UFUNCTION(BlueprintCallable, Category = "FlowStateCameraActor")
	virtual void ResetCameraView();
	
	UFUNCTION(BlueprintCallable, Category = "FlowStateCameraActor")
	void SetCameraViewTarget(FVector TargetPos);
	
	UFUNCTION(BlueprintCallable, Category = "FlowStateCameraActor")
	void SetCameraRotationMode(ECameraRotationMode RotationMode) { CameraRotationMode = RotationMode; }

protected:
	virtual void BecomeViewTarget(APlayerController* PC) override;
	virtual void EndViewTarget(APlayerController* PC) override;

	virtual void EnableInput(APlayerController* PlayerController) override;
	virtual void DisableInput(APlayerController* PlayerController) override;

	/**
	 * Input Function
	 */

	void AddControllerYawInput(float X);
	void AddControllerPitchInput(float X);
	void AddControllerPitchInput_Origin(float X);
	void AddControllerYawInput_Origin(float X);

protected:
	FTransform DefaultTransform;
	UPROPERTY(BlueprintReadOnly, Category = "FlowStateCameraActor")
	float DefaultFOV;
	ECameraRotationMode CameraRotationMode;

private:
	FVector ViewOriginPos;

	APlayerController* Private_PC = nullptr;

	bool bIsInitViewOriginPos = false;
	float Radius = 0.0f;
};

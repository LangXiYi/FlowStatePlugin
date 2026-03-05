// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/Actions/FlowStateAction.h"
#include "Actions_Camera.generated.h"

/**
 * 这个只是一个非常简陋的版本，既不能缓存旧相机位置，也不能在过程中对相机进行任何操作
 * 只能简单的将视角切换至指定的位置、角度。
 */
UCLASS()
class FLOWSTATEMACHINE_API UActions_Camera : public UFlowStateAction
{
	GENERATED_BODY()

public:
	virtual void ExecuteAction(UFSMNodeInstance* Instance) override;
	
	virtual FString GetNodeName() const override { return "SwitchCamera"; }

protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
	FString CameraName;
};

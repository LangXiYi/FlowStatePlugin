// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FSMCommonData.generated.h"

/**
 * 类似 Blackboard 供状态机读取公共数据
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	int Value;
};

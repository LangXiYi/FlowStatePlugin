// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FSMCommonData.generated.h"

class UCommonDataType;

USTRUCT(BlueprintType)
struct FCommonDataTypeKey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName KeyName;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly)
	UCommonDataType* DataType;
};

/**
 * 类似 Blackboard 供状态机读取公共数据
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FCommonDataTypeKey> Keys;

	uint16 GetKeyID() const;
	
	FName GetKey() const { return NAME_None; }
	UCommonDataType* GetDataType() const { return nullptr; }
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Utility/FSMUtility.h"
#include "FSMCommonData.generated.h"

class UFSMCommonDataType;

USTRUCT(BlueprintType)
struct FCommonDataEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName EntryName;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly)
	UFSMCommonDataType* KeyType;
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
	TArray<FCommonDataEntry> Keys;

public:
	const FCommonDataEntry* GetKey(FCommonData::FKey KeyID) const;

	FCommonData::FKey GetKeyID(const FName KeyName) const;
	FName GetKeyName(FCommonData::FKey KeyID) const;

	TSubclassOf<UFSMCommonDataType> GetDataType(FCommonData::FKey KeyID) const;

protected:
	FCommonData::FKey InternalGetKeyID(const FName& KeyName) const;

};

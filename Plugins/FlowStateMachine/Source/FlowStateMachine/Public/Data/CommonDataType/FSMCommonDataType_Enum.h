// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Enum.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Enum : public UFSMCommonDataType
{
	GENERATED_BODY()

public:
	typedef uint8 FDataType;
	static const FDataType InvalidValue;
public:
	static FDataType GetValue(const UFSMCommonDataType_Enum* KeyObj)
	{
		return KeyObj ? KeyObj->EnumValue : InvalidValue;
	}

	static bool SetValue(UFSMCommonDataType_Enum* KeyObj, typename FDataType Value)
	{
		if (KeyObj)
		{
			KeyObj->EnumValue = Value;
			return true;
		}
		return false;
	}

protected:
	UPROPERTY(EditAnywhere)
	UEnum* EnumType;

	UPROPERTY()
	uint8 EnumValue;
};

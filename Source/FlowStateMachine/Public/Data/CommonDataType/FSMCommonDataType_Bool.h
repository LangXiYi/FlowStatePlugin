// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Bool.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Bool : public UFSMCommonDataType
{
	GENERATED_BODY()

public:
	typedef bool FDataType;
	static const FDataType InvalidValue;

public:
	static FDataType GetValue(const UFSMCommonDataType_Bool* KeyObj)
	{
		return KeyObj ? (FDataType)KeyObj->DataValue : InvalidValue;
	}

	static bool SetValue(UFSMCommonDataType_Bool* KeyObj, FDataType Value)
	{
		if (KeyObj)
		{
			KeyObj->DataValue = Value;
			return true;
		}
		return false;
	}

protected:
	UPROPERTY(EditAnywhere)
	bool DataValue;
};

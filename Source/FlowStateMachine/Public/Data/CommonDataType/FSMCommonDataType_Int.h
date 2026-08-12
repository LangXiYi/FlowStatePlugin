// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Int.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Int : public UFSMCommonDataType
{
	GENERATED_BODY()

public:
	typedef int FDataType;
	static const FDataType InvalidValue;
public:
	static FDataType GetValue(const UFSMCommonDataType_Int* KeyObj)
	{
		return KeyObj ? (FDataType)KeyObj->DataValue : InvalidValue;
	}

	static bool SetValue(UFSMCommonDataType_Int* KeyObj, FDataType Value)
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
	int DataValue;
};

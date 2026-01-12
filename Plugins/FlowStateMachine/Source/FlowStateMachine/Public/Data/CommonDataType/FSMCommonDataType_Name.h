// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Name.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Name : public UFSMCommonDataType
{
	GENERATED_BODY()

public:
	typedef FName FDataType;
	static const FDataType InvalidValue;
public:
	static FDataType GetValue(const UFSMCommonDataType_Name* KeyObj)
	{
		return KeyObj ? (FDataType)KeyObj->DataValue : InvalidValue;
	}

	static bool SetValue(UFSMCommonDataType_Name* KeyObj, typename FDataType Value)
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
	FName DataValue;
};

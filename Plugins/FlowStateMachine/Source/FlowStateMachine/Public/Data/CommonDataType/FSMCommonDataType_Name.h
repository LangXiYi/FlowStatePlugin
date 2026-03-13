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
    using FDataType = FName;
    static const FDataType InvalidValue;

    static FDataType GetValue(const UFSMCommonDataType_Name* KeyObj)
    {
        return KeyObj ? static_cast<FDataType>(KeyObj->DataValue) : InvalidValue;
    }

    static bool SetValue(UFSMCommonDataType_Name* KeyObj, FDataType Value)
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

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Object.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Object : public UFSMCommonDataType
{
    GENERATED_BODY()

public:
    using FDataType = UObject*;
    static const FDataType InvalidValue;

    static FDataType GetValue(const UFSMCommonDataType_Object* KeyObj)
    {
        return KeyObj ? static_cast<FDataType>(KeyObj->DataValue) : InvalidValue;
    }

    static bool SetValue(UFSMCommonDataType_Object* KeyObj, FDataType Value)
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
    UObject* DataValue;
};

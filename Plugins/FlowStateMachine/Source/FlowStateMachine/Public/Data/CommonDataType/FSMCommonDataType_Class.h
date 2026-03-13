// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Class.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Class : public UFSMCommonDataType
{
    GENERATED_BODY()

public:
    using FDataType = UClass*;
    static const FDataType InvalidValue;

    static FDataType GetValue(const UFSMCommonDataType_Class* KeyObj)
    {
        return KeyObj ? static_cast<FDataType>(KeyObj->DataValue) : InvalidValue;
    }

    static bool SetValue(UFSMCommonDataType_Class* KeyObj, FDataType Value)
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
    UClass* DataValue;
};

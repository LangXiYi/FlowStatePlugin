// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMCommonDataType.h"
#include "FSMCommonDataType_Vector.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataType_Vector : public UFSMCommonDataType
{
    GENERATED_BODY()

public:
    using FDataType = FVector;
    static const FDataType InvalidValue;

    static FDataType GetValue(const UFSMCommonDataType_Vector* KeyObj)
    {
        return KeyObj ? static_cast<FDataType>(KeyObj->DataValue) : InvalidValue;
    }

    static bool SetValue(UFSMCommonDataType_Vector* KeyObj, FDataType Value)
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
    FVector DataValue;
};

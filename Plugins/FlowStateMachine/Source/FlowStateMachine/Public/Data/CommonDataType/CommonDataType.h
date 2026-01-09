// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CommonDataType.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UCommonDataType : public UObject
{
	GENERATED_BODY()

	// 子类定义他们子级的 DataType
	// typedef YourCustomType FDataType;
};

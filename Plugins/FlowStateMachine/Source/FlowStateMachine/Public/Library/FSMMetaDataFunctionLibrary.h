// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSMMetaDataFunctionLibrary.generated.h"

class UFSMMetaDataAsset;
class UFSMMetaDataFragment;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMMetaDataFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    //////////////////////////////////////////////////////////////////
    // Flow State Machine Meta Data
    //////////////////////////////////////////////////////////////////

    /**
     * 使用资产ID加载资产对象
     * NOTE: 编辑器模式下资产加载策略与打包后策略不同，编辑器环境下资源被加载过后不会释放，除非重启编辑器
     */
    UFUNCTION(BlueprintPure, Category = "FSMMetaDataFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    static UFSMMetaDataAsset* FindMetaDataAsset(UObject* WorldContextObject, FPrimaryAssetId MetaDataID);

    /**
     * 使用资产ID与片段类型加载指定的资产片段
     * NOTE: 编辑器模式下资产加载策略与打包后策略不同，编辑器环境下资源被加载过后不会释放，除非重启编辑器
     */
    UFUNCTION(BlueprintPure, Category = "FSMMetaDataFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeterminesOutputType = "DataType"
        ))
    static UFSMMetaDataFragment* FindMetaDataFragment(UObject* WorldContextObject, FPrimaryAssetId MetaDataID,
                                                      TSubclassOf<UFSMMetaDataFragment> DataType);

    template <class T>
    static T* FindMetaDataFragment(UObject* WorldContextObject)
    {
        return static_cast<T*>(FindMetaDataFragment(WorldContextObject, T::StaticClass()));
    }

    /** 资产的引用计数 */
    static int32 CountSimpleReferencers(UObject* TargetObject);
};

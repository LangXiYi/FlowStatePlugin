// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FSMMetaDataFunctionLibrary.h"

#include "Data/FSMMetaDataAsset.h"
#include "Data/DataFragments/FSMMetaDataFragment_Assets.h"
#include "Engine/AssetManager.h"
#include "Library/FSMFunctionLibrary.h"
#include "SM/FlowStateContext.h"

UFSMMetaDataAsset* UFSMMetaDataFunctionLibrary::FindMetaDataAsset(UObject* WorldContextObject,
                                                                  FPrimaryAssetId MetaDataID)
{
    UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(MetaDataID);
    // 确保资产对象的有效性
    if (AssetObject && !AssetObject->IsPendingKill())
    {
#if !UE_BUILD_SHIPPING
        int32 ReferencerCount = CountSimpleReferencers(AssetObject);
        ensureMsgf(ReferencerCount <= 0, TEXT("资产 %s (%s) 被 %d 个对象引用"),
                   *AssetObject->GetName(),
                   *MetaDataID.ToString(),
                   ReferencerCount);
#endif

        if (UFSMMetaDataAsset* MetaData = Cast<UFSMMetaDataAsset>(AssetObject))
        {
            return MetaData;
        }
    }
    return nullptr;
}

UFSMMetaDataFragment* UFSMMetaDataFunctionLibrary::FindMetaDataFragment(UObject* WorldContextObject,
                                                                        FPrimaryAssetId MetaDataID,
                                                                        TSubclassOf<UFSMMetaDataFragment> DataType)
{
    if (UFSMMetaDataAsset* MetaData = FindMetaDataAsset(WorldContextObject, MetaDataID))
    {
        return MetaData->FindDataFragment(DataType);
    }
    return nullptr;
}

int32 UFSMMetaDataFunctionLibrary::CountSimpleReferencers(UObject* TargetObject)
{
    if (!TargetObject || TargetObject->IsPendingKill())
    {
        return 0;
    }

    int32 ReferencerCount = 0;

    // 快速检查：遍历所有对象属性
    for (FThreadSafeObjectIterator It; It; ++It)
    {
        UObject* CurrentObject = *It;
        if (CurrentObject == TargetObject || CurrentObject->IsPendingKill())
        {
            continue;
        }

        // 快速属性检查
        for (TFieldIterator<FObjectProperty> PropIt(CurrentObject->GetClass()); PropIt; ++PropIt)
        {
            FObjectProperty* ObjectProp = *PropIt;
            void* PropertyValue = ObjectProp->ContainerPtrToValuePtr<void>(CurrentObject);
            UObject* ReferencedObject = ObjectProp->GetObjectPropertyValue(PropertyValue);

            if (ReferencedObject == TargetObject)
            {
                ReferencerCount++;
                break; // 这个对象已经引用了目标，跳到下一个对象
            }
        }
    }

    return ReferencerCount;
}

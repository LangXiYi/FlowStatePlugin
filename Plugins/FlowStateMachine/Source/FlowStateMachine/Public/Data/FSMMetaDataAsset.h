// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FSMMetaDataAsset.generated.h"

class UFSMMetaDataFragment;

/**
 * 数据资产，支持使用PrimaryDataAssetID进行动态加载
 * 需要在ProjectSettings中找到AssetManager->PrimaryAssetTypeScan，为当前数据资产添加搜索路径
 *	数据实例如下：
 *		PrimaryAssetType: FlowStateDataAsset
 *		AssetBaseType: FlowStateDataAsset
 *		HasBlueprintClasses: False
 *		IsEditorOnly: True
 *		Directories: /Game/Data
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMMetaDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	virtual void PostLoad() override;

	UFSMMetaDataFragment* FindDataFragment(TSubclassOf<UFSMMetaDataFragment> DataType);
	
	template<class T>
	T FindDataFragment()
	{
		return (T*)FindDataFragment(T::StaticClass());
	}

protected:
	// 通过添加编辑器实例
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "MetaData")
	TArray<UFSMMetaDataFragment*> DataFragments;
};

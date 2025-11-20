// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FlowStateDataAsset.generated.h"

class UWidget;
class UFlowState;
class UFlowStateDataAsset;

/**
 * 数据资产子类
 */
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew)
class FLOWSTATEMACHINE_API UFlowStateDataFragment : public UObject
{
	GENERATED_BODY()

public:
	virtual void OnPostLoad(UFlowStateDataAsset* Parent) {}
};

/**
 * 该数据保存在 OperationGuideDataAsset 中，内部保存的数据会跟随该资产被一起加载。
 * 关卡实例保存的是数据资产的ID而非数据资产本身，故调用 OpenLevel 打开新关卡时不会同步加载这些资产
 * 在关卡打开且所有Actor的 BeginPlay 事件被触发后，才会触发资产加载事件，将资源加载到内存中。
 * 数据长期有效，除非数据资产被卸载
 */
UCLASS()
class UDataFragment_Assets : public UFlowStateDataFragment
{
	GENERATED_BODY()

protected:
	/** 需要使用到的模型资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data")
	TMap<FName, UStaticMesh*> SM_Meshes;

	/** 需要使用到的骨骼资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data")
	TMap<FName, USkeletalMesh*> SK_Meshes;

	/** 需要使用到的动画资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data")
	TMap<FName, UAnimSequence*> Animations;
public:
	UFUNCTION(BlueprintCallable, Category = "Data")
	virtual UObject* FindData(TSubclassOf<UObject> Type, FName Name);

	template<class T>
	T* FindData(FName Name)
	{
		return (T*)FindData(T::StaticClass(), Name);
	}
};

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
class FLOWSTATEMACHINE_API UFlowStateDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	virtual void PostLoad() override;

	UFlowStateDataFragment* FindDataFragment(TSubclassOf<UFlowStateDataFragment> DataType);
	
	template<class T>
	T FindDataFragment()
	{
		return (T*)FindDataFragment(T::StaticClass());
	}

public:
	// 进入培训关卡后，状态机首先进入的状态
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data Asset")
	TSubclassOf<UFlowState> StartState;

protected:
	// 通过添加编辑器实例
	UPROPERTY(Instanced, BlueprintReadOnly, EditDefaultsOnly, Category = "Data Asset")
	TArray<UFlowStateDataFragment*> DataArray;
};

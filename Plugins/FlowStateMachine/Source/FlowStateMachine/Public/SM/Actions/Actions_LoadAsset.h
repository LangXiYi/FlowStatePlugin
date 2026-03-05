// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/Actions/FlowStateAction.h"
#include "SM/FlowStateContext.h"
#include "Actions_LoadAsset.generated.h"

struct FStreamableHandle;

/**
 * 加载资产
 * 允许预加载
 * 需要搭配 AssetCondition 使用，保证在进入步骤时，资产已全部加载完成
 *
 * Note: Scans a list of paths and reads asset data for all primary assets of a specific type.
 *       If done in the editor it will load the data off disk, in cooked games it will load out of the asset registry cache
 * Node: 资产在调用卸载函数后不会立即卸载，需要等待该资产的引用计数归零后才会开始执行，期间资产会一致在内存中保持加载。
 */
UCLASS(NotBlueprintable)
class FLOWSTATEMACHINE_API UActions_LoadAsset : public UFlowStateAction
{
	GENERATED_BODY()

public:
	UActions_LoadAsset(const FObjectInitializer& ObjectInitializer);
	
	virtual void ExecuteAction(UFSMNodeInstance* Instance) override;

	virtual void OnPreprocessing() override;

	bool HasLoadCompleted() const;

protected:
	void LoadAsset(bool IsSyncLoad, bool IsPreload = false);

	void UnloadAsset();

	void OnExitState();

private:
	void PrintLoadBoundMessage(const TArray<FName>& LoadBounds) const;
	
protected:
	/** 需要加载的资产ID, 类型主要为 FSMMetaDataAsset */
	UPROPERTY(EditAnywhere)
	FPrimaryAssetId AssetId;

	/** 是否允许预加载，加载会在运行状态机时发生 */
	UPROPERTY(EditAnywhere)
	bool bAllowPreLoading = true;

	/** 在当前状态结束后，是否自动释放已加载的资产 */
	UPROPERTY(EditAnywhere)
	bool bAutoReleaseAsset = false;

	/** 同步加载数据（阻塞游戏进程） */
	UPROPERTY(EditAnywhere, Category = "Advanced")
	bool bSyncLoad = false;

private:
	// 使用弱指针引用该资产，确保回收机制正常运行
	UPROPERTY(Transient)
	TWeakObjectPtr<UFSMMetaDataAsset> MetaData;

	TSharedPtr<FStreamableHandle> LoadingHandle;
};

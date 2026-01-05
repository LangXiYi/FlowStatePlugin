// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "SM/FlowStateContext.h"
#include "Actions_LoadAsset.generated.h"

struct FStreamableHandle;

/**
 * 加载资产
 * 允许预加载
 * 需要搭配 AssetCondition 使用，保证在进入步骤时，资产已全部加载完成
 */
UCLASS(NotBlueprintable)
class FLOWSTATEMACHINE_API UActions_LoadAsset : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()

public:
	UActions_LoadAsset(const FObjectInitializer& ObjectInitializer);
	
	virtual void ExecuteAction() override;

	void LoadAsset(bool bIsASync = true);
	void UnloadAsset();
	void PreloadAsset(FOnExitState& OnExitState);
	bool HasLoadCompleted() const;
	bool HasPreloadCompleted() const;

protected:
	void PrintLoadBoundMessage(const TArray<FName>& LoadBounds) const;

	void OnExitState(UFSMRuntimeNode* ExitNode);

private:
	void CheckCondition();	

protected:
	/** 需要加载的资产ID, 类型主要为 FSMMetaDataAsset */
	UPROPERTY(EditAnywhere)
	FPrimaryAssetId AssetId;

	/** 是否允许预加载，及在当前状态时会同步执行下一步骤的资产加载逻辑 */
	UPROPERTY(EditAnywhere)
	bool bAllowPreLoading = true;

	/** 在当前状态结束后，是否自动释放已加载的资产 */
	UPROPERTY(EditAnywhere)
	bool bAutoReleaseAsset = false;

	/** 同步加载数据（阻塞游戏进程） */
	UPROPERTY(EditAnywhere, Category = "Advanced")
	bool bSyncLoad = false;

	UPROPERTY()
	UFSMMetaDataAsset* MetaData;

	TSharedPtr<FStreamableHandle> LoadingHandle;
	TSharedPtr<FStreamableHandle> PreloadingHandle;
private:
	FDelegateHandle OnExitStateHandle;
	FDelegateHandle OnEnterStateHandle;
};

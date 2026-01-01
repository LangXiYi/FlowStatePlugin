// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowStateBase.h"
#include "FSMGC.h"
#include "UObject/Object.h"
#include "Utility/FSMUtility.h"
#include "FlowStateContext.generated.h"

class UFlowStateBase;
class UFlowStateMachine;
class UFSMMetaDataAsset;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFlowStateMachine);

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateContext : public UObject
{
	GENERATED_BODY()

	friend class UFlowStateBase;

public:
	UFlowStateContext();
	
public:
	virtual void RegisterFlowStateMachine(UFlowStateMachine* FlowStateMachine);

	// TODO::由程序自动处理状态切换而不是用户定义
	bool TrySwitchTo(UFSMRuntimeNode* Node);

	void Tick(float DeltaTime);

public:
	FOnStartFlowStateMachine OnStartFlowStateMachine;

	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	virtual UWorld* GetWorld() const override;

	UFlowStateLayoutWidget* GetLayoutWidget() const { return nullptr; }
	
	UFUNCTION(BlueprintCallable, Category="FlowStateContext")
	FORCEINLINE UFlowStateBase* GetCurrentState() { return CurState; }
	template<class T>
	FORCEINLINE T* GetCurrentState() const { return static_cast<T*>(CurState); }

	UFUNCTION(BlueprintCallable, Category = "FlowStateContext")
	FORCEINLINE UFSMMetaDataAsset* GetMetaData() const { return FlowStateData; }

	////////////////////////////////////////////////////////////////////////
	/// Custom Process Event
	////////////////////////////////////////////////////////////////////////
public:

protected:
	/* 保证 FSMMetaDataAsset 已加载 */
	virtual void BeginPlay();
	/* 保证 FSMMetaDataAsset 已加载 */
	UFUNCTION(BlueprintImplementableEvent, Category = "FlowStateContext")
	void OnBeginPlay();
	
	////////////////////////////////////////////////////////////////////////
	/// GCManager Helper
	////////////////////////////////////////////////////////////////////////
public:
	/** 将目标添加至缓存 */
	template<class T>
	void AddToCache(T* Target, EFlowStateLifetime Lifetime)
	{
		GCManager->AddToCache(Target, Lifetime);
	}
	/** 从缓存中查找目标 */
	template<class T>
	T* FindByCache(FName Name) const
	{
		return GCManager->FindByCache<T>(Name);
	}
	/** 从缓存中查找目标 */
	AActor* FindByCache(FName Name, TSubclassOf<AActor> Type) const
	{
		return GCManager->FindByCache(Name, Type);
	}
	/** 清空缓存 */
	void ClearAllCache() const { GCManager->ClearAllCache(); }

private:
	void LoadingFlowStateData(const FPrimaryAssetId& FlowStateDataID, TFunction<void()> Callback);

protected:
	UPROPERTY()
	UFlowStateBase* CurState;

	UPROPERTY()
	UFSMRuntimeNode* CurNode;

private:
	UPROPERTY()
	UFSMMetaDataAsset* FlowStateData = nullptr;

	UPROPERTY()
	UFlowStateMachine* StateMachine = nullptr;

	UPROPERTY()
	UFlowStateLayoutWidget* LayoutWidget;

	TSharedPtr<struct FStreamableHandle> MetaDataLoadHandle;

	TSharedPtr<FSMGC> GCManager;
};

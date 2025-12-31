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

	////////////////////////////////////////////////////////////////////////
	/// IFlowStateInterface Event
	////////////////////////////////////////////////////////////////////////
public:
	// virtual void OnEnter() override {}
	// virtual void OnExit() override {}
	// virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) override {}
	// virtual void OnInitialize(UFlowStateContext* Context) override {}
	// virtual void OnPreInitialize(IFlowStateInterface* LastState) override {}
	// virtual void OnPostInitialize() override {}

	UFlowStateBase* SwitchTo(UFlowStateBase* NewState);
	UFlowStateBase* SwitchTo(const TSubclassOf<UFlowStateBase>& NewStateClass);
	template<class StateType = UFlowStateBase>
	StateType* SwitchTo() { return (StateType*)SwitchToByClass(StateType::StaticClass()); }

	// 获取下一组将要进入的节点

	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	virtual UWorld* GetWorld() const override;
	virtual ULevel* GetLevel() const;
	
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
	/** 不保证 FSMMetaDataAsset 已加载 */
	virtual void Initialize();
	/** 不保证 FSMMetaDataAsset 已加载 */
	UFUNCTION(BlueprintImplementableEvent, Category = "FlowStateContext")
	void OnInitialize();

	virtual void Tick(float DeltaTime);
	UFUNCTION(BlueprintImplementableEvent, Category = "FlowStateContext", DisplayName="Tick")
	void OnTick(float DeltaTime);

protected:
	/* 保证 FSMMetaDataAsset 已加载 */
	virtual void BeginPlay();
	/* 保证 FSMMetaDataAsset 已加载 */
	UFUNCTION(BlueprintImplementableEvent, Category = "FlowStateContext")
	void OnBeignPlay();
	
	////////////////////////////////////////////////////////////////////////
	/// GC Helper
	////////////////////////////////////////////////////////////////////////
public:
	/** 将目标添加至缓存 */
	template<class T>
	void AddToCache(T* Target, EFlowStateLifetime Lifetime)
	{
		GC->AddToCache(Target, Lifetime);
	}
	/** 从缓存中查找目标 */
	template<class T>
	T* FindByCache(FName Name) const
	{
		return GC->FindByCache<T>(Name);
	}
	/** 从缓存中查找目标 */
	AActor* FindByCache(FName Name, TSubclassOf<AActor> Type) const
	{
		return GC->FindByCache(Name, Type);
	}
	/** 清空缓存 */
	void ClearAllCache() const { GC->ClearAllCache(); }

private:
	void LoadingFlowStateData(const FPrimaryAssetId& FlowStateDataID, TFunction<void()> Callback);

protected:
	UPROPERTY()
	UFlowStateBase* CurState;

private:
	UPROPERTY()
	UFSMMetaDataAsset* FlowStateData = nullptr;

	UPROPERTY()
	UFlowStateMachine* StateMachine = nullptr;

	TSharedPtr<struct FStreamableHandle> MetaDataLoadHandle;

	TSharedPtr<FSMGC> GC;
};

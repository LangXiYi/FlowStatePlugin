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
DECLARE_MULTICAST_DELEGATE_OneParam(FStateDelegate, UFSMRuntimeNode*);

/**
 * 因为存在两种可执行的节点，State以及Composites，所以使用他们的公用基类 RuntimeNode
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateContext : public UObject
{
	GENERATED_BODY()

public:
	virtual void RegisterFlowStateMachine(UFlowStateMachine* FlowStateMachine);

	bool TrySwitchTo(UFSMRuntimeNode* Node);

	void Tick(float DeltaTime);

	void ExitCurrentState();

	void EnterNewState(UFSMRuntimeNode* NewState);

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

	
	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	UFlowStateLayoutWidget* GetLayoutWidget() const { return LayoutWidget; }

	TArray<UFSMRuntimeNode*> GetNextStates() const;

	UFUNCTION(BlueprintPure, Category="FlowStateContext")
	FORCEINLINE UFSMRuntimeNode* GetCurrentState() { return CurState; }
	template<class T>
	FORCEINLINE T* GetCurrentState() const { return static_cast<T*>(CurState); }


	////////////////////////////////////////////////////////////////////////
	/// Events
	////////////////////////////////////////////////////////////////////////
public:
	FOnStartFlowStateMachine OnStartFlowStateMachine;
	FStateDelegate OnExitState;
	FStateDelegate OnEnterState;
	FStateDelegate OnPreInitializeState;

protected:
	UPROPERTY()
	UFSMRuntimeNode* CurState;

private:
	UPROPERTY()
	UFlowStateMachine* StateMachine = nullptr;

	UPROPERTY()
	UFlowStateLayoutWidget* LayoutWidget;

	TSharedPtr<FSMGC> GCManager;
};

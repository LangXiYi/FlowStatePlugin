// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowStateBase.h"
#include "FlowStateMachine.h"
#include "FSMGC.h"
#include "UObject/Object.h"
#include "Utility/FSMUtility.h"
#include "FlowStateContext.generated.h"

class UFSMCommonDataManager;
class UFlowStateBase;
class UFlowStateMachine;
class UFSMMetaDataAsset;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFlowStateMachine);
DECLARE_MULTICAST_DELEGATE_OneParam(FStateDelegate, UFSMRuntimeNode*);

/**
 * 因为存在两种可执行的节点，State以及Composites，所以使用他们的公用基类 RuntimeNode
 * TODO::不要直接使用这些实例化了的对象！！！这会导致对象属性被修改
 * 创建一个管理器，管理所有加载的状态机
 *		在加载时，会深度拷贝状态机中的根节点，并将其加入缓存，避免重复复制
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateContext : public UObject
{
	GENERATED_BODY()

public:
	UFlowStateContext(const FObjectInitializer& ObjectInitializer);

	void Initialize(EFSMExecuteMode InExecuteMode);
	
	virtual void RegisterFlowStateMachine(UFlowStateMachine& FlowStateMachine);

	bool TrySwitchTo(UFSMRuntimeNode* Node);

	/** 切换至零散节点 */
	bool GotoScatteredNode(FGuid Key);

	void Tick(float DeltaTime);

	void ExitCurrentState();

	void EnterNewState(UFSMRuntimeNode* NewState);

protected:
	/** 将对象转换为运行时实例化的对象 */
	UFSMRuntimeNodeBase* DumpInstance(const UFSMRuntimeNodeBase* Template);

	/** 将对象转换为运行时实例化的对象 */
	template<class T>
	T* DumpInstance(const UFSMRuntimeNodeBase* Template)
	{
		return static_cast<T*>(DumpInstance(Template));
	}

	/** 转换模板实例为运行时实例 */
	UFSMRuntimeNode* CreateChildrenInstance(const UFSMRuntimeNode* TemplateRootNode, UFSMRuntimeNodeBase* ParentNode, TArray<UFSMRuntimeNodeBase*>& Stack);

	void CreateScatteredInstance();
	
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
	FORCEINLINE UFSMRuntimeNode* GetCurrentState() const { return CurState; }
	template<class T>
	FORCEINLINE T* GetCurrentState() const { return static_cast<T*>(CurState); }

	UFUNCTION(BlueprintPure, Category="FlowStateContext")
	UFSMCommonDataManager* GetCommonDataManager() const { return CommonDataManager; }

	////////////////////////////////////////////////////////////////////////
	/// Events
	////////////////////////////////////////////////////////////////////////
public:
	FOnStartFlowStateMachine OnStartFlowStateMachine;
	FStateDelegate OnExitState;
	FStateDelegate OnEnterState;
	FStateDelegate OnPreInitializeState;

protected:
	UPROPERTY(Transient)
	UFSMRuntimeNode* CurState;

	UPROPERTY()
	TArray<UFSMRuntimeNode*> InstanceStack;

	// 表示执行链中最顶部的元素（不是一定），对于出现环形的执行流，该变量表示的就不一定是最顶部的元素
	TWeakObjectPtr<UFSMRuntimeNodeBase> StackTop;

	UPROPERTY(Transient)
	UFSMRuntimeNode* RootState;

	// 所有的零散节点
	UPROPERTY(Transient)
	TArray<UFSMRuntimeNode*> ScatteredNodes;

	/** 公用数据管理器 */
	UPROPERTY(Transient)
	UFSMCommonDataManager* CommonDataManager;
	
private:
	// 引用资产，供运行时创建新的运行时节点使用
	UPROPERTY(Transient)
	UFlowStateMachine* StateMachine = nullptr;

	UPROPERTY(Transient)
	UFlowStateLayoutWidget* LayoutWidget;

	TSharedPtr<FSMGC> GCManager;

	/** 缓存已经加载的对象，对 Value 使用弱指针引用确保回收机制正常运行 */
	UPROPERTY(Transient)
	TMap<const UFSMRuntimeNodeBase* /* Template Node */, UFSMRuntimeNodeBase* /* Dump Instance */> CacheTemplateObjects;

	UPROPERTY(Transient)
	TMap<FGuid, UFSMRuntimeNode*> ScatteredNodeMapping;

	EFSMExecuteMode ExecuteMode;
};

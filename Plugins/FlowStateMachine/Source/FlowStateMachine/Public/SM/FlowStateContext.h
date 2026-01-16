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

DECLARE_MULTICAST_DELEGATE_OneParam(FStateDelegate, UFSMRuntimeNode*);

/**
 * 因为存在两种可执行的节点，State以及Composites，所以使用他们的公用基类 RuntimeNode
 * TODO::不要直接使用这些实例化了的对象！！！这会导致对象属性被修改
 * 创建一个管理器，管理所有加载的状态机
 *		在加载时，会深度拷贝状态机中的根节点，并将其加入缓存，避免重复复制
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateContext : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	UFlowStateContext(const FObjectInitializer& ObjectInitializer);

	/** 注册状态机至运行时上下文对象 */
	virtual void RegisterFlowStateMachine(UFlowStateMachine& FlowStateMachine);

	/** 切换至状态节点 */
	virtual bool GotoStateNode(UFSMRuntimeNode* Node);

	/** 切换至零散节点 */
	virtual bool GotoScatteredNode(FGuid Key);

	// Begin FTickableGameObject
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override { return Super::GetStatID(); }
	// End of FTickableGameObject

protected:
	/** 进入新的状态 */
	virtual void OnEnterNewState(UFSMRuntimeNode* NewState);

	/** 退出当前的状态 */
	virtual void OnExitCurState();

private:
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

	/** 转换零散的模板节点为运行时对象 */
	void CreateScatteredInstance(TArray<UFSMRuntimeNodeBase*>& Stack);

	////////////////////////////////////////////////////////////////////////
	/// GCManager Helper
	////////////////////////////////////////////////////////////////////////
public:
	/** 将目标添加至缓存 */
	template<class T>
	void AddToCache(T Target, EFlowStateLifetime Lifetime)
	{
		GCManager->AddToCache(Target, Lifetime);
	}
	/** 切换目标的缓存区 */
	template<class T>
	void SwitchCache(T Target, EFlowStateLifetime FromLifetime, EFlowStateLifetime ToLifetime)
	{
		GCManager->SwitchCache(Target, FromLifetime, ToLifetime);
	}
	/** 从缓存中查找目标 */
	template<class T>
	EFlowStateLifetime FindByCache(FName Name, T& OutTarget)
	{
		return GCManager->FindRefByCache(Name, OutTarget);
	}
	/** 清空缓存 */
	void ClearAllCache() const { GCManager->ClearAllCache(); }
	
	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	/** 获取布局控件 */
	UFlowStateLayoutWidget* GetLayoutWidget() const { return LayoutWidget; }

	/** 获取所有的次态对象 */
	TArray<UFSMRuntimeNode*> GetNextStates() const;

	/** 获取当前的状态对象 */
	UFUNCTION(BlueprintPure, Category="FlowStateContext")
	FORCEINLINE UFSMRuntimeNode* GetCurrentState() const { return CurState; }
	/** 获取当前的状态对象 */
	template<class T>
	FORCEINLINE T* GetCurrentState() const { return static_cast<T*>(CurState); }

	/** 获取公用数据管理器 */
	UFUNCTION(BlueprintPure, Category="FlowStateContext")
	UFSMCommonDataManager* GetCommonDataManager() const { return CommonDataManager; }

	/** 获取所有零散节点的唯一ID */
	UFUNCTION(BlueprintPure, Category="FlowStateContext")
	void GetScatteredNodeIDs(TArray<FGuid>& OutData) const { return ScatteredNodeMapping.GenerateKeyArray(OutData); }

	////////////////////////////////////////////////////////////////////////
	/// Events
	////////////////////////////////////////////////////////////////////////
public:
	FStateDelegate OnExitState;
	FStateDelegate OnEnterState;
	FStateDelegate OnPreInitializeState;

protected:
	/** 当前状态 */
	UPROPERTY(Transient)
	UFSMRuntimeNode* CurState;

	/** 执行链 */
	UPROPERTY()
	TArray<UFSMRuntimeNode*> InstanceStack;

	// 表示执行链中最顶部的元素（不是一定），对于出现环形的执行流，该变量表示的就不一定是最顶部的元素
	TWeakObjectPtr<UFSMRuntimeNodeBase> StackTop;

	/** 运行时根节点 */
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

	/** 布局控件 */
	UPROPERTY(Transient)
	UFlowStateLayoutWidget* LayoutWidget;

	/** 资源回收管理器 */
	TSharedPtr<FSMGC> GCManager;

	/** 缓存已经加载的对象，加载完成后自动释放 */
	UPROPERTY(Transient)
	TMap<const UFSMRuntimeNodeBase* /* Template Node */, UFSMRuntimeNodeBase* /* Dump Instance */> CacheTemplateObjects;

	/** 缓存零碎节点与它的唯一ID，加快查询速度 */
	UPROPERTY(Transient)
	TMap<FGuid, UFSMRuntimeNode*> ScatteredNodeMapping;

	bool bIsRegisterFlowStateMachine = false;
};

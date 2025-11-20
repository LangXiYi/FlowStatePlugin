// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowState.h"
#include "UObject/Object.h"
#include <functional>
#include "Utility/FlowStateUtility.h"
#include "FlowStateContext.generated.h"

struct FStreamableHandle;
class UFlowStateDataFragment;
class UFlowStateDataAsset;
class UWidget;

/**
 * 
 */
UCLASS(Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateContext : public UObject
{
	GENERATED_BODY()

	friend class UFlowState;

public:
	/** 此时不保证 FlowStateContext 已经加载 */
	virtual void Initialize();
	UFUNCTION(BlueprintImplementableEvent, Category = "Flow State Context")
	void OnInitialize();

	virtual void BeginPlay();
	UFUNCTION(BlueprintImplementableEvent, Category = "Flow State Context")
	void OnBeignPlay();
	
	UFUNCTION(BlueprintCallable, Category="Flow State Context")
	virtual UFlowState* SwitchTo(UFlowState* NewState);

	UFUNCTION(BlueprintCallable, Category="Flow State Context")
	UFlowState* SwitchToByIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category="Flow State Context", meta = (DeterminesOutputType = "NewState"))
	UFlowState* SwitchToByClass(const TSubclassOf<UFlowState>& NewState) { return SwitchTo(NewObject<UFlowState>(this, NewState)); }

	template<class T>
	T* SwitchTo() { return (T*)SwitchToByClass(T::StaticClass()); }

	virtual void Tick(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category="Flow State Context", meta = (DeterminesOutputType = Type))
	UFlowState* GetCurrentState(TSubclassOf<UFlowState> Type) { return CurState; }

	template<class T>
	T* GetCurrentState() const
	{
		return static_cast<T*>(CurState);
	}

	UFUNCTION(BlueprintCallable, Category="Flow State Context", meta = (DeterminesOutputType = Type))
	virtual AActor* FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag);

	template<class T>
	T* FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag)
	{
		return static_cast<T*>(FindActorFromCache(Type, ActorTag));
	}

	UFUNCTION(BlueprintCallable, Category = "Flow State Context", meta = (DeterminesOutputType = Type))
	virtual void ClearCache();

	UFUNCTION(BlueprintCallable, Category = "Flow State Context")
	UFlowStateDataAsset* GetFlowStateData() { return FlowStateData; }

	UFUNCTION(BlueprintCallable, Category = "Flow State Context", meta = (DeterminesOutputType = "FragmentClass"))
	UFlowStateDataFragment* FindFlowStateDataFragment(TSubclassOf<UFlowStateDataFragment> FragmentClass);

	template<class T>
	T* FindFlowStateDataFragment()
	{
		return (T*)FindFlowStateDataFragment(T::StaticClass());
	}

	void LoadingFlowStateData(std::function<void()> Callback);

	virtual UWorld* GetWorld() const override;

	virtual ULevel* GetLevel() const;

protected:
	UPROPERTY()
	UFlowState* CurState;

	UPROPERTY()
	UFlowState* LastState;

	// 缓存所有隐藏的对象
	TArray<AActor*> HiddenActorsCache;
	TArray<UWidget*> HiddenWidgetsCache;
	TArray<FName> HiddenLevelsCache;

	// TODO::将资产转移至 FlowStateContext 中，方便查询，且不会暴露至外部其他对象。
	// TODO::后续使用 FlowStateContext 作为不同关卡加载的目标
	UPROPERTY(EditAnywhere, Category = "Flow State Context")
	FPrimaryAssetId FlowStateDataID;

	UPROPERTY(BlueprintReadOnly, Category = "Flow State Context")
	UFlowStateDataAsset* FlowStateData = nullptr;

private:
	TSharedPtr<FStreamableHandle> FlowStateDataLoadHandle;
	
	// 当前状态可以切换的状态
	TArray<TSubclassOf<UFlowState>> FlowStateList;
	// 状态机的切换映射
	/**
	 * TODO::后续可以通过图表编辑
	 *               State_B
	 *             /          \
	 * root ----->             State_C ------> State_D          State_G
	 *			   \          /                       \       /
	 *			    State_A                            State_E
	 *			                                              \
	 *			                                                State_F
	 *  Start节点
	 *  Cur节点
	 *     - NextNodes[]
	 *  BroadcastSwitchToByIndex(int Index) --> check(GetThenCount() > Index)
	 *  数据结构大致如下
	 * 		节点结构
	 * 			NodeID
	 * 			NextNodes[节点结构]
	 * 			Node_DisplayName
	 * 			Node_StateClass
	 */
};

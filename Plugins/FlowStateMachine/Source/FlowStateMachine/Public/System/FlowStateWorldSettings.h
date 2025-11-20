// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "Utility/FlowStateUtility.h"
#include "FlowStateWorldSettings.generated.h"


class UFlowStateDataAsset;
BEGIN_NAMESPACE_FSM

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFlowState);

class UFlowStateContext;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API AFlowStateWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	AFlowStateWorldSettings();
public:
	static AFlowStateWorldSettings* Get(UObject* WorldContextObject);
	
	virtual void BeginPlay() override;
	virtual void NotifyBeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	bool IsTrainLevel() const { return bIsFlowStateLevel; }

	FPrimaryAssetId GetOperationGuideAssetId() const { return FlowStateDataID; }

	UFlowStateDataAsset* GetOperationGuideDataAsset() const
	{
		return bIsFlowStateLevel ? FlowStateData : nullptr;
	}

	virtual void Tick(float DeltaSeconds) override;

	UFlowStateContext* GetFlowStateContext() const { return FlowStateContext; }

	AActor* FindCamera(FName Name);

	template<class T>
	T* FindCamera(FName Name)
	{
		return static_cast<T*>(FindCamera(Name));
	}

protected:
	UFUNCTION()
	void OnCompletedLoadPrimaryAsset();

public:
	FOnStartFlowState OnStartFlowState;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	bool bIsFlowStateLevel = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data", meta = (EditCondition = "bIsFlowStateLevel"))
	TSubclassOf<UFlowStateContext> FlowStateContextClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data", meta = (EditCondition = "bIsFlowStateLevel"))
	FPrimaryAssetId FlowStateDataID;

	UPROPERTY(BlueprintReadOnly, Category = "Data")
	UFlowStateDataAsset* FlowStateData = nullptr;
private:
	// 加载事件句柄
	TSharedPtr<struct FStreamableHandle> LoadHandle;

	UPROPERTY()
	UFlowStateContext* FlowStateContext;

	TArray<AActor*> Cameras;
};

END_NAMESPACE_FSM
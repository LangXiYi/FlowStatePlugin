// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "Utility/FSMUtility.h"
#include "FSMWorldSettings.generated.h"


class UFlowStateMachine;
class UFSMMetaDataAsset;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFlowState);

class UFlowStateContext;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API AFSMWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	AFSMWorldSettings();

	static AFSMWorldSettings* Get(UObject* WorldContextObject);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE bool IsFlowStateLevel() const { return bIsFlowStateLevel; }
	FORCEINLINE UFlowStateContext* GetFlowStateContext() const { return FlowStateContext; }

protected:
	virtual void InitFlowStateContext();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "FSMWorldSettings")
	bool bIsFlowStateLevel = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "FSMWorldSettings", meta = (EditCondition = "bIsFlowStateLevel"))
	UFlowStateMachine* FlowStateMachine = nullptr;

private:
	UPROPERTY()
	UFlowStateContext* FlowStateContext;
};


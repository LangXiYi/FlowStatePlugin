// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMUtility.h"
#include "GameplayTagContainer.h"
#include "Components/SlateWrapperTypes.h"
#include "UObject/Object.h"
#include "Widgets/FlowStateWidgetLayerManager.h"
#include "FSMCreateWidgetHelper.generated.h"

class UFlowStateLayoutWidget;
class UWidget;
class UFlowStateContext;

USTRUCT()
struct FLOWSTATEMACHINE_API FFSMWidgetEvent
{
	GENERATED_BODY()

public:
	FName UniqueName;

	#if WITH_EDITOR
	FString DisplayName;
#endif
};

/**
 * 
 */
UCLASS(EditInlineNew)
class FLOWSTATEMACHINE_API UFSMCreateWidgetHelper : public UObject
{
	GENERATED_BODY()

public:
	virtual void CreateWidget(UFlowStateContext* InStateContext);

	UFUNCTION(BlueprintImplementableEvent)
	void OverrideProperty(UWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeWidget(UWidget* ResultWidget);

	UFUNCTION(BlueprintNativeEvent)
	APlayerController* GetPlayerController();

	bool IsValid() const;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
protected:
	UPROPERTY(EditAnywhere, Category = "Basic")
	TSubclassOf<UUserWidget> WidgetClass;

	/** 控件的唯一标识，推荐第一个标签为控件所在的层级，如：Game.Main.CharacterInfo、GameMenu.Main.CharacterInfo等，区分不同层级的控件 */
	UPROPERTY(EditAnywhere, Category = "Basic")
	FGameplayTag WidgetTag;

	UPROPERTY(EditAnywhere, Category = "Basic")
	EFlowStateLifetime WidgetLifetime;

	UPROPERTY(EditAnywhere, Category = "Basic")
	EFlowStateWidgetLayer WidgetLayer;

	UPROPERTY(EditAnywhere, Category = "Basic|Advanced")
	int WidgetPriority = 0;

	UPROPERTY(EditAnywhere, Category = "Basic|Advanced")
	TArray<FFSMWidgetEvent> Events;

	UPROPERTY(EditAnywhere, Category = "Basic|Advanced")
	ESlateVisibility Visibility = ESlateVisibility::SelfHitTestInvisible;
};

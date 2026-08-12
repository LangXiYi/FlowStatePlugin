// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FlowStateWidgetLayerManager.generated.h"

class UFlowStateLayoutWidget;

UENUM()
enum class EFlowStateWidgetLayer : uint8
{
	// 通常用于显示游戏状态，即生命条、武器槽等
	GameLayer = 0,
	// 游戏内的菜单，即背包等
	GameMenu,
	// 游戏菜单，例如游戏开始界面、设置界面等。
	MenuLayer,
	// 游戏弹窗,例如保存游戏或者更改游戏设置时弹窗的确定弹窗之类。
	ModalLayer,
};

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_WIDGET_API UFlowStateWidgetLayerManager : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "FlowStateWidgetLayerManager")
	UFlowStateLayoutWidget* GetLayerWidget(EFlowStateWidgetLayer Layer) const;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UFlowStateLayoutWidget* GameLayer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UFlowStateLayoutWidget* GameMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UFlowStateLayoutWidget* MenuLayer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UFlowStateLayoutWidget* ModalLayer;
};

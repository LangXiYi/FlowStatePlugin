// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FlowStateWidgetLayerManager.h"

UFlowStateLayoutWidget* UFlowStateWidgetLayerManager::GetLayerWidget(EFlowStateWidgetLayer Layer) const
{
	switch (Layer)
	{
	case EFlowStateWidgetLayer::GameLayer:
		return GameLayer;
	case EFlowStateWidgetLayer::GameMenu:
		return GameMenu;
	case EFlowStateWidgetLayer::MenuLayer:
		return MenuLayer;
	case EFlowStateWidgetLayer::ModalLayer:
		return ModalLayer;
	default: return nullptr;
	}
}

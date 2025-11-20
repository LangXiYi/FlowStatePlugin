// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "KismetNodes/SGraphNodeK2Default.h"

/**
 * 
 */
class FLOWSTATEMACHINE_EDITORMODULE_API SMyGraphNodeCreateWidget : public SGraphNodeK2Default
{
public:
	// SGraphNode interface
	virtual TSharedPtr<SGraphPin> CreatePinWidget(UEdGraphPin* Pin) const override;
	// End of SGraphNode interface
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_ConstructObjectFromClass.h"
#include "K2Node_CreateAndBindWidget.generated.h"


/**
 * Bug: 通过节点传递的参数虽然传递过去了，但是值在 Construct 函数中无法获取，需要间隔一帧才能正确获取
 * Note: Lifetime传入隐藏时，若存在其他控件，那么传入的Spawn变量不会覆盖原始控件的变量。
 */
UCLASS()
class FLOWSTATEMACHINE_NODE_API UK2Node_CreateAndBindWidget : public UK2Node_ConstructObjectFromClass
{
	GENERATED_BODY()

public:
	UK2Node_CreateAndBindWidget(const FObjectInitializer& ObjectInitializer);

public:
	//~ Begin UEdGraphNode Interface.
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual TSharedPtr<SGraphNode> CreateVisualWidget() override;
	//~ End UEdGraphNode Interface.

	//~ Begin UK2Node Interface
	virtual void PinDefaultValueChanged(UEdGraphPin* ChangedPin) override;
	virtual FText GetMenuCategory() const override;
	virtual FName GetCornerIcon() const override;
	//~ End UK2Node Interface.
	
	UEdGraphPin* GetWidgetLayoutPin() const;
	UEdGraphPin* GetSlotTagPin() const;
	UEdGraphPin* GetLifetimePin() const;

protected:
	/** Gets the default node title when no class is selected */
	virtual FText GetBaseNodeTitle() const override;
	/** Gets the node title when a class has been selected. */
	virtual FText GetNodeTitleFormat() const override;
	/** Gets base class to use for the 'class' pin.  UObject by default. */
	virtual UClass* GetClassPinBaseClass() const override;
	/**  */
	virtual bool IsSpawnVarPin(UEdGraphPin* Pin) const override;
};


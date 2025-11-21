// Fill out your copyright notice in the Description page of Project Settings.


#include "SMyGraphNodeCreateWidget.h"
#include "Nodes/K2Node_CreateAndBindWidget.h"
#include "KismetPins/SGraphPinClass.h"

TSharedPtr<SGraphPin> SMyGraphNodeCreateWidget::CreatePinWidget(UEdGraphPin* Pin) const
{
	UK2Node_CreateAndBindWidget* CreateWidgetNode = CastChecked<UK2Node_CreateAndBindWidget>(GraphNode);
	UEdGraphPin* ClassPin = CreateWidgetNode->GetClassPin();
	if ((ClassPin == Pin) && (!ClassPin->bHidden || (ClassPin->LinkedTo.Num() > 0)))
	{
		TSharedPtr<SGraphPinClass> NewPin = SNew(SGraphPinClass, ClassPin);
		check(NewPin.IsValid());
		NewPin->SetAllowAbstractClasses(false);
		return NewPin;
	}
	return SGraphNodeK2Default::CreatePinWidget(Pin);
}

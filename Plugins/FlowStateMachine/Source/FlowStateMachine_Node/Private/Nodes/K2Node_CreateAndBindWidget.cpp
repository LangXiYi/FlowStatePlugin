// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_CreateAndBindWidget.h"

#include "EditorCategoryUtils.h"
#include "K2Node_CallFunction.h"
#include "KismetCompiler.h"
#include "Widgets/SMyGraphNodeCreateWidget.h"
#include "GameplayTags.h"
#include "Library/FSMFunctionLibrary.h"
#include "Utility/FSMUtility.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/FlowStateLayoutWidget.h"


struct FK2Node_CreateAndBIndWidgetHelper
{
	static FName const WidgetLayoutPinName;
	static FName const WidgetSlotTagPinName;
	static FName const WidgetLifetimePinName;
};
FName const FK2Node_CreateAndBIndWidgetHelper::WidgetLayoutPinName = "Layout";
FName const FK2Node_CreateAndBIndWidgetHelper::WidgetSlotTagPinName = "SlotTag";
FName const FK2Node_CreateAndBIndWidgetHelper::WidgetLifetimePinName = "Lifetime";

#define LOCTEXT_NAMESPACE "K2Node_CreateAndBindWidget"

UK2Node_CreateAndBindWidget::UK2Node_CreateAndBindWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	NodeTooltip = LOCTEXT("NodeTooltip", "Create a new widget from class and bind for state.");
}

void UK2Node_CreateAndBindWidget::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	UEdGraphPin* LayoutPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UFlowStateLayoutWidget::StaticClass(), FK2Node_CreateAndBIndWidgetHelper::WidgetLayoutPinName);
	UEdGraphPin* TagPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, FGameplayTag::StaticStruct(), FK2Node_CreateAndBIndWidgetHelper::WidgetSlotTagPinName);

	UEdGraphPin* LifeCyclePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, StaticEnum<EFlowStateLifetime>(), FK2Node_CreateAndBIndWidgetHelper::WidgetLifetimePinName);
	const UEnum* const ScaleMethodEnum = StaticEnum<EFlowStateLifetime>();
	LifeCyclePin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(EFlowStateLifetime::Kill));
}

void UK2Node_CreateAndBindWidget::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	static const FName Create_FunctionName = GET_FUNCTION_NAME_CHECKED(UFSMFunctionLibrary, CreateAndBindWidget);
	static const FName WorldContextObject_ParamName(TEXT("WorldContextObject"));
	static const FName WidgetType_ParamName(TEXT("WidgetType"));
	static const FName WidgetLayout_ParamName(TEXT("WidgetLayout"));
	static const FName SlotTag_ParamName(TEXT("WidgetSlotTag"));
	static const FName LifetimeState_ParamName(TEXT("Lifetime"));

	UK2Node_CreateAndBindWidget* CreateWidgetNode = this;
	// Pins From Construct Object
	UEdGraphPin* SpawnNodeExec = CreateWidgetNode->GetExecPin();
	UEdGraphPin* SpawnWorldContextPin = CreateWidgetNode->GetWorldContextPin();
	UEdGraphPin* SpawnClassPin = CreateWidgetNode->GetClassPin();
	UEdGraphPin* SpawnNodeThen = CreateWidgetNode->GetThenPin();
	UEdGraphPin* SpawnNodeResult = CreateWidgetNode->GetResultPin();
	// My Custom Pin
	UEdGraphPin* WidgetLayoutPin = CreateWidgetNode->GetWidgetLayoutPin();
	UEdGraphPin* SlotTagPin = CreateWidgetNode->GetSlotTagPin();
	UEdGraphPin* LifetimeStatePin = CreateWidgetNode->GetLifetimePin();

	UClass* SpawnClass = ( SpawnClassPin != NULL ) ? Cast<UClass>(SpawnClassPin->DefaultObject) : NULL;
	if ( !SpawnClassPin || ((0 == SpawnClassPin->LinkedTo.Num()) && (NULL == SpawnClass)))
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("CreateWidgetNodeMissingClass_Error", "Spawn node @@ must have a class specified.").ToString(), CreateWidgetNode);
		// we break exec links so this is the only error we get, don't want the CreateWidget node being considered and giving 'unexpected node' type warnings
		CreateWidgetNode->BreakAllNodeLinks();
		return;
	}

	//////////////////////////////////////////////////////////////////////////
	// create 'FlowStateMachineLibrary::CreateAndBindWidget' call node
	UK2Node_CallFunction* CallCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(CreateWidgetNode, SourceGraph);
	CallCreateNode->FunctionReference.SetExternalMember(Create_FunctionName, UFSMFunctionLibrary::StaticClass());
	CallCreateNode->AllocateDefaultPins();

	// store off the class to spawn before we mutate pin connections:
	UClass* ClassToSpawn = GetClassToSpawn();

	UEdGraphPin* CallCreateExec = CallCreateNode->GetExecPin();
	UEdGraphPin* CallCreateWorldContextPin = CallCreateNode->FindPinChecked(WorldContextObject_ParamName);
	UEdGraphPin* CallCreateWidgetLayoutPin = CallCreateNode->FindPinChecked(WidgetLayout_ParamName);
	UEdGraphPin* CallCreateWidgetTypePin = CallCreateNode->FindPinChecked(WidgetType_ParamName);
	UEdGraphPin* CallCreateSlotTagPin = CallCreateNode->FindPinChecked(SlotTag_ParamName);
	UEdGraphPin* CallCreateLifetimeStatePin = CallCreateNode->FindPinChecked(LifetimeState_ParamName);
	UEdGraphPin* CallCreateResult = CallCreateNode->GetReturnValuePin();

	// Move 'exec' connection from create widget node to 'FlowStateMachineLibrary::CreateAndBindWidget'
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeExec, *CallCreateExec);

	if ( SpawnClassPin->LinkedTo.Num() > 0 )
	{
		// Copy the 'blueprint' connection from the spawn node to 'FlowStateMachineLibrary::CreateAndBindWidget'
		CompilerContext.MovePinLinksToIntermediate(*SpawnClassPin, *CallCreateWidgetTypePin);
	}
	else
	{
		// Copy blueprint literal onto 'FlowStateMachineLibrary::CreateAndBindWidget' call
		CallCreateWidgetTypePin->DefaultObject = SpawnClass;
	}

	// Copy the world context connection from the spawn node to 'FlowStateMachineLibrary::CreateAndBindWidget' if necessary
	if ( SpawnWorldContextPin )
	{
		CompilerContext.MovePinLinksToIntermediate(*SpawnWorldContextPin, *CallCreateWorldContextPin);
	}

	// Copy the 'Widget' connection from the spawn node to 'FlowStateMachineLibrary::CreateAndBindWidget'
	CompilerContext.MovePinLinksToIntermediate(*WidgetLayoutPin, *CallCreateWidgetLayoutPin);
	CompilerContext.MovePinLinksToIntermediate(*SlotTagPin, *CallCreateSlotTagPin);

	// if for some reason we couldn't find scale method pin on the spawn node, defer it's value to runtime
	CompilerContext.MovePinLinksToIntermediate(*LifetimeStatePin, *CallCreateLifetimeStatePin);

	// Move result connection from spawn node to 'FlowStateMachineLibrary::CreateAndBindWidget'
	CallCreateResult->PinType = SpawnNodeResult->PinType; // Copy type so it uses the right actor subclass
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeResult, *CallCreateResult);

	//////////////////////////////////////////////////////////////////////////
	// create 'set var' nodes

	// Get 'result' pin from 'begin spawn', this is the actual actor we want to set properties on
	UEdGraphPin* LastThen = FKismetCompilerUtilities::GenerateAssignmentNodes(CompilerContext, SourceGraph, CallCreateNode, CreateWidgetNode, CallCreateResult, ClassToSpawn);

	// Move 'then' connection from create widget node to the last 'then'
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeThen, *LastThen);

	// Break any links to the expanded node
	CreateWidgetNode->BreakAllNodeLinks();
}

TSharedPtr<SGraphNode> UK2Node_CreateAndBindWidget::CreateVisualWidget()
{
	// return Super::CreateVisualWidget();
	return SNew(SMyGraphNodeCreateWidget, this);
	// return SNew(SGraphNodeCreateWidget, this);
}

void UK2Node_CreateAndBindWidget::PinDefaultValueChanged(UEdGraphPin* ChangedPin)
{
	Super::PinDefaultValueChanged(ChangedPin);
	// GetGraph()->NotifyNodeChanged(this);
}

FText UK2Node_CreateAndBindWidget::GetMenuCategory() const
{
	return FEditorCategoryUtils::GetCommonCategory(FCommonEditorCategory::UserInterface);
}

FName UK2Node_CreateAndBindWidget::GetCornerIcon() const
{
	return TEXT("Graph.Replication.ClientEvent");
}

UEdGraphPin* UK2Node_CreateAndBindWidget::GetWidgetLayoutPin() const
{
	UEdGraphPin* Pin = FindPin(FK2Node_CreateAndBIndWidgetHelper::WidgetLayoutPinName);
	check(Pin && Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_CreateAndBindWidget::GetSlotTagPin() const
{
	UEdGraphPin* Pin = FindPin(FK2Node_CreateAndBIndWidgetHelper::WidgetSlotTagPinName);
	check(Pin && Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_CreateAndBindWidget::GetLifetimePin() const
{
	UEdGraphPin* Pin = FindPin(FK2Node_CreateAndBIndWidgetHelper::WidgetLifetimePinName);
	check(Pin && Pin->Direction == EGPD_Input);
	return Pin;
}

FText UK2Node_CreateAndBindWidget::GetBaseNodeTitle() const
{
	return LOCTEXT("CreateAndBindWidget_BaseTitle", "Create And Bind Widget");
}

FText UK2Node_CreateAndBindWidget::GetNodeTitleFormat() const
{
	return LOCTEXT("CreatAndBindWidget", "Create And Bind {ClassName} Widget");
}

UClass* UK2Node_CreateAndBindWidget::GetClassPinBaseClass() const
{
	return UUserWidget::StaticClass();
}

bool UK2Node_CreateAndBindWidget::IsSpawnVarPin(UEdGraphPin* Pin) const
{
	return(
		Super::IsSpawnVarPin(Pin) &&
		Pin->PinName != "Layout" &&
		Pin->PinName != "SlotTag" &&
		Pin->PinName != "Lifetime");
}

#undef LOCTEXT_NAMESPACE
#include "FlowStateMachine_EditorModule.h"

#include "EdGraphUtilities.h"
#include "FSMGraphEditor.h"
#include "SGraphPin.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "Node/FSMGraphNode.h"
#include "Node/FSMGraphSubNode.h"
#include "Slate/SFSMGraphNode_State.h"
#include "Slate/SFSMGraphNode_Root.h"
#include "Slate/SFSMGraphSubNode.h"
#include "RUntimeNode/FSMRuntimeNode.h"
#include "Node/FSMGraphNode_Root.h"
#include "Node/FSMGraphNode_State.h"
#include "Styling/SlateStyle.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_EditorModule"

const FName FFlowStateMachine_EditorModule::FlowStateMachineAppIdentifier = "FlowStateMachineEditor";

class FGraphPanelNodeFactory_FSM : public FGraphPanelNodeFactory
{
public:
	virtual TSharedPtr<class SGraphNode> CreateNode(class UEdGraphNode* Node) const override
	{
		if (UFSMGraphNode_Root* RootNode = Cast<UFSMGraphNode_Root>(Node))
		{
			return SNew(SFSMGraphNode_Root, RootNode);
		}
		if (UFSMGraphNode_State* StateNode = Cast<UFSMGraphNode_State>(Node))
		{
			return SNew(SFSMGraphNode_State, StateNode);
		}
		if (UFSMGraphSubNode* SubNode = Cast<UFSMGraphSubNode>(Node))
		{
			return SNew(SFSMGraphSubNode, SubNode);
		}
		return nullptr;
	}
};
/*class FGraphPanelPinFactory_FSM: public FGraphPanelPinFactory
{
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* Pin) const override
	{
		if (UFSMGraphPin* FSMPin = Cast<UFSMGraphPin>(Pin))
		{
			return SNew(SGraphPin);
		}
		return nullptr;
	}
};*/

void FFlowStateMachine_EditorModule::StartupModule()
{

	// 注册自定义的图表节点
	FEdGraphUtilities::RegisterVisualNodeFactory(MakeShareable(new FGraphPanelNodeFactory_FSM));
	// 注册自定义的图表引脚
	// FEdGraphUtilities::RegisterVisualPinFactory(MakeShareable(new FGraphPanelPinFactory_FSM));

	StyleSet = MakeShareable(new FSlateStyleSet("FlowStateMachineStyleSet"));


	FSlateImageBrush* NodeAddPinIcon = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeAddPinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* NodeDeletePinIcon = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeletePinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* NodeDeleteNodeIcon = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeleteNodeIcon"), TEXT(".png")), FVector2D(128.f, 128.f));

	StyleSet->Set("FlowStateMachineEditor.NodeAddPinIcon", NodeAddPinIcon);
	StyleSet->Set("FlowStateMachineEditor.NodeDeletePinIcon", NodeDeletePinIcon);
	StyleSet->Set("FlowStateMachineEditor.NodeDeleteNodeIcon", NodeDeleteNodeIcon);
}

void FFlowStateMachine_EditorModule::ShutdownModule()
{
	ClassCache.Reset();
}

TSharedRef<FFSMGraphEditor> FFlowStateMachine_EditorModule::CreateFlowStateMachineEditor(
	const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UObject* Object)
{
	if (!ClassCache.IsValid())
	{
		ClassCache = MakeShareable(new FGraphNodeClassHelper(UFSMRuntimeNodeBase::StaticClass()));
		// FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTTask_BlueprintBase::StaticClass());
		// FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTDecorator_BlueprintBase::StaticClass());
		// FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTService_BlueprintBase::StaticClass());
		ClassCache->UpdateAvailableBlueprintClasses();
	}
	TSharedRef< FFSMGraphEditor > NewBehaviorTreeEditor( new FFSMGraphEditor() );
	NewBehaviorTreeEditor->InitFlowStateMachineEditor( Mode, InitToolkitHost, Object );
	return NewBehaviorTreeEditor;	
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FFlowStateMachine_EditorModule, FlowStateMachine_Editor)
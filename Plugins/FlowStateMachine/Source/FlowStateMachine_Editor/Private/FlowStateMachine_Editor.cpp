#include "FlowStateMachine_Editor.h"

#include "FSMGraphEditor.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "SM/FSMRuntimeNode.h"
#include "Styling/SlateStyle.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_EditorModule"

const FName FFlowStateMachine_EditorModule::FlowStateMachineAppIdentifier = "FlowStateMachineEditor";

void FFlowStateMachine_EditorModule::StartupModule()
{


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
		ClassCache = MakeShareable(new FGraphNodeClassHelper(UFSMRuntimeNode::StaticClass()));
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
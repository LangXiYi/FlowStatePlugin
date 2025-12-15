#include "FlowStateMachine_Editor.h"

#include "..\Public\FSMGraphEditor.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_EditorModule"

const FName FFlowStateMachine_EditorModule::FlowStateMachineAppIdentifier = "FlowStateMachineEditor";

void FFlowStateMachine_EditorModule::StartupModule()
{
    
}

void FFlowStateMachine_EditorModule::ShutdownModule()
{
    
}

TSharedRef<FFSMGraphEditor> FFlowStateMachine_EditorModule::CreateFlowStateMachineEditor(
	const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UObject* Object)
{
	/*if (!ClassCache.IsValid())
	{
		ClassCache = MakeShareable(new FGraphNodeClassHelper(UBTNode::StaticClass()));
		FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTTask_BlueprintBase::StaticClass());
		FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTDecorator_BlueprintBase::StaticClass());
		FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTService_BlueprintBase::StaticClass());
		ClassCache->UpdateAvailableBlueprintClasses();
	}*/
	TSharedRef< FFSMGraphEditor > NewBehaviorTreeEditor( new FFSMGraphEditor() );
	NewBehaviorTreeEditor->InitFlowStateMachineEditor( Mode, InitToolkitHost, Object );
	return NewBehaviorTreeEditor;	
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FFlowStateMachine_EditorModule, FlowStateMachine_Editor)
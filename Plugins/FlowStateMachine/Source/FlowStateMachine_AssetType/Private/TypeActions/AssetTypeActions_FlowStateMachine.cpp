#include "TypeActions/AssetTypeActions_FlowStateMachine.h"

#include "FlowStateMachine_Editor.h"
#include "SM/FlowStateMachine.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions_FlowStateMachine"


void FAssetTypeActions_FlowStateMachine::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	// Open my custom editor
	for(auto Object : InObjects)
	{
		auto FlowStateMachine = Cast<UFlowStateMachine>(Object);
		if(FlowStateMachine != nullptr)
		{
			FFlowStateMachine_EditorModule& FlowStateMachineEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>( "FlowStateMachine_Editor" );
			auto NewEditor = FlowStateMachineEditorModule.CreateFlowStateMachineEditor( Mode, EditWithinLevelEditor, FlowStateMachine );	
		}
	}
}


#undef LOCTEXT_NAMESPACE

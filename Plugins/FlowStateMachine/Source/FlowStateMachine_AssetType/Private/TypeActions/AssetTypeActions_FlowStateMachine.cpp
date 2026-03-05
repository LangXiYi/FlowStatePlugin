#include "TypeActions/AssetTypeActions_FlowStateMachine.h"

#include "FlowStateEditorModule.h"
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
			FFlowStateEditorModule& FlowStateMachineEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>( "FlowStateMachine_Editor" );
			auto NewEditor = FlowStateMachineEditorModule.CreateFlowStateMachineEditor( Mode, EditWithinLevelEditor, FlowStateMachine );	
		}
	}
}


#undef LOCTEXT_NAMESPACE

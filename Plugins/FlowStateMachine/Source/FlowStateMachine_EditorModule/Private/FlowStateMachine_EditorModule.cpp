#include "FlowStateMachine_EditorModule.h"

#include "AssetToolsModule.h"
#include "TypeActions/AssetTypeActions_FlowState.h"
#include "TypeActions/AssetTypeActions_FlowStateContext.h"
#include "TypeActions/AssetTypeActions_FlowStateData.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_EditorModule"

void FFlowStateMachine_EditorModule::StartupModule()
{
	// Register Asset Type
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowState));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateData));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateContext));
}

void FFlowStateMachine_EditorModule::ShutdownModule()
{
	// Unregister Asset Type
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
}

void FFlowStateMachine_EditorModule::RegisterAssetTypeAction(class IAssetTools& AssetTools,
	TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FFlowStateMachine_EditorModule, FlowStateMachine_EditorModule)
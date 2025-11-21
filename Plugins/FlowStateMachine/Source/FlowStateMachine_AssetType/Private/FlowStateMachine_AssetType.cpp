#include "FlowStateMachine_AssetType.h"

#include "AssetToolsModule.h"
#include "TypeActions/AssetTypeActions_FlowState.h"
#include "TypeActions/AssetTypeActions_FlowStateData.h"
#include "TypeActions/AssetTypeActions_FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_AssetTypeModule"

void FFlowStateMachine_AssetTypeModule::StartupModule()
{
	// Register Asset Type
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowState));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateData));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateMachine));
}

void FFlowStateMachine_AssetTypeModule::ShutdownModule()
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

void FFlowStateMachine_AssetTypeModule::RegisterAssetTypeAction(class IAssetTools& AssetTools,
	TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FFlowStateMachine_AssetTypeModule, FlowStateMachine_AssetType)
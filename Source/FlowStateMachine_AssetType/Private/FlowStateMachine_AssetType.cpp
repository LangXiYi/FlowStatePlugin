#include "FlowStateMachine_AssetType.h"

#include "AssetToolsModule.h"
#include "TypeActions/AssetTypeActions_FlowState.h"
#include "TypeActions/AssetTypeActions_FlowStateData.h"
#include "TypeActions/AssetTypeActions_FlowStateMachine.h"
#include "Utility/FSMUtility.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachine_AssetTypeModule"

void FFlowStateMachine_AssetTypeModule::StartupModule()
{
	// Register Asset Type
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowState));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateData));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateMachine));

	// Register Property Type Layout
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	// RegisterPropertyTypeLayout(PropertyEditorModule, "JumpStateId", MakeShareable(new FJumpStateIdCustomization));
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

	// Unregister Property Type Layout
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		for (int32 Index = 0; Index < CreatedPropertyTypeLayouts.Num(); ++Index)
		{
			PropertyEditorModule.UnregisterCustomPropertyTypeLayout(CreatedPropertyTypeLayouts[Index]);
		}
	}
}

void FFlowStateMachine_AssetTypeModule::RegisterAssetTypeAction(class IAssetTools& AssetTools,
	TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

void FFlowStateMachine_AssetTypeModule::RegisterPropertyTypeLayout(FPropertyEditorModule& PropertyEditorModule, FName PropertyName, TSharedRef<IPropertyTypeCustomization> TypeCustomization)
{
	PropertyEditorModule.RegisterCustomPropertyTypeLayout(PropertyName, FOnGetPropertyTypeCustomizationInstance::CreateLambda(
	[TypeCustomization]()->TSharedRef<IPropertyTypeCustomization> 
	{
		return TypeCustomization;
	}));
	CreatedPropertyTypeLayouts.Add(PropertyName);
	PropertyEditorModule.NotifyCustomizationModuleChanged();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FFlowStateMachine_AssetTypeModule, FlowStateMachine_AssetType)
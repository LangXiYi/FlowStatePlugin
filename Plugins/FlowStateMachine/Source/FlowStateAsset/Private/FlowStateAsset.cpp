#include "FlowStateAsset.h"

#include "AssetToolsModule.h"
#include "FlowStateStyleSet.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "TypeActions/AssetTypeActions_FlowState.h"
#include "TypeActions/AssetTypeActions_FlowStateData.h"
#include "TypeActions/AssetTypeActions_FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FFlowStateAssetModule"

void FFlowStateAssetModule::StartupModule()
{
    // Register Asset Type
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
    RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowState));
    RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateData));
    RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_FlowStateMachine));

    // Register Property Type Layout
    FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    
    // 自定义资产略缩图
    StateStyleSet = MakeShareable(new FFlowStateStyleSet("FlowStateMachine"));
    StateStyleSet->RegisterAssetThumbnail("FlowStateMachine", "FlowStateMachine_64x.png", FVector2D(64, 64));
    StateStyleSet->RegisterAssetThumbnail("FlowStateBlueprint", "Icon_FlowStateMachine.png", FVector2D(64, 64));
    StateStyleSet->RegisterAssetThumbnail("FlowStateBase", "Icon_FlowStateMachine.png", FVector2D(64, 64));
    FSlateStyleRegistry::RegisterSlateStyle(*StateStyleSet);
}

void FFlowStateAssetModule::ShutdownModule()
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
    
    // 注销所有样式
    FSlateStyleRegistry::UnRegisterSlateStyle(*StateStyleSet);
}

void FFlowStateAssetModule::RegisterAssetTypeAction(class IAssetTools& AssetTools,
    TSharedRef<IAssetTypeActions>                                      Action)
{
    AssetTools.RegisterAssetTypeActions(Action);
    CreatedAssetTypeActions.Add(Action);
}

void FFlowStateAssetModule::RegisterPropertyTypeLayout(FPropertyEditorModule& PropertyEditorModule, FName PropertyName, TSharedRef<IPropertyTypeCustomization> TypeCustomization)
{
    PropertyEditorModule.RegisterCustomPropertyTypeLayout(PropertyName, FOnGetPropertyTypeCustomizationInstance::CreateLambda(
                                                                            [TypeCustomization]() -> TSharedRef<IPropertyTypeCustomization> {
        return TypeCustomization;
    }));
    CreatedPropertyTypeLayouts.Add(PropertyName);
    PropertyEditorModule.NotifyCustomizationModuleChanged();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFlowStateAssetModule, FlowStateAsset)
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FFlowStateStyleSet;
class IAssetTypeActions;

class FFlowStateAssetModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    
protected:
    void RegisterAssetTypeAction(class IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> ActionPtr);
    void RegisterPropertyTypeLayout(class FPropertyEditorModule& PropertyEditorModule, FName PropertyName, TSharedRef<IPropertyTypeCustomization> TypeCustomization);

    TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
    TArray<FName> CreatedPropertyTypeLayouts;

    // 所有样式集合
    TSharedPtr<FFlowStateStyleSet>  StateStyleSet;
};

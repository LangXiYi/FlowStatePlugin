#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSlateStyleSet;
class FFSMGraphEditor;
class IFlowStateMachineEditor;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUpdateStateCollect, UBlueprint*);

/**
 * 在移动类的文件路径后，使用复制会报错，注意检查问题
 */
class FFlowStateEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual TSharedRef<FFSMGraphEditor> CreateFlowStateMachineEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UObject* Object);

    TSharedPtr<struct FGraphNodeClassHelper> GetClassCache() { return ClassCache; }

    ////////////////////////////////////////////////////
    /// Events
    ////////////////////////////////////////////////////
    void OnAssetAdded(const FAssetData& AssetData);

    void OnBlueprintCompiled(UBlueprint* Blueprint);

    FOnUpdateStateCollect OnUpdateStateCollect;

    static const FName FlowStateMachineAppIdentifier;

private:
    TSharedPtr<struct FGraphNodeClassHelper> ClassCache;

    TSharedPtr<FSlateStyleSet> StyleSet;

    FDelegateHandle AssetAddedHandle;
};

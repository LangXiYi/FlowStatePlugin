#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSlateStyleSet;
class FFlowStateMachineEditor;
class IFlowStateMachineEditor;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnUpdateStateCollect, UBlueprint*);

/**
 * 在移动类的文件路径后，使用复制会报错，注意检查问题
 */
class FLOWSTATEEDITOR_API FFlowStateEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    TSharedRef<FFlowStateMachineEditor> CreateFlowStateMachineEditor(const EToolkitMode::Type Mode,
                                                                     const TSharedPtr<class IToolkitHost>&
                                                                     InitToolkitHost, class UObject* Object);

    TSharedPtr<struct FGraphNodeClassHelper> GetClassCache() { return ClassCache; }

    ////////////////////////////////////////////////////
    /// Events
    ////////////////////////////////////////////////////
    void OnAssetAdded(const FAssetData& AssetData);

    void OnBlueprintCompiled(UBlueprint* Blueprint);

    FOnUpdateStateCollect OnUpdateStateCollect;

private:
    /** 节点类型缓存，会自动收集符合条件的类型加入缓存，引用自行为树模块 */
    TSharedPtr<struct FGraphNodeClassHelper> ClassCache;

    /** 状态机的样式集合 */
    TSharedPtr<FSlateStyleSet> StyleSet;

    FDelegateHandle AssetAddedHandle;
};

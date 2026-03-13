#include "FlowStateEditorModule.h"

#include "FlowStateMachineEditor.h"
// 仅使用 ClasCollect
#include "AIGraph/Classes/AIGraphTypes.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Styling/SlateStyle.h"

#include "NodeInstance/FSMNodeInstanceBase.h"
#include "Utility/FlowStateEditorHelper.h"

#define LOCTEXT_NAMESPACE "FFlowStateEditorModule"

USING_FLOWSTATE_EDITORHELPER

void FFlowStateEditorModule::StartupModule()
{
    // 注册自定义的图表节点
    // FEdGraphUtilities::RegisterVisualNodeFactory(MakeShareable(new FGraphPanelNodeFactory_FSM));
    // 注册自定义的图表引脚
    // FEdGraphUtilities::RegisterVisualPinFactory(MakeShareable(new FGraphPanelPinFactory_FSM));

    /*StyleSet = MakeShareable(new FSlateStyleSet("FlowStateMachineStyleSet"));

    FSlateImageBrush* NodeAddPinIcon     = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeAddPinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
    FSlateImageBrush* NodeDeletePinIcon  = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeletePinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
    FSlateImageBrush* NodeDeleteNodeIcon = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeleteNodeIcon"), TEXT(".png")), FVector2D(128.f, 128.f));

    StyleSet->Set("FlowStateMachineEditor.NodeAddPinIcon", NodeAddPinIcon);
    StyleSet->Set("FlowStateMachineEditor.NodeDeletePinIcon", NodeDeletePinIcon);
    StyleSet->Set("FlowStateMachineEditor.NodeDeleteNodeIcon", NodeDeleteNodeIcon);*/

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(
        TEXT("AssetRegistry"));
    // 监听 AssetRegister 的资产加载事件，
    // AssetAddedHandle = AssetRegistryModule.Get().OnAssetAdded().AddRaw(this, &FFlowStateEditorModule::OnAssetAdded);
    // 监听资产改变事件，当改变的目标类型为蓝图时触发收集事件，会自动收集状态的执行引脚
    AssetRegistryModule.Get().OnAssetUpdated().AddLambda([this](const FAssetData& AssetData)
    {
        if (UBlueprint* BlueprintAsset = Cast<UBlueprint>(AssetData.GetAsset());)
        {
            OnBlueprintCompiled(BlueprintAsset);
        }
    });
}

void FFlowStateEditorModule::ShutdownModule()
{
    ClassCache.Reset();
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(
        TEXT("AssetRegistry"));
    AssetRegistryModule.Get().OnAssetAdded().Remove(AssetAddedHandle);

    // 正常来说这里应该需要解除绑定的蓝图编译事件的，但是编辑器的生命周期在引擎阶段，所以影响也不大，可以不做处理，当然如果出现了bug还是需要额外处理的，
    // 不过，暂时也够用了。
}

TSharedRef<FFlowStateMachineEditor> FFlowStateEditorModule::CreateFlowStateMachineEditor(
    const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UObject* Object)
{
    if (!ClassCache.IsValid())
    {
        // TODO::如果状态机图表需要缓存更多的类型，需要修改这部分的代码，添加新的缓存类型
        ClassCache = MakeShareable(new FGraphNodeClassHelper(UFSMNodeInstanceBase::StaticClass()));
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTTask_BlueprintBase::StaticClass());
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTDecorator_BlueprintBase::StaticClass());
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTService_BlueprintBase::StaticClass());
        ClassCache->UpdateAvailableBlueprintClasses();
    }
    TSharedRef<FFlowStateMachineEditor> NewBehaviorTreeEditor(new FFlowStateMachineEditor());
    NewBehaviorTreeEditor->InitFlowStateMachineEditor(Mode, InitToolkitHost, Object);
    return NewBehaviorTreeEditor;
}

void FFlowStateEditorModule::OnAssetAdded(const FAssetData& AssetData)
{
    UClass* AssetClass = AssetData.GetClass();
    if (AssetClass->IsChildOf(UBlueprint::StaticClass()))
    {
        // 如果添加的资产是蓝图资产，则监听该蓝图编译事件
        UBlueprint* BlueprintAsset = Cast<UBlueprint>(AssetData.GetAsset());
        BlueprintAsset->OnCompiled().AddRaw(this, &FFlowStateEditorModule::OnBlueprintCompiled);
    }
}

void FFlowStateEditorModule::OnBlueprintCompiled(UBlueprint* Blueprint)
{
    if (Blueprint->GeneratedClass->ImplementsInterface(UFlowStateCollectInterface::StaticClass()))
    {
        OnUpdateStateCollect.Broadcast(Blueprint);
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFlowStateEditorModule, FlowStateEditor)

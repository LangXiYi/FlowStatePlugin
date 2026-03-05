#include "FlowStateEditorModule.h"

#include "EdGraphUtilities.h"
#include "FSMGraphEditor.h"
#include "SGraphPin.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Node/FSGraphNode.h"
#include "Node/FSGraph_RootNode.h"
#include "Node/FSGraphSubNode.h"
#include "Node/Composites/Composite_JumpNode.h"
#include "Slate/SFSMGraphNode_State.h"
#include "Slate/SFSMGraphNode_Root.h"
#include "Slate/SFSMGraphSubNode.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "Slate/SFSMGraphNode_JumpStart.h"
#include "Slate/SFSMGraphNode_JumpTo.h"
#include "Styling/SlateStyle.h"

#define LOCTEXT_NAMESPACE "FFlowStateEditorModule"

const FName FFlowStateEditorModule::FlowStateMachineAppIdentifier = "FlowStateMachineEditor";

class FGraphPanelNodeFactory_FSM : public FGraphPanelNodeFactory
{
public:
    virtual TSharedPtr<class SGraphNode> CreateNode(class UEdGraphNode* Node) const override
    {
        if (UFSGraph_RootNode* RootNode = Cast<UFSGraph_RootNode>(Node))
        {
            return SNew(SFSMGraphNode_Root, RootNode);
        }
        /*if (UFSMGraphNode_State* StateNode = Cast<UFSMGraphNode_State>(Node))
        {
            return SNew(SFSMGraphNode_State, StateNode);
        }*/
        if (UFSGraphSubNode* SubNode = Cast<UFSGraphSubNode>(Node))
        {
            return SNew(SFSMGraphSubNode, SubNode);
        }
        if (UGraphCNode_JumpTo* GraphNode = Cast<UGraphCNode_JumpTo>(Node))
        {
            return SNew(SFSMGraphNode_JumpTo, GraphNode);
        }
        if (UGraphCNode_JumpStart* GraphNode = Cast<UGraphCNode_JumpStart>(Node))
        {
            return SNew(SFSMGraphNode_JumpStart, GraphNode);
        }
        return nullptr;
    }
};
/*class FGraphPanelPinFactory_FSM: public FGraphPanelPinFactory
{
    virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* Pin) const override
    {
        if (UFSMGraphPin* FSMPin = Cast<UFSMGraphPin>(Pin))
        {
            return SNew(SGraphPin);
        }
        return nullptr;
    }
};*/

void FFlowStateEditorModule::StartupModule()
{
    // 注册自定义的图表节点
    FEdGraphUtilities::RegisterVisualNodeFactory(MakeShareable(new FGraphPanelNodeFactory_FSM));
    // 注册自定义的图表引脚
    // FEdGraphUtilities::RegisterVisualPinFactory(MakeShareable(new FGraphPanelPinFactory_FSM));

    StyleSet = MakeShareable(new FSlateStyleSet("FlowStateMachineStyleSet"));

    FSlateImageBrush* NodeAddPinIcon     = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeAddPinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
    FSlateImageBrush* NodeDeletePinIcon  = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeletePinIcon"), TEXT(".png")), FVector2D(128.f, 128.f));
    FSlateImageBrush* NodeDeleteNodeIcon = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("NodeDeleteNodeIcon"), TEXT(".png")), FVector2D(128.f, 128.f));

    StyleSet->Set("FlowStateMachineEditor.NodeAddPinIcon", NodeAddPinIcon);
    StyleSet->Set("FlowStateMachineEditor.NodeDeletePinIcon", NodeDeletePinIcon);
    StyleSet->Set("FlowStateMachineEditor.NodeDeleteNodeIcon", NodeDeleteNodeIcon);

    // 监听 AssetRegister 的资产加载事件，
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
    AssetAddedHandle                          = AssetRegistryModule.Get().OnAssetAdded().AddRaw(this, &FFlowStateEditorModule::OnAssetAdded);
}

void FFlowStateEditorModule::ShutdownModule()
{
    ClassCache.Reset();

    /*FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
    AssetRegistryModule.Get().OnAssetAdded().Remove(AssetAddedHandle);*/

    // 正常来说这里应该需要解除绑定的蓝图编译事件的，但是编辑器的生命周期在引擎阶段，所以影响也不大，可以不做处理，当然如果出现了bug还是需要额外处理的，
    // 不过，暂时也够用了。
}

TSharedRef<FFSMGraphEditor> FFlowStateEditorModule::CreateFlowStateMachineEditor(
    const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, class UObject* Object)
{
    if (!ClassCache.IsValid())
    {
        ClassCache = MakeShareable(new FGraphNodeClassHelper(UFSMNodeInstanceBase::StaticClass()));
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTTask_BlueprintBase::StaticClass());
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTDecorator_BlueprintBase::StaticClass());
        // FGraphNodeClassHelper::AddObservedBlueprintClasses(UBTService_BlueprintBase::StaticClass());
        ClassCache->UpdateAvailableBlueprintClasses();
    }
    TSharedRef<FFSMGraphEditor> NewBehaviorTreeEditor(new FFSMGraphEditor());
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
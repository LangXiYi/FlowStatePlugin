#include "Slate/SFSGraphPalette.h"

#include "FlowStateEditorModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "EdGraph/EdGraphSchema.h"
#include "Graph/FlowStateGraphSchema.h"
#include "Node/FSGraph_StateNode.h"

#include "Node/FSGraphSubNode.h"
#include "SM/Composites/FlowStateComposite.h"
#include "SM/Actions/FlowStateAction.h"
#include "SM/FlowStateBase.h"
#include "SM/Conditions/FlowStateCondition.h"
#include "SM/FlowStateMachine.h"
#include "SM/Services/FlowStateService.h"

void SFSGraphPalette::Construct(const FArguments& InArgs, UFlowStateMachine* InAsset)
{
    FSMAsset = InAsset;

    // Auto expand the palette as there's so few nodes
    SGraphPalette::Construct(SGraphPalette::FArguments().AutoExpandActionMenu(true));

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
    DelegateHandles.Add(AssetRegistryModule.Get().OnAssetAdded().AddSP(this, &SFSGraphPalette::AddAssetFromAssetRegistry));
    DelegateHandles.Add(AssetRegistryModule.Get().OnAssetRemoved().AddSP(this, &SFSGraphPalette::RemoveAssetFromRegistry));
    DelegateHandles.Add(AssetRegistryModule.Get().OnAssetRenamed().AddSP(this, &SFSGraphPalette::RenameAssetFromRegistry));
}

void SFSGraphPalette::RefreshActionsList(bool bPreserveExpansion)
{
    SGraphPalette::RefreshActionsList(bPreserveExpansion);
}

void SFSGraphPalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
    FFlowStateEditorModule&           FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>("FlowStateEditor");
    TSharedPtr<FGraphNodeClassHelper> ClassCache      = FSMEditorModule.GetClassCache();

    // Node
    FCategorizedGraphActionListBuilder StateAction("FlowState");
    UFlowStateGraphSchema::CollectNewNodeAction(
        StateAction,
        UFlowStateBase::StaticClass(),
        UFSGraph_StateNode::StaticClass(),
        FSMAsset->FSMGraph);

    // Composites Nodes
    FCategorizedGraphActionListBuilder CompositesAction("Composites");
    TArray<FGraphNodeClassData>        CompositesNodeClasses;
    ClassCache->GatherClasses(UFlowStateComposite::StaticClass(), CompositesNodeClasses);
    for (FGraphNodeClassData& NodeClass : CompositesNodeClasses)
    {
        UClass* CompositesGraphNodeClass = UFlowStateGraphSchema::GetCompositesGraphNodeClass(NodeClass.GetClass());
        UFlowStateGraphSchema::CollectNewNodeAction(
            CompositesAction,
            NodeClass.GetClass(),
            CompositesGraphNodeClass,
            FSMAsset->FSMGraph);
    }

    // Sub Nodes
    FCategorizedGraphActionListBuilder ActionAction("SubNode|Action");
    UFlowStateGraphSchema::CollectNewSubNodeAction(
        ActionAction,
        UFlowStateAction::StaticClass(),
        UFSMGraphSubNode_Action::StaticClass(),
        FSMAsset->FSMGraph);

    FCategorizedGraphActionListBuilder ServiceAction("SubNode|Service");
    UFlowStateGraphSchema::CollectNewSubNodeAction(
        ServiceAction,
        UFlowStateService::StaticClass(),
        UFSMGraphSubNode_Service::StaticClass(),
        FSMAsset->FSMGraph);

    FCategorizedGraphActionListBuilder ConditionAction("SubNode|Condition");
    UFlowStateGraphSchema::CollectNewSubNodeAction(
        ConditionAction,
        UFlowStateCondition::StaticClass(),
        UFSMGraphSubNode_Condition::StaticClass(),
        FSMAsset->FSMGraph);

    OutAllActions.Append(StateAction);
    OutAllActions.Append(CompositesAction);

    OutAllActions.Append(ActionAction);
    OutAllActions.Append(ServiceAction);
    OutAllActions.Append(ConditionAction);
}

void SFSGraphPalette::AddAssetFromAssetRegistry(const FAssetData& AssetData)
{
    RefreshAssetInRegistry(AssetData);
}

void SFSGraphPalette::RemoveAssetFromRegistry(const FAssetData& AssetData)
{
    RefreshAssetInRegistry(AssetData);
}

void SFSGraphPalette::RenameAssetFromRegistry(const FAssetData& AssetData, const FString& String)
{
    RefreshAssetInRegistry(AssetData);
}

void SFSGraphPalette::RefreshAssetInRegistry(const FAssetData& InAddedAssetData)
{
    // Grab the asset class, it will be checked for being a material function.
    UObject* Asset = FindObject<UObject>(ANY_PACKAGE, *InAddedAssetData.ObjectPath.ToString());
    if (Asset == nullptr)
    {
        return;
    }
    if (Asset->IsA(UFSMNodeInstanceBase::StaticClass()))
    {
        RefreshActionsList(true);
    }
    // 因为加载进来的是资产对象而非实例，所以需要额外判定是否是蓝图资产，若是蓝图资产，则需要使用ParentClass进行判断
    UBlueprint* BlueprintAsset = Cast<UBlueprint>(Asset);
    if (BlueprintAsset && BlueprintAsset->ParentClass->IsChildOf(UFSMNodeInstanceBase::StaticClass()))
    {
        RefreshActionsList(true);
    }
}
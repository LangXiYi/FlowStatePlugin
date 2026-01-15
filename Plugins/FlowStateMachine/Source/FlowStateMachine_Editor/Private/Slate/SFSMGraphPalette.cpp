#include "Slate/SFSMGraphPalette.h"

#include "FlowStateMachine_EditorModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "EdGraph/EdGraphSchema.h"
#include "Graph/Schema/EdGraphSchema_FSM.h"
#include "Node/FSMGraphNode_Composites.h"
#include "Node/FSMGraphNode_State.h"
#include "Node/FSMGraphSubNode.h"
#include "Node/Composites/FSMGraphNode_Branch.h"
#include "Node/Composites/FSMGraphNode_Jump.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "RuntimeNode/FSMRuntimeNode_State.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"
#include "SM/FlowStateMachine.h"

void SFSMGraphPalette::Construct(const FArguments& InArgs, UFlowStateMachine* InAsset)
{
	FSMAsset = InAsset;
	OwnerOfTemporaries =  NewObject<UEdGraph>((UObject*)GetTransientPackage());

	// Auto expand the palette as there's so few nodes
	SGraphPalette::Construct(SGraphPalette::FArguments().AutoExpandActionMenu(true));

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::GetModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	DelegateHandles.Add(AssetRegistryModule.Get().OnAssetAdded().AddSP(this, &SFSMGraphPalette::AddAssetFromAssetRegistry));
	DelegateHandles.Add(AssetRegistryModule.Get().OnAssetRemoved().AddSP(this, &SFSMGraphPalette::RemoveAssetFromRegistry));
	DelegateHandles.Add(AssetRegistryModule.Get().OnAssetRenamed().AddSP(this, &SFSMGraphPalette::RenameAssetFromRegistry));
}

void SFSMGraphPalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	FFlowStateMachine_EditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>("FlowStateMachine_Editor");
	TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();
	
	// Node
	FCategorizedGraphActionListBuilder StateAction("FlowState");
	UEdGraphSchema_FSM::CollectNewNodeAction(
		StateAction,
		UFSMRuntimeNode_State::StaticClass(),
		UFSMGraphNode_State::StaticClass(),
		OwnerOfTemporaries);

	// Composites Nodes
	FCategorizedGraphActionListBuilder CompositesAction("Composites");
	TArray<FGraphNodeClassData> CompositesNodeClasses;
	ClassCache->GatherClasses(UFSMRuntimeNode_Composites::StaticClass(), CompositesNodeClasses);
	for (FGraphNodeClassData& NodeClass : CompositesNodeClasses)
	{
		UClass* CompositesGraphNodeClass = UEdGraphSchema_FSM::GetCompositesGraphNodeClass(NodeClass.GetClass());
		UEdGraphSchema_FSM::CollectNewNodeAction(
			CompositesAction,
			NodeClass.GetClass(),
			CompositesGraphNodeClass,
			OwnerOfTemporaries);
	}

	// Sub Nodes
	FCategorizedGraphActionListBuilder ActionAction("SubNode|Action");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(
		ActionAction,
		UFSMRuntimeSubNode_Action::StaticClass(),
		UFSMGraphSubNode_Action::StaticClass(),
		OwnerOfTemporaries);
	
	FCategorizedGraphActionListBuilder ServiceAction("SubNode|Service");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(
		ServiceAction,
		UFSMRuntimeSubNode_Service::StaticClass(),
		UFSMGraphSubNode_Service::StaticClass(),
		OwnerOfTemporaries);

	FCategorizedGraphActionListBuilder ConditionAction("SubNode|Condition");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(
		ConditionAction,
		UFSMRuntimeSubNode_Condition::StaticClass(),
		UFSMGraphSubNode_Condition::StaticClass(),
		OwnerOfTemporaries);

	OutAllActions.Append(StateAction);
	OutAllActions.Append(CompositesAction);

	OutAllActions.Append(ActionAction);
	OutAllActions.Append(ServiceAction);
	OutAllActions.Append(ConditionAction);
}

void SFSMGraphPalette::AddAssetFromAssetRegistry(const FAssetData& AssetData)
{
	RefreshAssetInRegistry(AssetData);
}

void SFSMGraphPalette::RemoveAssetFromRegistry(const FAssetData& AssetData)
{
	RefreshAssetInRegistry(AssetData);
}

void SFSMGraphPalette::RenameAssetFromRegistry(const FAssetData& AssetData, const FString& String)
{
	RefreshAssetInRegistry(AssetData);
}

void SFSMGraphPalette::RefreshAssetInRegistry(const FAssetData& InAddedAssetData)
{
	// Grab the asset class, it will be checked for being a material function.
	UObject* Asset = FindObject<UObject>(ANY_PACKAGE, *InAddedAssetData.ObjectPath.ToString());
	if (Asset == nullptr)
	{
		return;
	}
	if (Asset->IsA(UFSMRuntimeNodeBase::StaticClass()))
	{
		RefreshActionsList(true);
	}
	// 因为加载进来的是资产对象而非实例，所以需要额外判定是否是蓝图资产，若是蓝图资产，则需要使用ParentClass进行判断
	UBlueprint* BlueprintAsset = Cast<UBlueprint>(Asset);
	if (BlueprintAsset && BlueprintAsset->ParentClass->IsChildOf(UFSMRuntimeNodeBase::StaticClass()))
	{
		RefreshActionsList(true);
	}
}
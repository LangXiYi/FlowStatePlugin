#include "Slate/SFSMGraphPalette.h"

#include "FlowStateMachine_EditorModule.h"
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
	
	// Auto expand the palette as there's so few nodes
	SGraphPalette::Construct(SGraphPalette::FArguments().AutoExpandActionMenu(true));
}

void SFSMGraphPalette::RefreshActionsList(bool bPreserveExpansion)
{
	SGraphPalette::RefreshActionsList(bPreserveExpansion);
}

void SFSMGraphPalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	FFlowStateMachine_EditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>("FlowStateMachine_Editor");
	TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();
	
	// Node
	FCategorizedGraphActionListBuilder StateAction("FlowState");
	UEdGraphSchema_FSM::CollectNewNodeAction(StateAction,
		UFSMRuntimeNode_State::StaticClass(),
		UFSMGraphNode_State::StaticClass(),
		FSMAsset->FSMGraph);

	// Composites Nodes
	FCategorizedGraphActionListBuilder CompositesAction("Composites");
	TArray<FGraphNodeClassData> CompositesNodeClasses;
	ClassCache->GatherClasses(UFSMRuntimeNode_Composites::StaticClass(), CompositesNodeClasses);
	for (FGraphNodeClassData& NodeClass : CompositesNodeClasses)
	{
		UClass* CompositesGraphNodeClass = UEdGraphSchema_FSM::GetCompositesGraphNodeClass(NodeClass.GetClass());
		UEdGraphSchema_FSM::CollectNewNodeAction(CompositesAction, NodeClass.GetClass(), CompositesGraphNodeClass, FSMAsset->FSMGraph);
	}

	// Sub Nodes
	FCategorizedGraphActionListBuilder ActionAction("SubNode|Action");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ActionAction,
		UFSMRuntimeSubNode_Action::StaticClass(),
		UFSMGraphSubNode_Action::StaticClass(),
		FSMAsset->FSMGraph);
	
	FCategorizedGraphActionListBuilder ServiceAction("SubNode|Service");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ServiceAction,
		UFSMRuntimeSubNode_Service::StaticClass(),
		UFSMGraphSubNode_Service::StaticClass(),
		FSMAsset->FSMGraph);

	FCategorizedGraphActionListBuilder ConditionAction("SubNode|Condition");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ConditionAction,
		UFSMRuntimeSubNode_Condition::StaticClass(),
		UFSMGraphSubNode_Condition::StaticClass(),
		FSMAsset->FSMGraph);

	OutAllActions.Append(StateAction);
	OutAllActions.Append(CompositesAction);

	OutAllActions.Append(ActionAction);
	OutAllActions.Append(ServiceAction);
	OutAllActions.Append(ConditionAction);
}

#include "Slate/SFSMGraphPalette.h"

#include "EdGraph/EdGraphSchema.h"
#include "Graph/Schema/EdGraphSchema_FSM.h"
#include "Node/FSMGraphNode_Composites.h"
#include "Node/FSMGraphNode_State.h"
#include "Node/FSMGraphSubNode.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "RuntimeNode/FSMRuntimeNode_State.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"

void SFSMGraphPalette::Construct(const FArguments& InArgs, class UEdGraph* InGraph)
{
	FSMGraph = InGraph;
	
	// Auto expand the palette as there's so few nodes
	SGraphPalette::Construct(SGraphPalette::FArguments().AutoExpandActionMenu(true));
}

void SFSMGraphPalette::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	// Node
	FCategorizedGraphActionListBuilder StateAction("FlowState");
	UEdGraphSchema_FSM::CollectNewNodeAction(StateAction,
		UFSMRuntimeNode_State::StaticClass(),
		UFSMGraphNode_State::StaticClass(),
		FSMGraph);

	FCategorizedGraphActionListBuilder CompositesAction("Composites");
	UEdGraphSchema_FSM::CollectNewNodeAction(CompositesAction,
		UFSMRuntimeNode_Composites::StaticClass(),
		UFSMGraphNode_Composites::StaticClass(),
		FSMGraph);

	// Sub Nodes
	FCategorizedGraphActionListBuilder ActionAction("SubNode|Action");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ActionAction,
		UFSMRuntimeSubNode_Action::StaticClass(),
		UFSMGraphSubNode_Action::StaticClass(),
		FSMGraph);
	
	FCategorizedGraphActionListBuilder ServiceAction("SubNode|Service");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ServiceAction,
		UFSMRuntimeSubNode_Service::StaticClass(),
		UFSMGraphSubNode_Service::StaticClass(),
		FSMGraph);

	FCategorizedGraphActionListBuilder ConditionAction("SubNode|Condition");
	UEdGraphSchema_FSM::CollectNewSubNodeAction(ConditionAction,
		UFSMRuntimeSubNode_Condition::StaticClass(),
		UFSMGraphSubNode_Condition::StaticClass(),
		FSMGraph);

	OutAllActions.Append(StateAction);
	OutAllActions.Append(CompositesAction);

	OutAllActions.Append(ActionAction);
	OutAllActions.Append(ServiceAction);
	OutAllActions.Append(ConditionAction);
}

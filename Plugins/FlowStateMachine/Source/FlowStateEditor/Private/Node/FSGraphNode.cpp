// Fill out your copyright notice in the Description page of Project Settings.

#include "Node/FSGraphNode.h"

#include "Utility/FlowStateEditorType.h"
#include "ToolMenu.h"
#include "Graph/FlowStateGraph.h"
#include "Node/FSGraphSubNode.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "SM/FlowStateMachine.h"
#include "Slate/SFSGraphNodeActionMenu.H"
#include "Utility/FlowStateEditorHelper.h"

#define LOCTEXT_NAMESPACE "FSMGraphNode"

bool UFSGraphNode::CanUserDeleteNode() const
{
    return Super::CanUserDeleteNode();
}

void UFSGraphNode::ResetNodeOwner()
{
    Super::ResetNodeOwner();

    for (auto& SubNode : SubNodes)
    {
        SubNode->ResetNodeOwner();
    }
}

void UFSGraphNode::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
    ensure(Pin.GetOwningNode() == this);
    HoverTextOut = Pin.PinName.ToString();
}

void UFSGraphNode::RemoveAllSubNode()
{
    SubNodes.Empty();

    Actions.Reset();
    Services.Reset();
    Conditions.Reset();
}

void UFSGraphNode::InitializeInstance()
{
    Super::InitializeInstance();
    if (UFSMNodeInstance* Node = Cast<UFSMNodeInstance>(NodeInstance))
    {
        // 初始化节点信息，如父级节点、节点深度、执行优先级等等，此时无实际意义。
        Node->InitializeNode(nullptr);
    }
}

void UFSGraphNode::OnSubNodeAdded(UFSGraphNodeBase* SubNode)
{
    if (UFSMGraphSubNode_Condition* ConditionNode = Cast<UFSMGraphSubNode_Condition>(SubNode))
    {
        Conditions.Add(ConditionNode);
    }
    else if (UFSMGraphSubNode_Service* ServiceNode = Cast<UFSMGraphSubNode_Service>(SubNode))
    {
        Services.Add(ServiceNode);
    }
    else if (UFSMGraphSubNode_Action* ActionNode = Cast<UFSMGraphSubNode_Action>(SubNode))
    {
        Actions.Add(ActionNode);
    }
}

void UFSGraphNode::AddSubNode(UFSGraphNodeBase* SubNode, class UEdGraph* ParentGraph)
{
    if (SubNode == nullptr)
    {
        checkNoEntry() return;
    }

    // const FScopedTransaction Transaction(LOCTEXT("AddNode", "Add Node"));
    ParentGraph->Modify();
    Modify();

    SubNode->SetFlags(RF_Transactional);

    // 设置节点 Outer 为 Graph 确保其不会被回收
    SubNode->Rename(nullptr, ParentGraph, REN_NonTransactional);
    SubNode->ParentNode = this;

    SubNode->CreateNewGuid();
    SubNode->PostPlacedNewNode();
    SubNode->AllocateDefaultPins();
    SubNode->AutowireNewNode(nullptr);

    SubNode->NodePosX = 0;
    SubNode->NodePosY = 0;

    SubNodes.Add(SubNode);
    OnSubNodeAdded(SubNode);

    MarkNodeRequiresSynchronization(true, "Add SubNode");
}

void UFSGraphNode::RemoveSubNode(UFSGraphNodeBase* SubNode)
{
    GetGraph()->Modify();
    Modify();
    SubNodes.RemoveSingle(SubNode);

    OnSubNodeRemoved(SubNode);

    MarkNodeRequiresSynchronization(true, "Remove SubNode");
}

void UFSGraphNode::OnSubNodeRemoved(UFSGraphNodeBase* SubNode)
{
    if (UFSMGraphSubNode_Condition* ConditionNode = Cast<UFSMGraphSubNode_Condition>(SubNode))
    {
        Conditions.RemoveSingle(ConditionNode);
    }
    else if (UFSMGraphSubNode_Service* ServiceNode = Cast<UFSMGraphSubNode_Service>(SubNode))
    {
        Services.RemoveSingle(ServiceNode);
    }
    else if (UFSMGraphSubNode_Action* ActionNode = Cast<UFSMGraphSubNode_Action>(SubNode))
    {
        Actions.RemoveSingle(ActionNode);
    }
}

void UFSGraphNode::AddConditionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
    FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
    Section.AddSubMenu(
        "AddCondition",
        LOCTEXT("ConditionLabel", "Add Condition..."),
        LOCTEXT("ConditionToolTip", "Adds new decorator as a subnode"),
        FNewToolMenuDelegate::CreateUObject(this, &UFSGraphNode::CreateAddConditionSubMenu, (UEdGraph*)Context->Graph));
}

void UFSGraphNode::AddActionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
    FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
    Section.AddSubMenu(
        "AddAction",
        LOCTEXT("ActionLabel", "Add Action..."),
        LOCTEXT("ActionToolTip", "Adds new action as a subnode"),
        FNewToolMenuDelegate::CreateUObject(this, &UFSGraphNode::CreateAddActionSubMenu, (UEdGraph*)Context->Graph));
}

void UFSGraphNode::AddServiceSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
    FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
    Section.AddSubMenu(
        "AddService",
        LOCTEXT("ServiceLabel", "Add Service..."),
        LOCTEXT("ServiceToolTip", "Adds new service as a subnode"),
        FNewToolMenuDelegate::CreateUObject(this, &UFSGraphNode::CreateAddServiceSubMenu, (UEdGraph*)Context->Graph));
}

void UFSGraphNode::CreateAddConditionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
    TSharedRef<SFSGraphNodeActionMenu> Widget =
        SNew(SFSGraphNodeActionMenu)
            .GraphObj(Graph)
            .GraphNode(const_cast<UFSGraphNode*>(this))
            .SubNodeFlags(ESubNodeType::Condition)
            .AutoExpandActionMenu(true);

    FToolMenuSection& Section = Menu->FindOrAddSection("Section");
    Section.AddEntry(FToolMenuEntry::InitWidget("ConditionWidget", Widget, FText(), true));
}

void UFSGraphNode::CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
    TSharedRef<SFSGraphNodeActionMenu> Widget =
        SNew(SFSGraphNodeActionMenu)
            .GraphObj(Graph)
            .GraphNode(const_cast<UFSGraphNode*>(this))
            .SubNodeFlags(ESubNodeType::Action)
            .AutoExpandActionMenu(true);

    FToolMenuSection& Section = Menu->FindOrAddSection("Section");
    Section.AddEntry(FToolMenuEntry::InitWidget("ActionWidget", Widget, FText(), true));
}

void UFSGraphNode::CreateAddServiceSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
    TSharedRef<SFSGraphNodeActionMenu> Widget =
        SNew(SFSGraphNodeActionMenu)
            .GraphObj(Graph)
            .GraphNode(const_cast<UFSGraphNode*>(this))
            .SubNodeFlags(ESubNodeType::Service)
            .AutoExpandActionMenu(true);

    FToolMenuSection& Section = Menu->FindOrAddSection("Section");
    Section.AddEntry(FToolMenuEntry::InitWidget("ServiceWidget", Widget, FText(), true));
}

#undef LOCTEXT_NAMESPACE


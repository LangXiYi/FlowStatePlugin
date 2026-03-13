#include "Node/Slates/SFSGraphSubNode.h"

#include "SGraphPanel.h"
#include "TutorialMetaData.h"
#include "Node/FSGraphSubNode.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "NodeInstance/FSMSubNodeInstance.h"
#include "SM/Conditions/FlowStateCondition.h"

void SFSGraphSubNode::Construct(const FArguments& InArgs, UFSGraphSubNode* InGraphNode)
{
    this->GraphNode = InGraphNode;

    this->SetCursor(EMouseCursor::CardinalCross);

    this->UpdateGraphNode();
}

FString SFSGraphSubNode::GetNodeComment() const
{
    const UFSMGraphSubNode_Condition* MyGraphNode = Cast<UFSMGraphSubNode_Condition>(GetNodeObj());
    const UFlowStateCondition* MyNodeInstance = MyGraphNode
                                                    ? Cast<UFlowStateCondition>(MyGraphNode->NodeInstance)
                                                    : nullptr;

    if (MyNodeInstance)
    {
        return MyNodeInstance->GetNodeName();
    }

    return SGraphNode::GetNodeComment();
}

FReply SFSGraphSubNode::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
    UFSGraphSubNode* SubNode = Cast<UFSGraphSubNode>(GraphNode);
    if (SubNode != nullptr)
    {
        // OwnerGraphPanel is nullptr
        GetOwnerPanel()->SelectionManager.ClickedOnNode(GraphNode, MouseEvent);
        return FReply::Handled();
    }
    return FReply::Unhandled();
}

void SFSGraphSubNode::UpdateGraphNode()
{
    // SGraphNode::UpdateGraphNode();
    // TODO::自定义子节点样式
    TSharedPtr<SWidget> CenterAreaWidget = CreateNodeContentArea();

    // 获得节点内容槽
    GetOrAddSlot(ENodeZone::Center)
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        [
            SNew(SBorder)
            .BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
            .BorderBackgroundColor(this, &SFSGraphSubNode::GetBorderBackgroundColor)
            .OnMouseButtonDown(this, &SFSGraphSubNode::OnMouseButtonDown)
            .HAlign(HAlign_Fill)
            .Padding(2.f)
            [
                CenterAreaWidget.ToSharedRef()
            ]
        ];
}

TSharedRef<SWidget> SFSGraphSubNode::CreateNodeContentArea()
{
    return SNew(SBorder)
        .BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
        .BorderBackgroundColor(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f))
        .Padding(FMargin(4.0f, 2.0f))
        .HAlign(HAlign_Center)
        [
            SNew(STextBlock)
            .Text(this, &SFSGraphSubNode::GetNodeName)
            .ColorAndOpacity(this, &SFSGraphSubNode::GetNodeTitleColor)
        ];
}

FSlateColor SFSGraphSubNode::GetBorderBackgroundColor() const
{
    /*UBehaviorTreeGraphNode* BTGraphNode = Cast<UBehaviorTreeGraphNode>(GraphNode);
    UBehaviorTreeGraphNode* BTParentNode = BTGraphNode ? Cast<UBehaviorTreeGraphNode>(BTGraphNode->ParentNode) : nullptr;
    const bool bIsInDebuggerActiveState = BTGraphNode && BTGraphNode->bDebuggerMarkCurrentlyActive;
    const bool bIsInDebuggerPrevState = BTGraphNode && BTGraphNode->bDebuggerMarkPreviouslyActive;
    const bool bSelectedSubNode = BTParentNode && GetOwnerPanel()->SelectionManager.SelectedNodes.Contains(GraphNode);
    
    UBTNode* NodeInstance = BTGraphNode ? Cast<UBTNode>(BTGraphNode->NodeInstance) : NULL;
    const bool bIsConnectedTreeRoot = BTGraphNode && BTGraphNode->IsA<UBehaviorTreeGraphNode_Root>() && BTGraphNode->Pins.IsValidIndex(0) && BTGraphNode->Pins[0]->LinkedTo.Num() > 0;
    const bool bIsDisconnected = NodeInstance && NodeInstance->GetExecutionIndex() == MAX_uint16;
    const bool bIsService = BTGraphNode && BTGraphNode->IsA(UBehaviorTreeGraphNode_Service::StaticClass());
    const bool bIsRootDecorator = BTGraphNode && BTGraphNode->bRootLevel;
    const bool bIsInjected = BTGraphNode && BTGraphNode->bInjectedNode;
    const bool bIsBrokenWithParent = bIsService ? 
        BTParentNode && BTParentNode->Services.Find(BTGraphNode) == INDEX_NONE ? true : false :
        BTParentNode && BTParentNode->Decorators.Find(BTGraphNode) == INDEX_NONE ? true :
        (BTGraphNode && BTGraphNode->NodeInstance != NULL && (Cast<UBTNode>(BTGraphNode->NodeInstance->GetOuter()) == NULL && Cast<UBehaviorTree>(BTGraphNode->NodeInstance->GetOuter()) == NULL)) ? true : false;

    if (FBehaviorTreeDebugger::IsPIENotSimulating() && BTGraphNode)
    {
        if (BTGraphNode->bHighlightInAbortRange0)
        {
            return BehaviorTreeColors::NodeBorder::HighlightAbortRange0;
        }
        else if (BTGraphNode->bHighlightInAbortRange1)
        {
            return BehaviorTreeColors::NodeBorder::HighlightAbortRange1;
        }
        else if (BTGraphNode->bHighlightInSearchTree)
        {
            return BehaviorTreeColors::NodeBorder::QuickFind;
        }
    }

    return bSelectedSubNode ? BehaviorTreeColors::NodeBorder::Selected : 
        !bIsRootDecorator && !bIsInjected && bIsBrokenWithParent ? BehaviorTreeColors::NodeBorder::BrokenWithParent :
        !bIsRootDecorator && !bIsInjected && bIsDisconnected ? BehaviorTreeColors::NodeBorder::Disconnected :
        bIsInDebuggerActiveState ? BehaviorTreeColors::NodeBorder::ActiveDebugging :
        bIsInDebuggerPrevState ? BehaviorTreeColors::NodeBorder::InactiveDebugging :
        bIsConnectedTreeRoot ? BehaviorTreeColors::NodeBorder::Root :
        BehaviorTreeColors::NodeBorder::Inactive;*/

    const bool bSelectedSubNode = GetOwnerPanel()->SelectionManager.SelectedNodes.Contains(GraphNode);

    return bSelectedSubNode ? FLinearColor::Red : FLinearColor::Transparent;
}

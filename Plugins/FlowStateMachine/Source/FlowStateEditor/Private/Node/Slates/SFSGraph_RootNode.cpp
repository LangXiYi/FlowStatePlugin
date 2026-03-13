#include "Node/Slates/SFSGraph_RootNode.h"
#include "Node/FSGraphNode.h"

void SFSGraph_RootNode::Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode)
{
    GraphNode = InGraphNode;

    this->SetCursor(EMouseCursor::CardinalCross);

    this->UpdateGraphNode();
}

FString SFSGraph_RootNode::GetNodeComment() const
{
    return TEXT("This is a root node");
}

TSharedRef<SWidget> SFSGraph_RootNode::CreateNodeContentArea()
{
    return SNew(SBorder)
        .BorderImage(FEditorStyle::GetBrush("NoBorder"))
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)
        .Padding(FMargin(0, 3))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
            .HAlign(HAlign_Left)
            .FillWidth(1.0f)
            [
                // LEFT
                SAssignNew(LeftNodeBox, SVerticalBox)
            ]
            + SHorizontalBox::Slot()
            .AutoWidth()
            .VAlign(VAlign_Center)
            .HAlign(HAlign_Center)
            .Padding(10)
            [
                SNew(SImage)
                // TODO::为根节点使用自定义的图标
                .Image(FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode"))
            ]
            + SHorizontalBox::Slot()
            .AutoWidth()
            .HAlign(HAlign_Right)
            .VAlign(VAlign_Center)
            [
                // RIGHT
                SAssignNew(RightNodeBox, SVerticalBox)
            ]
        ];
}

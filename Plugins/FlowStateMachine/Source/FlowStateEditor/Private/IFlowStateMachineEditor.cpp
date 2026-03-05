#include "IFlowStateMachineEditor.h"

#include "EdGraphUtilities.h"
#include "GraphEditAction.h"
#include "GraphEditorActions.h"
#include "Framework/Commands/GenericCommands.h"
#include "Graph/FSMGraph.h"
#include "HAL/PlatformApplicationMisc.h"
#include "Node/FSGraphNode.h"
#include "Node/FSGraphNodeBase.h"
#include "Node/FSGraphSubNode.h"

IFlowStateMachineEditor::IFlowStateMachineEditor()
{
    if (GEditor)
    {
        GEditor->RegisterForUndo(this);
    }
}

IFlowStateMachineEditor::~IFlowStateMachineEditor()
{
    if (GEditor)
    {
        GEditor->UnregisterForUndo(this);
    }
}

void IFlowStateMachineEditor::CreateCommandList()
{
    if (GraphEditorCommands.IsValid())
    {
        return;
    }

    GraphEditorCommands = MakeShareable(new FUICommandList);

    // Can't use CreateSP here because derived editor are already implementing TSharedFromThis<FAssetEditorToolkit>
    // however it should be safe, since commands are being used only within this editor
    // if it ever crashes, this function will have to go away and be reimplemented in each derived class

    GraphEditorCommands->MapAction(FGenericCommands::Get().SelectAll,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::SelectAllNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanSelectAllNodes));

    GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::DeleteSelectedNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanDeleteNodes));

    GraphEditorCommands->MapAction(FGenericCommands::Get().Copy,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CopySelectedNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanCopyNodes));

    GraphEditorCommands->MapAction(FGenericCommands::Get().Cut,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CutSelectedNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanCutNodes));

    GraphEditorCommands->MapAction(FGenericCommands::Get().Paste,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::PasteNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanPasteNodes));

    GraphEditorCommands->MapAction(FGenericCommands::Get().Duplicate,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::DuplicateNodes),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanDuplicateNodes));

    GraphEditorCommands->MapAction(
        FGraphEditorCommands::Get().CreateComment,
        FExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::OnCreateComment),
        FCanExecuteAction::CreateRaw(this, &IFlowStateMachineEditor::CanCreateComment));
}

void IFlowStateMachineEditor::PostUndo(bool bSuccess)
{
    if (bSuccess)
    {
        // Clear selection, to avoid holding refs to nodes that go away
        if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
        {
            CurrentGraphEditor->ClearSelectionSet();
            CurrentGraphEditor->NotifyGraphChanged();
        }
        FSlateApplication::Get().DismissAllMenus();
    }
}

void IFlowStateMachineEditor::PostRedo(bool bSuccess)
{
    if (bSuccess)
    {
        // Clear selection, to avoid holding refs to nodes that go away
        if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
        {
            CurrentGraphEditor->ClearSelectionSet();
            CurrentGraphEditor->NotifyGraphChanged();
        }
        FSlateApplication::Get().DismissAllMenus();
    }
}

void IFlowStateMachineEditor::SelectAllNodes()
{
    if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
    {
        CurrentGraphEditor->SelectAllNodes();
    }
}

bool IFlowStateMachineEditor::CanSelectAllNodes() const
{
    return true;
}

void IFlowStateMachineEditor::DeleteSelectedNodes()
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    if (!CurrentGraphEditor.IsValid())
    {
        return;
    }

    const FScopedTransaction Transaction(FGenericCommands::Get().Delete->GetDescription());
    CurrentGraphEditor->GetCurrentGraph()->Modify();

    const FGraphPanelSelectionSet SelectedNodes = CurrentGraphEditor->GetSelectedNodes();
    CurrentGraphEditor->ClearSelectionSet();

    for (FGraphPanelSelectionSet::TConstIterator NodeIt(SelectedNodes); NodeIt; ++NodeIt)
    {
        if (UEdGraphNode* Node = Cast<UEdGraphNode>(*NodeIt))
        {
            if (Node->CanUserDeleteNode())
            {
                Node->Modify();
                Node->DestroyNode();
            }
        }
    }
}

bool IFlowStateMachineEditor::CanDeleteNodes() const
{
    // If any of the nodes can be deleted then we should allow deleting
    const FGraphPanelSelectionSet SelectedNodes = UpdateGraphEdPtr.Pin()->GetSelectedNodes();
    for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
    {
        UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
        if (Node && Node->CanUserDeleteNode())
        {
            return true;
        }
    }

    return false;
}

void IFlowStateMachineEditor::DeleteSelectedDuplicatableNodes()
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    if (!CurrentGraphEditor.IsValid())
    {
        return;
    }

    const FGraphPanelSelectionSet OldSelectedNodes = CurrentGraphEditor->GetSelectedNodes();
    CurrentGraphEditor->ClearSelectionSet();

    for (FGraphPanelSelectionSet::TConstIterator SelectedIter(OldSelectedNodes); SelectedIter; ++SelectedIter)
    {
        UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
        if (Node && Node->CanDuplicateNode())
        {
            CurrentGraphEditor->SetNodeSelection(Node, true);
        }
    }

    // Delete the duplicatable nodes
    DeleteSelectedNodes();

    CurrentGraphEditor->ClearSelectionSet();

    for (FGraphPanelSelectionSet::TConstIterator SelectedIter(OldSelectedNodes); SelectedIter; ++SelectedIter)
    {
        if (UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter))
        {
            CurrentGraphEditor->SetNodeSelection(Node, true);
        }
    }
}

void IFlowStateMachineEditor::CutSelectedNodes()
{
    CopySelectedNodes();
    DeleteSelectedDuplicatableNodes();
}

bool IFlowStateMachineEditor::CanCutNodes() const
{
    return CanCopyNodes() && CanDeleteNodes();
}

void IFlowStateMachineEditor::CopySelectedNodes()
{
    // Export the selected nodes and place the text on the clipboard
    FGraphPanelSelectionSet   SelectedNodes = UpdateGraphEdPtr.Pin()->GetSelectedNodes();
    TArray<UFSGraphNodeBase*> SubNodes;

    FString ExportedText;

    int32 CopySubNodeIndex = 0;
    for (FGraphPanelSelectionSet::TIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
    {
        UEdGraphNode* Node   = Cast<UEdGraphNode>(*SelectedIter);
        UFSGraphNode* AINode = Cast<UFSGraphNode>(Node);
        if (Node == nullptr)
        {
            SelectedIter.RemoveCurrent();
            continue;
        }

        Node->PrepareForCopying();

        if (AINode)
        {
            AINode->CopySubNodeIndex = CopySubNodeIndex;

            // append all subnodes for selection
            for (int32 Idx = 0; Idx < AINode->SubNodes.Num(); Idx++)
            {
                AINode->SubNodes[Idx]->CopySubNodeIndex = CopySubNodeIndex;
                SubNodes.Add(AINode->SubNodes[Idx]);
            }

            CopySubNodeIndex++;
        }
    }

    for (int32 Idx = 0; Idx < SubNodes.Num(); Idx++)
    {
        SelectedNodes.Add(SubNodes[Idx]);
        SubNodes[Idx]->PrepareForCopying();
    }

    FEdGraphUtilities::ExportNodesToText(SelectedNodes, ExportedText);
    FPlatformApplicationMisc::ClipboardCopy(*ExportedText);

    for (FGraphPanelSelectionSet::TIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
    {
        UFSGraphNodeBase* Node = Cast<UFSGraphNodeBase>(*SelectedIter);
        if (Node)
        {
            Node->PostCopyNode();
        }
    }
}

bool IFlowStateMachineEditor::CanCopyNodes() const
{
    // If any of the nodes can be duplicated then we should allow copying
    const FGraphPanelSelectionSet SelectedNodes = UpdateGraphEdPtr.Pin()->GetSelectedNodes();
    for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
    {
        UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
        if (Node && Node->CanDuplicateNode())
        {
            return true;
        }
    }

    return false;
}

void IFlowStateMachineEditor::PasteNodes()
{
    if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
    {
        PasteNodesHere(CurrentGraphEditor->GetPasteLocation());
    }
}

void IFlowStateMachineEditor::PasteNodesHere(const FVector2D& Location)
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    if (!CurrentGraphEditor.IsValid())
    {
        return;
    }

    // Undo/Redo support
    // BUG::撤销操作会导致程序崩溃
    const FScopedTransaction Transaction(FGenericCommands::Get().Paste->GetDescription());
    UEdGraph*                EdGraph = CurrentGraphEditor->GetCurrentGraph();
    UFSMGraph*               AIGraph = Cast<UFSMGraph>(EdGraph);

    EdGraph->Modify();
    if (AIGraph)
    {
        AIGraph->LockUpdates();
    }

    UFSGraphNode* SelectedParent            = nullptr;
    bool          bHasMultipleNodesSelected = false;

    const FGraphPanelSelectionSet SelectedNodes = CurrentGraphEditor->GetSelectedNodes();
    for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
    {
        UFSGraphNodeBase* Node = Cast<UFSGraphNode>(*SelectedIter);
        if (Node == nullptr)
        {
            UFSGraphSubNode* SubNode = Cast<UFSGraphSubNode>(*SelectedIter);
            if (SubNode)
            {
                Node = SubNode->ParentNode;
            }
        }

        if (Node)
        {
            if (SelectedParent == nullptr)
            {
                SelectedParent = static_cast<UFSGraphNode*>(Node);
            }
            else
            {
                bHasMultipleNodesSelected = true;
                break;
            }
        }
    }

    // Clear the selection set (newly pasted stuff will be selected)
    CurrentGraphEditor->ClearSelectionSet();

    // Grab the text to paste from the clipboard.
    FString TextToImport;
    FPlatformApplicationMisc::ClipboardPaste(TextToImport);

    // Import the nodes
    TSet<UEdGraphNode*> PastedNodes;
    FEdGraphUtilities::ImportNodesFromText(EdGraph, TextToImport, /*out*/ PastedNodes);

    // Average position of nodes so we can move them while still maintaining relative distances to each other
    FVector2D AvgNodePosition(0.0f, 0.0f);

    // Number of nodes used to calculate AvgNodePosition
    int32 AvgCount = 0;

    for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
    {
        UEdGraphNode* EdNode = *It;
        UFSGraphNode* AINode = Cast<UFSGraphNode>(EdNode);
        if (EdNode && AINode)
        {
            AvgNodePosition.X += EdNode->NodePosX;
            AvgNodePosition.Y += EdNode->NodePosY;
            ++AvgCount;
        }
    }

    if (AvgCount > 0)
    {
        float InvNumNodes  = 1.0f / static_cast<float>(AvgCount);
        AvgNodePosition.X *= InvNumNodes;
        AvgNodePosition.Y *= InvNumNodes;
    }

    bool bPastedParentNode = false;

    TMap<FGuid /*New*/, FGuid /*Old*/> NewToOldNodeMapping;

    TMap<int32, UFSGraphNodeBase*> ParentMap;
    for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
    {
        UEdGraphNode* PasteNode   = *It;
        UFSGraphNode* PasteAINode = Cast<UFSGraphNode>(PasteNode);

        if (PasteNode && PasteAINode)
        {
            bPastedParentNode = true;

            // Select the newly pasted stuff
            CurrentGraphEditor->SetNodeSelection(PasteNode, true);

            PasteNode->NodePosX = (PasteNode->NodePosX - AvgNodePosition.X) + Location.X;
            PasteNode->NodePosY = (PasteNode->NodePosY - AvgNodePosition.Y) + Location.Y;

            PasteNode->SnapToGrid(16);

            const FGuid OldGuid = PasteNode->NodeGuid;

            // Give new node a different Guid from the old one
            PasteNode->CreateNewGuid();

            const FGuid NewGuid = PasteNode->NodeGuid;

            NewToOldNodeMapping.Add(NewGuid, OldGuid);

            if (PasteAINode)
            {
                PasteAINode->RemoveAllSubNode();
                ParentMap.Add(PasteAINode->CopySubNodeIndex, PasteAINode);
            }
        }
    }

    // 添加次要节点到指定位置
    for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
    {
        UFSGraphSubNode* PasteNode = Cast<UFSGraphSubNode>(*It);
        if (PasteNode)
        {
            PasteNode->NodePosX = 0;
            PasteNode->NodePosY = 0;

            // remove subnode from graph, it will be referenced from parent node
            PasteNode->DestroyNode();

            PasteNode->ParentNode = ParentMap.FindRef(PasteNode->CopySubNodeIndex);
            if (UFSGraphNode* FSMParentNode = Cast<UFSGraphNode>(PasteNode->ParentNode))
            {
                FSMParentNode->AddSubNode(PasteNode, EdGraph);
            }
            else if (!bHasMultipleNodesSelected && !bPastedParentNode && SelectedParent)
            {
                PasteNode->ParentNode = SelectedParent;
                SelectedParent->AddSubNode(PasteNode, EdGraph);
            }
        }
    }

    FixupPastedNodes(PastedNodes, NewToOldNodeMapping);

    if (AIGraph)
    {
        AIGraph->UpdateClassData();
        AIGraph->OnNodesPasted(TextToImport);
        AIGraph->UnlockUpdates();
    }

    // Update UI
    CurrentGraphEditor->NotifyGraphChanged();

    UObject* GraphOwner = EdGraph->GetOuter();
    if (GraphOwner)
    {
        GraphOwner->PostEditChange();
        GraphOwner->MarkPackageDirty();
    }
}

bool IFlowStateMachineEditor::CanPasteNodes() const
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    if (!CurrentGraphEditor.IsValid())
    {
        return false;
    }

    FString ClipboardContent;
    FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);

    return FEdGraphUtilities::CanImportNodesFromText(CurrentGraphEditor->GetCurrentGraph(), ClipboardContent);
}

void IFlowStateMachineEditor::DuplicateNodes()
{
    CopySelectedNodes();
    PasteNodes();
}

bool IFlowStateMachineEditor::CanDuplicateNodes() const
{
    return CanCopyNodes();
}

bool IFlowStateMachineEditor::CanCreateComment() const
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    return CurrentGraphEditor.IsValid() ? (CurrentGraphEditor->GetNumberOfSelectedNodes() != 0) : false;
}

void IFlowStateMachineEditor::OnCreateComment()
{
    TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
    if (UEdGraph* EdGraph = CurrentGraphEditor.IsValid() ? CurrentGraphEditor->GetCurrentGraph() : nullptr)
    {
        TSharedPtr<FEdGraphSchemaAction> Action = EdGraph->GetSchema()->GetCreateCommentAction();
        if (Action.IsValid())
        {
            Action->PerformAction(EdGraph, nullptr, FVector2D());
        }
    }
}

void IFlowStateMachineEditor::FixupPastedNodes(const TSet<UEdGraphNode*>& NewPastedGraphNodes,
    const TMap<FGuid, FGuid>&                                             NewToOldNodeMapping)
{
}
#include "FSMGraphEditor.h"

#include "BlueprintEditorModes.h"
#include "EdGraphUtilities.h"
#include "FlowStateMachine_EditorModule.h"
#include "FSMEditorToolbar.h"
#include "GraphEditorActions.h"
#include "Graph/FSMGraph.h"
#include "Data/FSMCommonData.h"
#include "Framework/Commands/GenericCommands.h"
#include "Graph/Schema/EdGraphSchema_FSM.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Mode/CommonDataEditorAppMode.h"
#include "Mode/FSMEditorAppMode.h"
#include "Node/FSMGraphNodeBase.h"
#include "Node/FSMGraphNode_Root.h"
#include "RuntimeNode/FSMRuntimeNodeBase.h"
#include "Slate/SFSMGraphPalette.h"
#include "SM/FlowStateMachine.h"
#include "TabFactories/FSMTabSummoner.h"
#include "HAL/PlatformApplicationMisc.h"
#include "Node/FSMGraphSubNode.h"

FName const FFSMGraphEditor::FlowStateMachineMode = FName("FlowStateMachine");
FName const FFSMGraphEditor::CommonDataMode = FName("CommonData");

#define LOCTEXT_NAMESPACE "FlowStateMachineEditor"

FFSMGraphEditor::FFSMGraphEditor()
{
}

void FFSMGraphEditor::InitFlowStateMachineEditor(EToolkitMode::Type Mode,
                                                         const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject)
{
	UFlowStateMachine* FlowStateMachineInEditor = Cast<UFlowStateMachine>(InObject);
	UFSMCommonData* CommonDataInEditor = Cast<UFSMCommonData>(InObject);

	if (FlowStateMachineInEditor != nullptr)
	{
		FlowStateMachine = FlowStateMachineInEditor;
		if(FlowStateMachine->CommonData != nullptr)
		{
			CommonData = FlowStateMachine->CommonData;
		}
	}
	else if (CommonDataInEditor != nullptr)
	{
		CommonData = CommonDataInEditor;
	}
	
	// 将目标添加到待编辑列表
	TArray<UObject*> ObjectsToEdit;
	if (FlowStateMachine != nullptr)
	{
		ObjectsToEdit.Add(FlowStateMachine);
	}
	if (CommonData != nullptr)
	{
		ObjectsToEdit.Add(CommonData);
	}
	// TODO::Add More Edit Objects..

	// 创建编辑模式切换按钮
	if (!ToolbarBuilder.IsValid())
	{
		ToolbarBuilder = MakeShareable(new FFSMEditorToolbar(SharedThis(this)));
	}

	if(!DocumentManager.IsValid())
	{
		DocumentManager = MakeShareable(new FDocumentTracker);
		DocumentManager->Initialize(SharedThis(this));

		// Register the document factories
		{
			TSharedRef<FDocumentTabFactory> GraphEditorFactory = MakeShareable(new FFSMGraphEditorSummoner(SharedThis(this)));

			// Also store off a reference to the grapheditor factory so we can find all the tabs spawned by it later.
			GraphEditorTabFactoryPtr = GraphEditorFactory;
			DocumentManager->RegisterDocumentFactory(GraphEditorFactory);
		}
	}

	// if we are already editing objects, dont try to recreate the editor from scratch but update the list of objects in edition
	// ex: BehaviorTree may want to reuse an editor already opened for its associated Blackboard asset.
	const TArray<UObject*>* EditedObjects = GetObjectsCurrentlyBeingEdited();
	if (EditedObjects == nullptr || EditedObjects->Num() == 0)
	{
		// Init Asset M
		InitAssetEditor(
			Mode,
			InitToolkitHost,
			FFlowStateMachine_EditorModule::FlowStateMachineAppIdentifier,
			FTabManager::FLayout::NullLayout,
			true,
			true,
			ObjectsToEdit
			);
		// Add Application Mode
		AddApplicationMode(FlowStateMachineMode, MakeShareable(new FFSMEditorAppMode(SharedThis(this))));
		AddApplicationMode(CommonDataMode, MakeShareable(new FCommonDataEditorAppMode(SharedThis(this))));
	}
	else
	{
		for (UObject* ObjectToEdit : ObjectsToEdit)
		{
			if (!EditedObjects->Contains(ObjectToEdit))
			{
				AddEditingObject(ObjectToEdit);
			}
		}
	}
	// Set Editor mode to FSMEditorApplicationMode
	if(FlowStateMachine != nullptr)
	{
		SetCurrentMode(FlowStateMachineMode);
	}
	else if (CommonData != nullptr)
	{
		SetCurrentMode(CommonDataMode);
	}

	// OnClassListUpdated();
	RegenerateMenusAndToolbars();
}

void FFSMGraphEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	DocumentManager->SetTabManager(InTabManager);
	IFlowStateMachineEditor::RegisterTabSpawners(InTabManager);
}

void FFSMGraphEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	IFlowStateMachineEditor::UnregisterTabSpawners(InTabManager);
}

void FFSMGraphEditor::OnGraphEditorFocused(TSharedRef<SGraphEditor> InGraphEditor)
{
	UpdateGraphEdPtr = InGraphEditor;

	FGraphPanelSelectionSet CurrentSelection = InGraphEditor->GetSelectedNodes();
	OnSelectedNodesChanged(CurrentSelection);
}

void FFSMGraphEditor::CreateCommandList()
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
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::SelectAllNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanSelectAllNodes)
		);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::DeleteSelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanDeleteNodes)
		);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Copy,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::CopySelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanCopyNodes)
	);
	
	GraphEditorCommands->MapAction(FGenericCommands::Get().Cut,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::CutSelectedNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanCutNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Paste,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::PasteNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanPasteNodes)
	);

	GraphEditorCommands->MapAction(FGenericCommands::Get().Duplicate,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::DuplicateNodes),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanDuplicateNodes)
		);

	GraphEditorCommands->MapAction(
		FGraphEditorCommands::Get().CreateComment,
		FExecuteAction::CreateRaw(this, &FFSMGraphEditor::OnCreateComment),
		FCanExecuteAction::CreateRaw(this, &FFSMGraphEditor::CanCreateComment)
	);
}

void FFSMGraphEditor::SelectAllNodes()
{
	if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
	{
		CurrentGraphEditor->SelectAllNodes();
	}
}

bool FFSMGraphEditor::CanSelectAllNodes() const
{
	return true;
}

void FFSMGraphEditor::DeleteSelectedNodes()
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

bool FFSMGraphEditor::CanDeleteNodes() const
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

void FFSMGraphEditor::DeleteSelectedDuplicatableNodes()
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

void FFSMGraphEditor::CutSelectedNodes()
{
	CopySelectedNodes();
	DeleteSelectedDuplicatableNodes();
}

bool FFSMGraphEditor::CanCutNodes() const
{
	return CanCopyNodes() && CanDeleteNodes();
}

void FFSMGraphEditor::CopySelectedNodes()
{
	// Export the selected nodes and place the text on the clipboard
	FGraphPanelSelectionSet SelectedNodes = UpdateGraphEdPtr.Pin()->GetSelectedNodes();
	TArray<UFSMGraphNodeBase*> SubNodes;

	FString ExportedText;

	int32 CopySubNodeIndex = 0;
	for (FGraphPanelSelectionSet::TIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UEdGraphNode* Node = Cast<UEdGraphNode>(*SelectedIter);
		UFSMGraphNodeBase* AINode = Cast<UFSMGraphNodeBase>(Node);
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
		UFSMGraphNodeBase* Node = Cast<UFSMGraphNodeBase>(*SelectedIter);
		if (Node)
		{
			Node->PostCopyNode();
		}
	}
}

bool FFSMGraphEditor::CanCopyNodes() const
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

void FFSMGraphEditor::PasteNodes()
{
	if (TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin())
	{
		PasteNodesHere(CurrentGraphEditor->GetPasteLocation());
	}
}

void FFSMGraphEditor::PasteNodesHere(const FVector2D& Location)
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
	if (!CurrentGraphEditor.IsValid())
	{
		return;
	}

	// Undo/Redo support
	const FScopedTransaction Transaction(FGenericCommands::Get().Paste->GetDescription());
	UEdGraph* EdGraph = CurrentGraphEditor->GetCurrentGraph();
	UFSMGraph* AIGraph = Cast<UFSMGraph>(EdGraph);

	EdGraph->Modify();
	if (AIGraph)
	{
		AIGraph->LockUpdates();
	}

	UFSMGraphNodeBase* SelectedParent = NULL;
	bool bHasMultipleNodesSelected = false;

	const FGraphPanelSelectionSet SelectedNodes = CurrentGraphEditor->GetSelectedNodes();
	for (FGraphPanelSelectionSet::TConstIterator SelectedIter(SelectedNodes); SelectedIter; ++SelectedIter)
	{
		UFSMGraphNodeBase* Node = Cast<UFSMGraphNode>(*SelectedIter);
		if (Node == nullptr)
		{
			UFSMGraphSubNode* SubNode = Cast<UFSMGraphSubNode>(*SelectedIter);
			if (SubNode)
			{
				Node = SubNode->ParentNode;
			}
		}

		if (Node)
		{
			if (SelectedParent == nullptr)
			{
				SelectedParent = Node;
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

	//Average position of nodes so we can move them while still maintaining relative distances to each other
	FVector2D AvgNodePosition(0.0f, 0.0f);
	
	// Number of nodes used to calculate AvgNodePosition
	int32 AvgCount = 0;

	for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
	{
		UEdGraphNode* EdNode = *It;
		UFSMGraphNode* AINode = Cast<UFSMGraphNode>(EdNode);
		if (EdNode && AINode)
		{
			AvgNodePosition.X += EdNode->NodePosX;
			AvgNodePosition.Y += EdNode->NodePosY;
			++AvgCount;
		}
	}

	if (AvgCount > 0)
	{
		float InvNumNodes = 1.0f / float(AvgCount);
		AvgNodePosition.X *= InvNumNodes;
		AvgNodePosition.Y *= InvNumNodes;
	}

	bool bPastedParentNode = false;

	TMap<FGuid/*New*/, FGuid/*Old*/> NewToOldNodeMapping;

	TMap<int32, UFSMGraphNodeBase*> ParentMap;
	for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
	{
		UEdGraphNode* PasteNode = *It;
		UFSMGraphNode* PasteAINode = Cast<UFSMGraphNode>(PasteNode);

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

	for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
	{
		UFSMGraphSubNode* PasteNode = Cast<UFSMGraphSubNode>(*It);
		if (PasteNode)
		{
			PasteNode->NodePosX = 0;
			PasteNode->NodePosY = 0;

			// remove subnode from graph, it will be referenced from parent node
			PasteNode->DestroyNode();

			PasteNode->ParentNode = ParentMap.FindRef(PasteNode->CopySubNodeIndex);
			if (PasteNode->ParentNode)
			{
				PasteNode->ParentNode->AddSubNode(PasteNode, EdGraph);
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

bool FFSMGraphEditor::CanPasteNodes() const
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

void FFSMGraphEditor::DuplicateNodes()
{
	CopySelectedNodes();
	PasteNodes();
}

bool FFSMGraphEditor::CanDuplicateNodes() const
{
	return CanCopyNodes();
}

bool FFSMGraphEditor::CanCreateComment() const
{
	TSharedPtr<SGraphEditor> CurrentGraphEditor = UpdateGraphEdPtr.Pin();
	return CurrentGraphEditor.IsValid() ? (CurrentGraphEditor->GetNumberOfSelectedNodes() != 0) : false;
}

void FFSMGraphEditor::OnCreateComment()
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

void FFSMGraphEditor::FixupPastedNodes(const TSet<UEdGraphNode*>& NewPastedGraphNodes,
	const TMap<FGuid, FGuid>& NewToOldNodeMapping)
{
}

void FFSMGraphEditor::RegisterToolbarTab(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
}

void FFSMGraphEditor::SaveEditedObjectState()
{
	// todo::Save Object State
}

void FFSMGraphEditor::RestoreFlowStateMachine()
{
	// 根据保存的图形更新 FSM 资产数据，使编辑器中有正确的数据
	UFSMGraph* MyGraph = Cast<UFSMGraph>(FlowStateMachine->FSMGraph);
	const bool bNewGraph = (MyGraph == nullptr);
	if (bNewGraph)
	{
		FlowStateMachine->FSMGraph = FBlueprintEditorUtils::CreateNewGraph(
			FlowStateMachine,
			TEXT("FlowStateMachine"),
			UFSMGraph::StaticClass(),
			UEdGraphSchema_FSM::StaticClass());
		MyGraph = Cast<UFSMGraph>(FlowStateMachine->FSMGraph);

		// Initialize the behavior tree graph
		const UEdGraphSchema* Schema = MyGraph->GetSchema();
		Schema->CreateDefaultNodesForGraph(*MyGraph);

		MyGraph->OnCreateGraph();
	}
	else
	{
		MyGraph->OnLoadedGraph();
	}
	MyGraph->Initialize();
	TSharedPtr<FTabPayload_UObject> Payload = FTabPayload_UObject::Make(MyGraph);
	TSharedPtr<SDockTab> DocumentTab = DocumentManager->OpenDocument(
		Payload,
		bNewGraph ? FDocumentTracker::OpenNewDocument : FDocumentTracker::RestorePreviousDocument);

	/*if(BehaviorTree->LastEditedDocuments.Num() > 0)
	{
		TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(DocumentTab->GetContent());
		GraphEditor->SetViewLocation(BehaviorTree->LastEditedDocuments[0].SavedViewOffset, BehaviorTree->LastEditedDocuments[0].SavedZoomAmount);
	}

	const bool bIncreaseVersionNum = false;
	if(bNewGraph)
	{
		MyGraph->UpdateAsset(UBehaviorTreeGraph::ClearDebuggerFlags | UBehaviorTreeGraph::KeepRebuildCounter);
		RefreshBlackboardViewsAssociatedObject();
	}
	else
	{
		MyGraph->UpdateAsset(UBehaviorTreeGraph::KeepRebuildCounter);
		RefreshDebugger();
	}

	FAbortDrawHelper EmptyMode;
	bShowDecoratorRangeLower = false;
	bShowDecoratorRangeSelf = false;
	bSelectedNodeIsInjected = false;
	bSelectedNodeIsRootLevel = false;
	MyGraph->UpdateAbortHighlight(EmptyMode, EmptyMode);*/
}

bool FFSMGraphEditor::CanAccessFlowStateMachineMode() const
{
	return FlowStateMachine != nullptr;
}

bool FFSMGraphEditor::CanAccessCommonDataMode() const
{
	return CommonData != nullptr;
}

TSharedRef<SWidget> FFSMGraphEditor::CreateFlowStateMachineGraphEditor(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph)
{
	if (!GraphEditorCommands.IsValid())
	{
		CreateCommandList();
	}
/*
		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().RemoveExecutionPin,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnRemoveInputPin ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanRemoveInputPin )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().AddExecutionPin,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnAddInputPin ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanAddInputPin )
			);

		// Debug actions
		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().AddBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnAddBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanAddBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanAddBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().RemoveBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnRemoveBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanRemoveBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanRemoveBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().EnableBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnEnableBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanEnableBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanEnableBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().DisableBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnDisableBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanDisableBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanDisableBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().ToggleBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnToggleBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanToggleBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanToggleBreakpoint )
			);
	}*/

	
	SGraphEditor::FGraphEditorEvents InEvents;
	// TODO::绑定Graph图表的事件
	InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FFSMGraphEditor::OnSelectedNodesChanged);
	InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FFSMGraphEditor::OnNodeDoubleClicked);
	// InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FBehaviorTreeEditor::OnNodeTitleCommitted);
	
	// Make full graph editor
	const bool bGraphIsEditable = InGraph->bEditable;
	return SNew(SGraphEditor)
		// .AdditionalCommands(GraphEditorCommands)
		.IsEditable(this, &FFSMGraphEditor::InEditingMode, bGraphIsEditable)
		.Appearance(this, &FFSMGraphEditor::GetGraphAppearance)
		.GraphToEdit(InGraph)
		.GraphEvents(InEvents);
}

TSharedRef<SWidget> FFSMGraphEditor::CreateFlowStateMachineDetailView(const FWorkflowTabSpawnInfo& Info)
{
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);
	
	DetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);
	AssetDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);

	AssetDetailsView->SetObject(nullptr);
	DetailsView->SetObject(nullptr);

	// TODO::绑定属性改变事件，监听RootNode是否创建成功，并更新显示内容

	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			AssetDetailsView.ToSharedRef()
		]
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			DetailsView.ToSharedRef()
		];
}

TSharedRef<SWidget> FFSMGraphEditor::CreateFlowStateMachineListView(const FWorkflowTabSpawnInfo& Info)
{
	return SNew(SFSMGraphPalette, GetFlowStateMachine()->FSMGraph);
}

FText FFSMGraphEditor::GetLocalizedMode(FName InMode)
{
	static TMap< FName, FText > LocModes;

	if (LocModes.Num() == 0)
	{
		LocModes.Add( FlowStateMachineMode, LOCTEXT("FlowStateMachineMode", "FlowStateMachineMode") );
		LocModes.Add( CommonDataMode, LOCTEXT("CommonDataMode", "CommonDataMode") );
	}

	check( InMode != NAME_None );
	const FText* OutDesc = LocModes.Find( InMode );
	check( OutDesc );
	return *OutDesc;
}

FGraphAppearanceInfo FFSMGraphEditor::GetGraphAppearance() const
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText", "FLOW STATE MACHINE");

	return AppearanceInfo;
}

void FFSMGraphEditor::OnSelectedNodesChanged(const TSet<UObject*>& NewSelection)
{
	UFSMGraph* MyGraph = Cast<UFSMGraph>(FlowStateMachine->FSMGraph);

	TArray<UObject*> SelectionNodes;
	SelectionNodes.Reserve(NewSelection.Num());
	for (UObject* Selection : NewSelection)
	{
		// 对选中的节点进行筛选，确保类型正确
		if (Selection->IsA<UFSMGraphNodeBase>())
		{
			SelectionNodes.Add(Selection);
		}
	}
	// 若选中数量为 1 则改变 DetailView 的显示对象
	if (SelectionNodes.Num() == 1)
	{
		AssetDetailsView->SetObject(SelectionNodes[0]);
		// 设置细节面板显示的对象为运行时节点
		DetailsView->SetObject(static_cast<UFSMGraphNodeBase*>(SelectionNodes[0])->RuntimeNode);
	}
	else
	{
		UFSMGraphNode_Root* RootNode = nullptr;
		for (UEdGraphNode* Node : MyGraph->Nodes)
		{
			RootNode = Cast<UFSMGraphNode_Root>(Node);
			if (RootNode != nullptr)
			{
				break;
			}
		}
		AssetDetailsView->SetObject(FlowStateMachine);
		DetailsView->SetObject(RootNode);
	}
}

void FFSMGraphEditor::OnNodeDoubleClicked(UEdGraphNode* EdGraphNode)
{
	UFSMGraphNodeBase* MyGraphNode = Cast<UFSMGraphNodeBase>(EdGraphNode);
	if (MyGraphNode && MyGraphNode->RuntimeNode &&
			MyGraphNode->RuntimeNode->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		UClass* NodeClass = MyGraphNode->RuntimeNode->GetClass();
		UPackage* Pkg = NodeClass->GetOuterUPackage();
		FString ClassName = NodeClass->GetName().LeftChop(2);
		UBlueprint* BlueprintOb = FindObject<UBlueprint>(Pkg, *ClassName);
		if(BlueprintOb)
		{
			GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(BlueprintOb);
		}
	}
}

void FFSMGraphEditor::SaveAsset_Execute()
{
	if (FlowStateMachine)
	{
		UFSMGraph* Graph = Cast<UFSMGraph>(FlowStateMachine->FSMGraph);
		if (Graph)
		{
			Graph->OnSave();
		}
	}
	IFlowStateMachineEditor::SaveAsset_Execute();
}

#undef LOCTEXT_NAMESPACE

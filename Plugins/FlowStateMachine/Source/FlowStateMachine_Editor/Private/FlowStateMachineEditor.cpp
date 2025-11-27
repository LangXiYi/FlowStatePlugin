#include "FlowStateMachineEditor.h"

#include "BlueprintEditorModes.h"
#include "FlowStateMachine_Editor.h"
#include "FSMEditorToolbar.h"
#include "Graph/FSMGraph.h"
#include "Graph/Schema/EdGraphSchema_FlowStateMachine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Mode/FSMCommonDataEditorApplicationMode.h"
#include "Mode/FSMEditorApplicationMode.h"
#include "SM/FlowStateMachine.h"
#include "TabFactories/FSMGraphEditorSummoner.h"

FName const FFlowStateMachineEditor::FlowStateMachineMode = FName("FlowStateMachine");
FName const FFlowStateMachineEditor::CommonDataMode = FName("CommonData");

#define LOCTEXT_NAMESPACE "FlowStateMachineEditor"

FFlowStateMachineEditor::FFlowStateMachineEditor()
{
}

void FFlowStateMachineEditor::InitFlowStateMachineEditor(EToolkitMode::Type Mode,
                                                         const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject)
{
	UFlowStateMachine* FlowStateMachineInEditor = Cast<UFlowStateMachine>(InObject);

	if (FlowStateMachineInEditor != nullptr)
	{
		FlowStateMachine = FlowStateMachineInEditor;
	}
	// 将目标添加到待编辑列表
	TArray<UObject*> ObjectsToEdit;
	if (FlowStateMachine != nullptr)
	{
		ObjectsToEdit.Add(FlowStateMachine);
	}
	// TODO::Add More Edit Objects..

	if (!ToolbarBuilder.IsValid())
	{
		ToolbarBuilder = MakeShareable(new FFSMEditorToolbar(SharedThis(this)));
	}

	// 创建模式切换按钮
	// void FBehaviorTreeEditorToolbar::FillModesToolbar(FToolBarBuilder& ToolbarBuilder)

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
		AddApplicationMode(FlowStateMachineMode, MakeShareable(new FFSMEditorApplicationMode(SharedThis(this))));
		AddApplicationMode(CommonDataMode, MakeShareable(new FFSMCommonDataEditorApplicationMode(SharedThis(this))));
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

	// OnClassListUpdated();
	RegenerateMenusAndToolbars();
}

void FFlowStateMachineEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	DocumentManager->SetTabManager(InTabManager);
	IFlowStateMachineEditor::RegisterTabSpawners(InTabManager);
}

void FFlowStateMachineEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	IFlowStateMachineEditor::UnregisterTabSpawners(InTabManager);
}

void FFlowStateMachineEditor::RegisterToolbarTab(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
}

void FFlowStateMachineEditor::SaveEditedObjectState()
{
	// todo::Save Object State
}

void FFlowStateMachineEditor::RestoreFlowStateMachine()
{
	// Update BT asset data based on saved graph to have correct data in editor
	UFSMGraph* MyGraph = Cast<UFSMGraph>(FlowStateMachine->FSMGraph);
	const bool bNewGraph = (MyGraph == nullptr);
	if (bNewGraph)
	{
		FlowStateMachine->FSMGraph = FBlueprintEditorUtils::CreateNewGraph(
			FlowStateMachine,
			TEXT("FlowStateMachine"),
			UFSMGraph::StaticClass(),
			UEdGraphSchema_FlowStateMachine::StaticClass());
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

bool FFlowStateMachineEditor::CanAccessFlowStateMachineMode() const
{
	return FlowStateMachine != nullptr;
}

bool FFlowStateMachineEditor::CanAccessCommonDataMode() const
{
	return CommonData != nullptr;
}

FText FFlowStateMachineEditor::GetLocalizedMode(FName InMode)
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

#undef LOCTEXT_NAMESPACE
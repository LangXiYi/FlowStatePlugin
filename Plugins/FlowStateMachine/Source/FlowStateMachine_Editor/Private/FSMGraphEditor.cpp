#include "FSMGraphEditor.h"

#include "BlueprintEditorModes.h"
#include "FlowStateMachine_Editor.h"
#include "FSMEditorToolbar.h"
#include "Graph/FSMGraph.h"
#include "Data/FSMCommonData.h"
#include "Graph/Schema/EdGraphSchema_FSM.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Mode/CommonDataEditorAppMode.h"
#include "Mode/FSMEditorAppMode.h"
#include "SM/FlowStateMachine.h"
#include "TabFactories/FSMTabSummoner.h"

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

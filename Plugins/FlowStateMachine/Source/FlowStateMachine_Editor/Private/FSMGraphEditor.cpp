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

TSharedRef<SWidget> FFSMGraphEditor::CreateFlowStateMachineGraphEditor(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph)
{
	/*if (!GraphEditorCommands.IsValid())
	{
		CreateCommandList();

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
	// InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FBehaviorTreeEditor::OnNodeDoubleClicked);
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

	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(NewSelection.Num()));
	}
	// TODO::需要对选中的目标进行筛选，确认其类型是 FSMGraphNode
	TArray<UObject*> SelectionNodes;
	SelectionNodes.Reserve(NewSelection.Num());
	for (UObject* Selection : NewSelection)
	{
		if (Selection->IsA<UFSMGraphNode>())
		{
			SelectionNodes.Add(Selection);
		}
	}
	// 若选中数量为 1 则改变 DetailView 的显示对象
	if (SelectionNodes.Num() == 1)
	{
		AssetDetailsView->SetObject(SelectionNodes[0]);
		// 设置细节面板显示的对象为运行时节点
		DetailsView->SetObject(static_cast<UFSMGraphNode*>(SelectionNodes[0])->RuntimeNode);
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

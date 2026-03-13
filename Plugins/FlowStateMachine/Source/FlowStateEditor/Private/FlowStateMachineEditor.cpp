#include "FlowStateMachineEditor.h"

#include "BlueprintEditorModes.h"
#include "EdGraphUtilities.h"
#include "FlowStateEditorModule.h"
#include "FlowStateEditorToolbar.h"
#include "GraphEditAction.h"
#include "GraphEditorActions.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/SlateWrapperTypes.h"
#include "Graph/FlowStateGraph.h"
#include "Data/FSMCommonData.h"
#include "Framework/Commands/GenericCommands.h"
#include "Graph/FlowStateGraphSchema.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Mode/AppMode_CommonData.h"
#include "Mode/AppMode_StateGraph.h"
#include "Node/FSGraphNodeBase.h"
#include "Node/FSGraph_RootNode.h"
#include "NodeInstance/FSMNodeInstanceBase.h"
#include "Slate/SFSGraphPalette.h"
#include "SM/FlowStateMachine.h"
#include "TabSummoner/FlowStateTabSummoner.h"
#include "Node/FSGraphSubNode.h"
#include "Node/Slates/SFSGraphNodeBase.h"
#include "Utility/FlowStateEditorHelper.h"

USING_FLOWSTATE_EDITORHELPER

#define LOCTEXT_NAMESPACE "FlowStateMachineEditor"

FFlowStateMachineEditor::FFlowStateMachineEditor()
{
}

void FFlowStateMachineEditor::InitFlowStateMachineEditor(EToolkitMode::Type Mode,
                                                         const TSharedPtr<class IToolkitHost>& InitToolkitHost,
                                                         UObject* InObject)
{
    UFlowStateMachine* FlowStateMachineInEditor = Cast<UFlowStateMachine>(InObject);
    UFSMCommonData* CommonDataInEditor = Cast<UFSMCommonData>(InObject);

    if (FlowStateMachineInEditor != nullptr)
    {
        FlowStateMachine = FlowStateMachineInEditor;
        if (FlowStateMachine->CommonData != nullptr)
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
        ToolbarBuilder = MakeShareable(new FFlowStateEditorToolbar(SharedThis(this)));
    }

    if (!DocumentManager.IsValid())
    {
        DocumentManager = MakeShareable(new FDocumentTracker);
        DocumentManager->Initialize(SharedThis(this));

        // Register the document factories
        {
            TSharedRef<FDocumentTabFactory> GraphEditorFactory = MakeShareable(
                new FFSMGraphEditorSummoner(SharedThis(this)));

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
            FEditorHelper::FlowStateMachineAppIdentifier,
            FTabManager::FLayout::NullLayout,
            true,
            true,
            ObjectsToEdit);
        // Add Application Mode
        AddApplicationMode(FEditorHelper::FlowStateMachineMode,
                           MakeShareable(new FAppMode_StateGraph(SharedThis(this))));
        AddApplicationMode(FEditorHelper::CommonDataMode, MakeShareable(new FAppMode_CommonData(SharedThis(this))));
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
    if (FlowStateMachine != nullptr)
    {
        SetCurrentMode(FEditorHelper::FlowStateMachineMode);
    }
    else if (CommonData != nullptr)
    {
        SetCurrentMode(FEditorHelper::CommonDataMode);
    }

    // OnClassListUpdated();
    RegenerateMenusAndToolbars();

    // 在打开编辑器后监听资产改变事件
    FFlowStateEditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        TEXT("FlowStateEditor"));
    StateCollectHandle = FSMEditorModule.OnUpdateStateCollect.AddSP(this, &FFlowStateMachineEditor::OnCollectState);
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

FText FFlowStateMachineEditor::GetToolkitName() const
{
    const UObject* EditingObject = GetCurrentMode() == FEditorHelper::FlowStateMachineMode
                                       ? static_cast<UObject*>(FlowStateMachine)
                                       : static_cast<UObject*>(CommonData);
    if (EditingObject != nullptr)
    {
        return GetLabelForObject(EditingObject);
    }

    return FText();
}

FText FFlowStateMachineEditor::GetToolkitToolTipText() const
{
    const UObject* EditingObject = GetCurrentMode() == FEditorHelper::FlowStateMachineMode
                                       ? static_cast<UObject*>(FlowStateMachine)
                                       : static_cast<UObject*>(CommonData);

    check(EditingObject != NULL);

    return GetToolTipTextForObject(EditingObject);
}

void FFlowStateMachineEditor::OnGraphEditorFocused(TSharedRef<SGraphEditor> InGraphEditor)
{
    UpdateGraphEdPtr = InGraphEditor;

    FGraphPanelSelectionSet CurrentSelection = InGraphEditor->GetSelectedNodes();
    OnSelectedNodesChanged(CurrentSelection);
}

bool FFlowStateMachineEditor::IsPropertyEditable() const
{
    // Debug mode 下不能编辑
    /*if (FBehaviorTreeDebugger::IsPIESimulating() || bForceDisablePropertyEdit)
    {
        return false;
    }*/

    TSharedPtr<SGraphEditor> FocusedGraphEd = UpdateGraphEdPtr.Pin();
    return FocusedGraphEd.IsValid() && FocusedGraphEd->GetCurrentGraph() && FocusedGraphEd->GetCurrentGraph()->
        bEditable;
}

void FFlowStateMachineEditor::RefreshClassPalette()
{
    ClassPalette->RefreshActionsList(true);
}

void FFlowStateMachineEditor::OnCollectState(UBlueprint* Blueprint)
{
    if (Blueprint)
    {
        if (UFlowStateGraph* MyGraph = GetFlowStateGraph())
        {
            // 对图表中的所有节点进行整体刷新
            // TODO::后续可以考虑仅刷新指定类型的节点
            MyGraph->RefreshAllNodes();
        }
    }
}

void FFlowStateMachineEditor::PostUndo(bool bSuccess)
{
    IFlowStateMachineEditor::PostUndo(bSuccess);
}

void FFlowStateMachineEditor::PostRedo(bool bSuccess)
{
    IFlowStateMachineEditor::PostRedo(bSuccess);
}

void FFlowStateMachineEditor::NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
                                               FProperty* PropertyThatChanged)
{
    if (PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
    {
        if (PropertyChangedEvent.Property != nullptr && PropertyChangedEvent.Property->GetFName() == TEXT("CommonData"))
        {
            CommonData = FlowStateMachine->CommonData;
        }

        // RefreshBlackboardViewsAssociatedObject();
    }
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
    // 根据保存的图形更新 FSM 资产数据，使编辑器中有正确的数据
    UFlowStateGraph* MyGraph = Cast<UFlowStateGraph>(FlowStateMachine->FSMGraph);
    const bool bNewGraph = (MyGraph == nullptr);
    if (bNewGraph)
    {
        FlowStateMachine->FSMGraph = FBlueprintEditorUtils::CreateNewGraph(
            FlowStateMachine,
            TEXT("FlowStateMachine"),
            UFlowStateGraph::StaticClass(),
            UFlowStateGraphSchema::StaticClass());
        MyGraph = Cast<UFlowStateGraph>(FlowStateMachine->FSMGraph);

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
    // TODO::在更新资产的数据后，同步更新该编辑器的资产
    return CommonData != nullptr;
}

void FFlowStateMachineEditor::OnClose()
{
    FFlowStateEditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        TEXT("FlowStateEditor"));
    FSMEditorModule.OnUpdateStateCollect.Remove(StateCollectHandle);
    IFlowStateMachineEditor::OnClose();
}

TSharedRef<SWidget> FFlowStateMachineEditor::CreateFlowStateMachineGraphEditor(
    const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph)
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
    InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(
        this, &FFlowStateMachineEditor::OnSelectedNodesChanged);
    InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FFlowStateMachineEditor::OnNodeDoubleClicked);
    // InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FBehaviorTreeEditor::OnNodeTitleCommitted);

    InGraph->OnScatteredNodesChanged.AddRaw(this, &FFlowStateMachineEditor::RefreshClassPalette);

    // Make full graph editor
    const bool bGraphIsEditable = InGraph->bEditable;
    return SNew(SGraphEditor)
        .AdditionalCommands(GraphEditorCommands)
        .IsEditable(this, &FFlowStateMachineEditor::InEditingMode, bGraphIsEditable)
        .Appearance(this, &FFlowStateMachineEditor::GetGraphAppearance)
        .GraphToEdit(InGraph)
        .GraphEvents(InEvents);
}

TSharedRef<SWidget> FFlowStateMachineEditor::CreateFlowStateMachineDetailView(const FWorkflowTabSpawnInfo& Info)
{
    FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);
    PropertyViewArgs.NotifyHook = this;
    // 始终隐藏具有“编辑默认值仅”（即 CPF_DisableEditOnInstance）标志的节点。
    PropertyViewArgs.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;

    DetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);
    DetailsView->SetIsPropertyEditingEnabledDelegate(
        FIsPropertyEditingEnabled::CreateSP(this, &FFlowStateMachineEditor::IsPropertyEditable));

    DetailsView->SetObject(nullptr);

    return SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .FillHeight(1.f)
        [
            DetailsView.ToSharedRef()
        ]
        + SVerticalBox::Slot()
        .VAlign(VAlign_Fill)
        .AutoHeight()
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
            .VAlign(VAlign_Fill)
            .HAlign(HAlign_Fill)
            .Padding(FMargin(5.f, 2.f))
            [
                // Refresh Node Button
                SNew(SOverlay)
                + SOverlay::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)
                [
                    SNew(SButton)
                    .OnClicked(this, &FFlowStateMachineEditor::OnNodeRefreshClicked)
                ]
                + SOverlay::Slot()
                .HAlign(HAlign_Center)
                .VAlign(VAlign_Center)
                [
                    SNew(STextBlock)
                    .Text(LOCTEXT("FSMGraphEditor", "Refresh Node"))
                    .ColorAndOpacity(FSlateColor(FLinearColor::Black))
                    .Visibility(EVisibility::SelfHitTestInvisible)
                ]
            ]
        ];
}

TSharedRef<SWidget> FFlowStateMachineEditor::CreateFlowStateMachineListView(const FWorkflowTabSpawnInfo& Info)
{
    return SAssignNew(ClassPalette, SFSGraphPalette, GetFlowStateMachine());
}

UFlowStateGraph* FFlowStateMachineEditor::GetFlowStateGraph() const
{
    return FlowStateMachine ? Cast<UFlowStateGraph>(FlowStateMachine->FSMGraph) : nullptr;
}

FText FFlowStateMachineEditor::GetLocalizedMode(FName InMode)
{
    static TMap<FName, FText> LocModes;

    if (LocModes.Num() == 0)
    {
        LocModes.Add(FEditorHelper::FlowStateMachineMode, LOCTEXT("FlowStateMachineMode", "FlowStateMachineMode"));
        LocModes.Add(FEditorHelper::CommonDataMode, LOCTEXT("CommonDataMode", "CommonDataMode"));
    }

    check(InMode != NAME_None);
    const FText* OutDesc = LocModes.Find(InMode);
    check(OutDesc);
    return *OutDesc;
}

FGraphAppearanceInfo FFlowStateMachineEditor::GetGraphAppearance() const
{
    FGraphAppearanceInfo AppearanceInfo;
    AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText", "FLOW STATE MACHINE");

    return AppearanceInfo;
}

void FFlowStateMachineEditor::OnSelectedNodesChanged(const TSet<UObject*>& NewSelection)
{
    UFlowStateGraph* MyGraph = Cast<UFlowStateGraph>(FlowStateMachine->FSMGraph);
    SelectedNode = nullptr;

    TArray<UObject*> SelectionNodes;
    SelectionNodes.Reserve(NewSelection.Num());
    for (UObject* Selection : NewSelection)
    {
        // 对选中的节点进行筛选，确保类型正确
        if (Selection->IsA<UFSGraphNodeBase>())
        {
            SelectionNodes.Add(Selection);
        }
    }

    // 若选中数量为 1 则改变 DetailView 的显示对象
    if (SelectionNodes.Num() == 1)
    {
        if (UFSGraphNodeBase* FSMGraphNode = Cast<UFSGraphNodeBase>(SelectionNodes[0]))
        {
            // 设置细节面板显示的对象为运行时节点
            DetailsView->SetObject(FSMGraphNode->NodeInstance);
            SelectedNode = FSMGraphNode;
        }
    }
    else
    {
        UFSGraph_RootNode* RootNode = nullptr;
        for (UEdGraphNode* Node : MyGraph->Nodes)
        {
            RootNode = Cast<UFSGraph_RootNode>(Node);
            if (RootNode != nullptr)
            {
                break;
            }
        }
        DetailsView->SetObject(RootNode);
    }
}

void FFlowStateMachineEditor::OnNodeDoubleClicked(UEdGraphNode* EdGraphNode)
{
    UFSGraphNodeBase* MyGraphNode = Cast<UFSGraphNodeBase>(EdGraphNode);
    if (MyGraphNode && MyGraphNode->NodeInstance && MyGraphNode->NodeInstance->GetClass()->HasAnyClassFlags(
        CLASS_CompiledFromBlueprint))
    {
        UClass* NodeClass = MyGraphNode->NodeInstance->GetClass();
        UPackage* Pkg = NodeClass->GetOuterUPackage();
        FString ClassName = NodeClass->GetName().LeftChop(2);
        UBlueprint* BlueprintOb = FindObject<UBlueprint>(Pkg, *ClassName);
        if (BlueprintOb)
        {
            GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(BlueprintOb);
        }
    }
}

FReply FFlowStateMachineEditor::OnNodeRefreshClicked()
{
    if (SelectedNode.IsValid() && SelectedNode->NodeInstance)
    {
        TArray<FStatePinInfo> StatePinInfos;
        SelectedNode->RefreshStateNode(true);
        return FReply::Handled();
    }
    return FReply::Unhandled();
}

void FFlowStateMachineEditor::SaveAsset_Execute()
{
    if (FlowStateMachine)
    {
        UFlowStateGraph* Graph = Cast<UFlowStateGraph>(FlowStateMachine->FSMGraph);
        if (Graph)
        {
            Graph->OnSave();
        }
    }
    IFlowStateMachineEditor::SaveAsset_Execute();
}

#undef LOCTEXT_NAMESPACE

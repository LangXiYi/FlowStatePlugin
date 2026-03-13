#pragma once
#include "IFlowStateMachineEditor.h"
#include "Graph/FlowStateGraph.h"
#include "SM/FlowStateMachine.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

struct FFlowStateEditorToolbar;
class UFSMCommonData;
class UFlowStateMachine;

class FFlowStateMachineEditor : public IFlowStateMachineEditor, public FNotifyHook
{
public:
    FFlowStateMachineEditor();

    /** 初始化状态机编辑器 */
    void InitFlowStateMachineEditor(EToolkitMode::Type Mode,
                                    const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);

    // Begin IToolkit interface
    virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
    virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
    // End of IToolkit interface

    // Begin IAssetEditorInstance
    /** 获取全局状态图表编辑器的引脚颜色 */
    virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor::Blue; }
    virtual FText GetToolkitName() const override;
    virtual FName GetToolkitFName() const override { return FName("FlowStateMachineEditor"); }
    virtual FText GetToolkitToolTipText() const override;
    virtual FText GetBaseToolkitName() const override { return FText::FromString("FlowStateMachineEditor"); }
    virtual FString GetWorldCentricTabPrefix() const override { return "FlowStateMachineEditor"; }
    // End of IAssetEditorInstance

    // Begin FEditorUndoClient Interface
    virtual void PostUndo(bool bSuccess) override;
    virtual void PostRedo(bool bSuccess) override;
    // End of FEditorUndoClient

    // Begin FNotifyHook
    virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
                                  FProperty* PropertyThatChanged) override;
    // End of FNotifyHook

    // @todo This is a hack for now until we reconcile the default toolbar with application modes [duplicated from counterpart in Blueprint Editor]
    void RegisterToolbarTab(const TSharedRef<class FTabManager>& InTabManager);

    void SaveEditedObjectState();

    /** 恢复状态机编辑图表，若不存在可用的则创建一个新的图表 */
    void RestoreFlowStateMachine();

    /** Check whether the behavior tree mode can be accessed (i.e whether we have a valid tree to edit) */
    bool CanAccessFlowStateMachineMode() const;

    /** Check whether the blackboard mode can be accessed (i.e whether we have a valid blackboard to edit) */
    bool CanAccessCommonDataMode() const;

    /** 当窗口关闭时触发该事件 */
    virtual void OnClose() override;

    //////////////////////////////////////////////////////////////
    /// Slate Widget
    //////////////////////////////////////////////////////////////

    /** 创建状态机图表编辑器 */
    TSharedRef<SWidget> CreateFlowStateMachineGraphEditor(const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph);

    /** 创建状态机细节面板 */
    TSharedRef<SWidget> CreateFlowStateMachineDetailView(const FWorkflowTabSpawnInfo& Info);

    /** 创建状态机节点列表 */
    TSharedRef<SWidget> CreateFlowStateMachineListView(const FWorkflowTabSpawnInfo& Info);

    //////////////////////////////////////////////////////////////
    /// Get Or Set
    //////////////////////////////////////////////////////////////

    /** Get editing asset */
    UFlowStateMachine* GetFlowStateMachine() const { return FlowStateMachine; }
    UFSMCommonData* GetCommonData() const { return CommonData; }
    /** 获得状态机编辑图表 */
    UFlowStateGraph* GetFlowStateGraph() const;

    /** Access the toolbar builder for this editor */
    TSharedPtr<FFlowStateEditorToolbar> GetToolbarBuilder() const { return ToolbarBuilder; }

    /**
     * Get the localized text to display for the specified mode
     * @param	InMode	The mode to display
     * @return the localized text representation of the mode
     */
    static FText GetLocalizedMode(FName InMode);

    bool InEditingMode(bool bGraphIsEditable) const { return bGraphIsEditable; }

    FGraphAppearanceInfo GetGraphAppearance() const;

    //////////////////////////////////////////////////////////////
    /// Graph Events
    //////////////////////////////////////////////////////////////
    virtual void OnSelectedNodesChanged(const TSet<UObject*>& NewSelection);

    virtual void OnNodeDoubleClicked(UEdGraphNode* EdGraphNode);

    virtual FReply OnNodeRefreshClicked();

    void OnGraphEditorFocused(TSharedRef<SGraphEditor> InGraphEditor);

    bool IsPropertyEditable() const;

    void RefreshClassPalette();

    void OnCollectState(UBlueprint* Blueprint);

protected:
    virtual void SaveAsset_Execute() override;

    // OnSelect

private:

protected:
    /** 正在编辑的状态机资产 */
    UFlowStateMachine* FlowStateMachine = nullptr;
    /** 正在编辑的状态机公用数据资产 */
    UFSMCommonData* CommonData = nullptr;

    /** 当前选中的节点，包括次要节点 */
    TWeakObjectPtr<UFSGraphNodeBase> SelectedNode = nullptr;

    /** 资产改变事件句柄 */
    FDelegateHandle StateCollectHandle;

private:
    // 管理不同编辑器图表
    TSharedPtr<FDocumentTracker> DocumentManager;
    TWeakPtr<FDocumentTabFactory> GraphEditorTabFactoryPtr;

    // 工具栏扩展器 FFSMEditorToolbar
    TSharedPtr<FFlowStateEditorToolbar> ToolbarBuilder;

    // 资产的细节面板
    // TSharedPtr<IDetailsView> AssetDetailsView;
    /** 节点的细节面板 */
    TSharedPtr<IDetailsView> DetailsView;

    /** 状态节点面板，支持拖拽放置新的节点 */
    TSharedPtr<class SFSGraphPalette> ClassPalette;
};

#pragma once
#include "IFlowStateMachineEditor.h"
#include "Graph/FSMGraph.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

struct FFSMEditorToolbar;
class UFSMCommonData;
class UFlowStateMachine;

class FFSMGraphEditor: public IFlowStateMachineEditor
{
public:
	FFSMGraphEditor();
	
	void InitFlowStateMachineEditor(EToolkitMode::Type Mode,
		const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);

	// IToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	// End of IToolkit interface
	
	// IAssetEditorInstance Begin
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor::Blue;}
	virtual FName GetToolkitFName() const override { return FName("FlowStateMachineEditor"); }
	virtual FText GetBaseToolkitName() const override { return FText::FromString("FlowStateMachineEditor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return "FlowStateMachineEditor"; }
	// IAssetEditorInstance End

	// @todo This is a hack for now until we reconcile the default toolbar with application modes [duplicated from counterpart in Blueprint Editor]
	void RegisterToolbarTab(const TSharedRef<class FTabManager>& InTabManager);
	
	void SaveEditedObjectState();

	/** 恢复状态机编辑图表，若不存在可用的则创建一个新的图表 */
	void RestoreFlowStateMachine();

	/** Check whether the behavior tree mode can be accessed (i.e whether we have a valid tree to edit) */
	bool CanAccessFlowStateMachineMode() const;

	/** Check whether the blackboard mode can be accessed (i.e whether we have a valid blackboard to edit) */
	bool CanAccessCommonDataMode() const;

	/** 创建状态机图表编辑器 */
	TSharedRef<SWidget> CreateFlowStateMachineGraphEditor(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph);

	/** 创建状态机细节面板 */
	TSharedRef<SWidget> CreateFlowStateMachineDetailView(const FWorkflowTabSpawnInfo& Info);

	//////////////////////////////////////////////////////////////
	/// Get Or Set
	//////////////////////////////////////////////////////////////
public:
	/** Get editing asset */
	FORCEINLINE UFlowStateMachine* GetFlowStateMachine() const { return FlowStateMachine; }
	FORCEINLINE UFSMCommonData* GetCommonData() const { return CommonData; }

	/** Access the toolbar builder for this editor */
	FORCEINLINE TSharedPtr<FFSMEditorToolbar> GetToolbarBuilder() const { return ToolbarBuilder; }

	/** 
	 * Get the localized text to display for the specified mode 
	 * @param	InMode	The mode to display
	 * @return the localized text representation of the mode
	 */
	static FText GetLocalizedMode(FName InMode);

	bool InEditingMode(bool bGraphIsEditable) const { return bGraphIsEditable; }
	FGraphAppearanceInfo GetGraphAppearance() const;

public:
	// Graph Events
	virtual void OnSelectedNodesChanged(const TSet<UObject*>& NewSelection);

	virtual void OnNodeDoubleClicked(UEdGraphNode* EdGraphNode);
	
protected:
	virtual void SaveAsset_Execute() override;

	// OnSelect

public:
	static FName const FlowStateMachineMode; 
	static FName const CommonDataMode; 

private:
	UFlowStateMachine* FlowStateMachine = nullptr;
	UFSMCommonData* CommonData = nullptr;

	// 管理不同编辑器图表
	TSharedPtr<FDocumentTracker> DocumentManager;
	TWeakPtr<FDocumentTabFactory> GraphEditorTabFactoryPtr;

	// 工具栏扩展器 FFSMEditorToolbar
	TSharedPtr<FFSMEditorToolbar> ToolbarBuilder;

	// 资产的细节面板
	TSharedPtr<IDetailsView> AssetDetailsView;
	// 节点的细节面板
	TSharedPtr<IDetailsView> DetailsView;
};

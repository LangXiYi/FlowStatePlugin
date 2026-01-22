#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMGraph.generated.h"

class UFSMGraphNode_JumpStart;
class UFlowStateMachine;
class UFSMGraphNodeBase;
class UFSMRuntimeNodeBase;
class UFSMRuntimeNode;
class UFSMGraphNode;

DECLARE_MULTICAST_DELEGATE(FOnScatteredNodesChanged);

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraph : public UEdGraph
{
	GENERATED_BODY()

public:
	virtual void Initialize();
	virtual void OnCreateGraph();
	virtual void OnLoadedGraph();

	/** 当执行保存文件时触发 */
	virtual void OnSave();
	/** 更新资产 */
	virtual void UpdateAsset(FString UpdateReason = "");

	void OnNodesPasted(const FString& String);

	virtual void NotifyGraphChanged() override;

	/** 根据图表得到内容创建状态机 */
	virtual void CreateFSMFromGraph(UFSMGraphNode* RootEdNode);

	// TODO::On Selected Node To Update Detail View

	void UpdateClassData();

	bool IsLocked() const;
	
	void LockUpdates();

	void UnlockUpdates();

	// Begin Object
	virtual void Serialize(FArchive& Ar) override;
	// End Of Object
	
#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif

	UFlowStateMachine* GetFSMAsset() const;

protected:
	/** 检查所有节点的有效性 */
	void UpdateAllNodesValidity();
	
	/** 生成缺少的节点，在图表被创建后调用 */
	void SpawnMissingNodes();

	void ClearRootNodeFlags();

	/** 移除孤儿节点（无父级节点且不是根节点的节点） */
	void RemoveOrphanedNodes();

	/** 收集所有的节点实例 */
	virtual void CollectAllNodeInstances(TSet<UObject*>& NodeInstances);
	virtual bool CanRemoveNestedObject(UObject* TestObject) const;
	virtual void OnNodeInstanceRemoved(UObject* NodeInstance) {}

public:
	/** 创建所有的子级节点 */
	static void CreateChildrenNodes(UFlowStateMachine* FSMAsset, UFSMRuntimeNode* RuntimeRootNode, const UFSMGraphNode* GraphRootNode, TArray<UObject*>& Stack);

	/** 创建所有的零散节点 */
	static void CreateScatteredNodes(UFlowStateMachine* FSMAsset, const TArray<const UFSMGraphNode*>& ScatteredNodes);

	/** 更新节点的错误信息 */
	static void UpdateNodeErrorMessage(UFSMGraphNodeBase& FSMNode);
	
public:
	void AddScatteredNode(const UFSMGraphNode* Node)
	{
		ScatteredNodes.Add(Node);
		OnScatteredNodesChanged.Broadcast();
	}
	void RemoveScatteredNode(const UFSMGraphNode* Node)
	{
		ScatteredNodes.Remove(Node);
		OnScatteredNodesChanged.Broadcast();
	}
	const TArray<const UFSMGraphNode*>& GetScatteredNodes() const { return ScatteredNodes; }

	FOnScatteredNodesChanged OnScatteredNodesChanged;

protected:
	UPROPERTY()
	TArray<const UFSMGraphNode*> ScatteredNodes;
	
private:
	bool bLockUpdates;

};


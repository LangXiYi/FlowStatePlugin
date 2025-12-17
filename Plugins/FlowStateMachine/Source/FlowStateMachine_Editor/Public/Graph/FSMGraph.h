#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMGraph.generated.h"

class UFSMRuntimeNode;
class UFSMGraphNode;

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
	virtual void UpdateAsset(int32 UpdateFlags = 0);

	/** 根据图表得到内容创建状态机 */
	virtual void CreateFSMFromGraph(UFSMGraphNode* RootEdNode);

	// TODO::On Selected Node To Update Detail View

protected:
	/** 生成缺少的节点，在图表被创建后调用 */
	void SpawnMissingNodes();

	void ClearRootNodeFlags();

	/** 移除孤儿节点（无父级节点且不是根节点的节点） */
	void RemoveOrphanedNodes();

	/** 收集所有的节点实例 */
	virtual void CollectAllNodeInstances(TSet<UObject*>& NodeInstances);
	virtual bool CanRemoveNestedObject(UObject* TestObject) const;
	virtual void OnNodeInstanceRemoved(UObject* NodeInstance) {}

	/** 创建所有的子级节点 */
	void CreateChildrenNodes(class UFlowStateMachine* FSMAsset, UFSMRuntimeNode* RuntimeRootNode, UFSMGraphNode* GraphRootNode, uint16& ExecuteIndex, uint8 TreeDepth);
};


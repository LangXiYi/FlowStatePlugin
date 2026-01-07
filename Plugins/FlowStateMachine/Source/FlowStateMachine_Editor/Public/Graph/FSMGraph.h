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

	void OnNodesPasted(const FString& String);

	/** 根据图表得到内容创建状态机 */
	virtual void CreateFSMFromGraph(UFSMGraphNode* RootEdNode);

	// TODO::On Selected Node To Update Detail View

	void UpdateClassData();

	bool IsLocked() const;
	
	void LockUpdates();

	void UnlockUpdates();

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif

	UFlowStateMachine* GetFSMAsset() const;

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

	/** 创建所有的子级节点
	 * 注意：避免出现环形，否则程序无法正确处理会直接报错，推荐使用 JumpState 与 JumpNode   
	 */
	void CreateChildrenNodes(class UFlowStateMachine* FSMAsset, UFSMRuntimeNode* RuntimeRootNode, UFSMGraphNode* GraphRootNode, TArray<UObject*>& Stack);

	// 环形检查，避免递归无限重复
	bool CheckRing(UFSMGraphNodeBase* StartNode, UFSMGraphNodeBase* BreakNode);
	
private:
	bool bLockUpdates;

	TArray<UFSMGraphNode_JumpStart*> JumpStartNodes;
};


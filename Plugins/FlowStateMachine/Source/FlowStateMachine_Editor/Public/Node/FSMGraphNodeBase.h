// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNodeBase.generated.h"

class UFSMRuntimeNodeBase;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNodeBase : public UEdGraphNode
{
	GENERATED_BODY()

public:
	/** 当节点被放置后调用，创建 RuntimeNode 实例 */
	virtual void PostPasteNode() override;

	/** 当节点被放置后调用，创建 RuntimeNode 实例 */
	virtual void PostPlacedNewNode() override;

	/** 自动连接创建的新节点 */
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	/** 是否可以删除该节点 */
	virtual bool CanUserDeleteNode() const override { return true; }

	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance();
	
	/** 为节点添加一个次要节点 */
	void AddSubNode( UFSMGraphNodeBase* SubNode, class UEdGraph* ParentGraph);

	/** 为节点添加一个次要节点 */
	virtual void OnSubNodeAdded( UFSMGraphNodeBase* SubNode) {}

	/** 将一个次要节点从当前节点中移除 */
	void RemoveSubNode(UFSMGraphNodeBase* SubNode);

	/** 将一个次要节点从当前节点中移除 */
	virtual void OnSubNodeRemoved(UFSMGraphNodeBase* SubNode) {}

	void RemoveAllSubNode();
	
	/** 复制节点 */
	virtual void PostCopyNode();

	/** 重设节点的拥有者 */
	void ResetNodeOwner();

	void UpdateNodeClassData();

	void UpdateNodeClassDataFrom(UClass* InstanceClass, FGraphNodeClassData& UpdatedData);
	
	/** 获取状态机图表 */
	class UFSMGraph* GetFSMGraph() const;

protected:
	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

public:
	/** 类型数据，目前使用的是 AIGraphType 中定义的类型，后续可以考虑使用自定义的类型 */
	FGraphNodeClassData ClassData;

	/**	运行时节点实例 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNodeBase* RuntimeNode;

	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMGraphNodeBase* ParentNode;

	/** 所有次要节点 */
	TArray<UFSMGraphNodeBase*> SubNodes;

	bool bIsRootNode = false;

	/** error message for node */
	UPROPERTY()
	FString ErrorMessage;

public:
	/** subnode index assigned during copy operation to connect nodes again on paste */
	UPROPERTY()
	int32 CopySubNodeIndex;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNodeBase.generated.h"

class UFSMRuntimeNodeBase;

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNodeBase : public UEdGraphNode
{
	GENERATED_BODY()

public:
	/** 当节点被放置后调用，创建 RuntimeNode 实例 */
	virtual void PostPasteNode() override;

	/** 当节点被放置后调用，创建 RuntimeNode 实例 */
	virtual void PostPlacedNewNode() override;

	/** 为节点提供差异化比较 */
	virtual void FindDiffs(class UEdGraphNode* OtherNode, FDiffResults& Results) override;

	virtual void PrepareForCopying() override;
	virtual void PostCopyNode();

	virtual void NodeConnectionListChanged() override;

	/** 获取节点的名称 */
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	/** 自动连接创建的新节点 */
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

	/** 是否可以删除该节点 */
	virtual bool CanUserDeleteNode() const override { return true; }

	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance();

	/** 重设节点的拥有者 */
	virtual void ResetNodeOwner();

	void UpdateNodeClassData();

	void UpdateNodeClassDataFrom(UClass* InstanceClass, FGraphNodeClassData& UpdatedData);
	
	/** 获取状态机图表 */
	class UFSMGraph* GetFSMGraph() const;

	bool UserBlueprint() const;

#if WITH_EDITOR

	virtual void PostEditUndo() override;

	virtual void PostEditImport() override;

#endif

	/** 检查引脚的连接性 */
	virtual FPinConnectionResponse CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const;

	/** 检查节点的有效性 */
	virtual bool CheckNodeValidity();

protected:
	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

public:
	/** 类型数据，目前使用的是 AIGraphType 中定义的类型，后续可以考虑使用自定义的类型 */
	UPROPERTY()
	FGraphNodeClassData ClassData;

	/**	运行时节点实例 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNodeBase* RuntimeNode;

	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMGraphNodeBase* ParentNode;

	bool bIsRootNode = false;

	/** error message for node */
	UPROPERTY()
	FString ErrorMessage;

public:
	/** subnode index assigned during copy operation to connect nodes again on paste */
	UPROPERTY()
	int32 CopySubNodeIndex;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNodeBase.generated.h"

class UFSMGraphNode;
class UFSMGraph;
class UFSMRuntimeNode;

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

	/** 获取状态机图表 */
	UFSMGraph* GetFSMGraph() const;

protected:
	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

public:
	/** 类型数据，目前使用的是 AIGraphType 中定义的类型，后续可以考虑使用自定义的类型 */
	FGraphNodeClassData ClassData;

	/**	运行时会随图表节点一起创建。 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNode* RuntimeNode;

	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMGraphNode* ParentNode;

	bool bIsRootNode = false;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMGraphNodeBase.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphSubNode.generated.h"

class UFSMCommonData;
class UFSMGraph;

class UFSMRuntimeNode;

/**
 * 图表子节点
 * 不能单独创建，必须在某个主节点下才能创建，创建后会自动附加到主节点上
 *     ParentNode
 *     |___ SubNode_A
 *     |___ SubNode_B
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphSubNode : public UFSMGraphNodeBase
{
	GENERATED_BODY()

public:

};

// 更改 Decorator 名称为 Condition
// 用于标识由当前状态切换至下一状态的条件
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Condition : public UFSMGraphSubNode
{
	GENERATED_BODY()

public:
};

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Action : public UFSMGraphSubNode
{
	GENERATED_BODY()

public:
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "EdGraph/EdGraphNode.h"
#include "Utility/FSMUtility.h"
#include "FSGraphNodeBase.generated.h"

class UFSMNodeInstanceBase;

UCLASS()
class FLOWSTATEEDITOR_API UFSGraphNodeBase : public UEdGraphNode
{
    GENERATED_BODY()

public:
    /////////////////////////////////////////////////////
    // UEdGraphNode Function
    /////////////////////////////////////////////////////

    /** 当节点被粘贴后调用，创建 NodeInstance 实例 */
    virtual void PostPasteNode() override;

    /** 当节点被放置后调用，创建 NodeInstance 实例 */
    virtual void PostPlacedNewNode() override;

    virtual void PrepareForCopying() override;

    /** 获取节点标题的颜色 */
    virtual FLinearColor GetNodeTitleColor() const override;

    /** 获取节点的名称 */
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

    virtual FString GetNodeTitleFormatString() const;

    /** 获取节点的提示文本 */
    virtual FText GetTooltipText() const override;

    virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;

    /** 自动连接创建的新节点 */
    virtual void AutowireNewNode(UEdGraphPin* FromPin) override;

    /** 是否可以删除该节点 */
    virtual bool CanUserDeleteNode() const override { return true; }

    /** 节点连接改变事件 */
    virtual void NodeConnectionListChanged() override;

    /** 引脚连接改变事件 */
    virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;

    /** 为节点提供差异化比较 */
    virtual void FindDiffs(class UEdGraphNode* OtherNode, FDiffResults& Results) override;

    /** 重写该函数扩展节点自身的警告 */
    virtual bool IsDeprecated() const override;

    /** 重写该函数扩展引用依赖缺失的警告 */
    virtual bool HasDeprecatedReference() const override;

    /** 子类重写该函数，并返回自定义的错误日志 */
    virtual FEdGraphNodeDeprecationResponse GetDeprecationResponse(EEdGraphNodeDeprecationType DeprecationType) const override;

    virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

    virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;

    /////////////////////////////////////////////////////
    // FSMGraphNodeBase Function
    /////////////////////////////////////////////////////

    // 监听 NodeInstance 类的改变，当它发生变化时刷新引脚
    virtual void ReconstructNode() override;
    virtual void RefreshStateNode(bool bIsAutoRemoveOrphanedNode);

    virtual void PostCopyNode();

    /** 初始化运行时节点实例时调用  */
    virtual void InitializeInstance();

    /** 重设节点的拥有者 */
    virtual void ResetNodeOwner();

    void UpdateNodeClassData();

    void UpdateNodeClassDataFrom(UClass* InstanceClass, FGraphNodeClassData& UpdatedData);

    /** 获取状态机图表 */
    class UFSMGraph* GetFSMGraph() const;

    bool UserBlueprint() const;

    /** 识别出此节点已发生更改，这些更改需要与编译后的脚本进行同步。*/
    void MarkNodeRequiresSynchronization(bool bIsUpdateAsset, const FString& Reason = "");

#if WITH_EDITOR

    virtual void PostEditUndo() override;

    virtual void PostEditImport() override;

#endif

    /** 检查引脚的连接性 */
    virtual FPinConnectionResponse CheckPinConnection(const UFSGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const;

protected:
    UEdGraphPin*         GetInputPin() const;
    TArray<UEdGraphPin*> GetOutputPins() const;
    FText                GetNodeTitleSuffix() const;

public:
    /** 所有次要节点 */
    UPROPERTY()
    TArray<UFSGraphNodeBase*> SubNodes;

    /** 类型数据，目前使用的是 AIGraphType 中定义的类型，后续可以考虑使用自定义的类型 */
    UPROPERTY()
    FGraphNodeClassData ClassData;

    /**	运行时节点实例 */
    UPROPERTY()
    UFSMNodeInstanceBase* NodeInstance;

    /** 父级节点 */
    UPROPERTY()
    UFSGraphNodeBase* ParentNode;

    bool bIsRootNode = false;

    /** error message for node */
    UPROPERTY()
    FString ErrorMessage;

    /** subnode index assigned during copy operation to connect nodes again on paste */
    UPROPERTY()
    int32 CopySubNodeIndex;
};

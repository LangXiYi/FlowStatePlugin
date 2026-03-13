// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Utility/FSMUtility.h"
#include "FlowStateCollectInterface.generated.h"

UINTERFACE()
class FLOWSTATEMACHINE_API UFlowStateCollectInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 状态引脚统计接口
 * 状态节点会收集所有继承自该类型对象，并自动创建对应的执行引脚
 * @NOTE:: C++ 继承自该接口后，必须重载 GetStatePinInfos 函数，并在最后手动调用 Execute_GetStatePinInfos
 */
class FLOWSTATEMACHINE_API IFlowStateCollectInterface
{
    GENERATED_BODY()

public:
    /** 调用蓝图函数并执行 */
    static void Execute_GetStatePinInfos(const UObject* Target, TArray<FStatePinInfo>& PinInfos);

    /** 允许通过 C++ 自定义该函数，但需要注意手动调用 Execute_GetStatePinInfos 确保蓝图函数会被执行 */
    virtual void GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const;

protected:
    /** 蓝图实现 */
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "GetStatePinInfos"))
    void NativeGetStatePinInfos(TArray<FName>& Array) const;
};

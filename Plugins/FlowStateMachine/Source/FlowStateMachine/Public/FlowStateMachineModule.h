// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


/**
 * TODO::创建一个简单的对象池工具，用于管理所有的StaticActor 与 SkeletalActor
 */
class FFlowStateMachineModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

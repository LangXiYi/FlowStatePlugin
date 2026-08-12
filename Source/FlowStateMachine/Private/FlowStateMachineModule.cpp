// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlowStateMachineModule.h"

#define LOCTEXT_NAMESPACE "FFlowStateMachineModule"

void FFlowStateMachineModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// TODO::自动注册 MetaData 到资产管理器中，避免每次都需要修改设置添加扫描路径
}

void FFlowStateMachineModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFlowStateMachineModule, FlowStateMachine)
// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOWSTATEMACHINE_FSMUtility_generated_h
#error "FSMUtility.generated.h already included, missing '#pragma once' in FSMUtility.h"
#endif
#define FLOWSTATEMACHINE_FSMUtility_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMUtility_h_80_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics; \
	FLOWSTATEMACHINE_API static class UScriptStruct* StaticStruct();


template<> FLOWSTATEMACHINE_API UScriptStruct* StaticStruct<struct FStateChildNodeHelper>();

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMUtility_h_54_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStatePinInfo_Statics; \
	FLOWSTATEMACHINE_API static class UScriptStruct* StaticStruct();


template<> FLOWSTATEMACHINE_API UScriptStruct* StaticStruct<struct FStatePinInfo>();

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMUtility_h_25_DELEGATE \
static inline void FStateExecuteDelegate_DelegateWrapper(const FScriptDelegate& StateExecuteDelegate) \
{ \
	StateExecuteDelegate.ProcessDelegate<UObject>(NULL); \
}


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMUtility_h


#define FOREACH_ENUM_EFLOWSTATELIFETIME(op) \
	op(EFlowStateLifetime::None) \
	op(EFlowStateLifetime::Static) \
	op(EFlowStateLifetime::Kill) \
	op(EFlowStateLifetime::Hidden) 

enum class EFlowStateLifetime : uint8;
template<> FLOWSTATEMACHINE_API UEnum* StaticEnum<EFlowStateLifetime>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

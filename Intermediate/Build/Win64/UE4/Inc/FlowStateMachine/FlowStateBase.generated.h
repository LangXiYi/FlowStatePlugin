// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UFlowStateContext;
#ifdef FLOWSTATEMACHINE_FlowStateBase_generated_h
#error "FlowStateBase.generated.h already included, missing '#pragma once' in FlowStateBase.h"
#endif
#define FLOWSTATEMACHINE_FlowStateBase_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDeltaTime);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDeltaTime);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_EVENT_PARMS \
	struct FlowStateBase_eventNativeOnInitialize_Parms \
	{ \
		UFlowStateContext* InContext; \
	}; \
	struct FlowStateBase_eventOnTick_Parms \
	{ \
		float DeltaTime; \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlowStateBase(); \
	friend struct Z_Construct_UClass_UFlowStateBase_Statics; \
public: \
	DECLARE_CLASS(UFlowStateBase, UFSMRuntimeNode_State, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateBase)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUFlowStateBase(); \
	friend struct Z_Construct_UClass_UFlowStateBase_Statics; \
public: \
	DECLARE_CLASS(UFlowStateBase, UFSMRuntimeNode_State, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateBase)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateBase(UFlowStateBase&&); \
	NO_API UFlowStateBase(const UFlowStateBase&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateBase(UFlowStateBase&&); \
	NO_API UFlowStateBase(const UFlowStateBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateBase)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_PRIVATE_PROPERTY_OFFSET
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_28_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFlowStateBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

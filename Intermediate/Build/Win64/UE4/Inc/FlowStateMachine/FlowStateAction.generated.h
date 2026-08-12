// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UFSMRuntimeNode;
#ifdef FLOWSTATEMACHINE_FlowStateAction_generated_h
#error "FlowStateAction.generated.h already included, missing '#pragma once' in FlowStateAction.h"
#endif
#define FLOWSTATEMACHINE_FlowStateAction_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_EVENT_PARMS \
	struct FlowStateAction_eventOnExecuteAction_Parms \
	{ \
		UFSMRuntimeNode* Instance; \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlowStateAction(); \
	friend struct Z_Construct_UClass_UFlowStateAction_Statics; \
public: \
	DECLARE_CLASS(UFlowStateAction, UFSMRuntimeSubNode_Action, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateAction)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUFlowStateAction(); \
	friend struct Z_Construct_UClass_UFlowStateAction_Statics; \
public: \
	DECLARE_CLASS(UFlowStateAction, UFSMRuntimeSubNode_Action, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateAction)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateAction) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateAction); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateAction(UFlowStateAction&&); \
	NO_API UFlowStateAction(const UFlowStateAction&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateAction(UFlowStateAction&&); \
	NO_API UFlowStateAction(const UFlowStateAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateAction); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateAction)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_PRIVATE_PROPERTY_OFFSET
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_13_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFlowStateAction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateAction_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

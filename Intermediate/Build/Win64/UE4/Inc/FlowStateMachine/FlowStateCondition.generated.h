// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UFlowStateContext;
#ifdef FLOWSTATEMACHINE_FlowStateCondition_generated_h
#error "FlowStateCondition.generated.h already included, missing '#pragma once' in FlowStateCondition.h"
#endif
#define FLOWSTATEMACHINE_FlowStateCondition_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_EVENT_PARMS \
	struct FlowStateCondition_eventBP_Condition_Parms \
	{ \
		UFlowStateContext* Context; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		FlowStateCondition_eventBP_Condition_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlowStateCondition(); \
	friend struct Z_Construct_UClass_UFlowStateCondition_Statics; \
public: \
	DECLARE_CLASS(UFlowStateCondition, UFSMRuntimeSubNode_Condition, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateCondition)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUFlowStateCondition(); \
	friend struct Z_Construct_UClass_UFlowStateCondition_Statics; \
public: \
	DECLARE_CLASS(UFlowStateCondition, UFSMRuntimeSubNode_Condition, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateCondition)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateCondition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateCondition) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateCondition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateCondition); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateCondition(UFlowStateCondition&&); \
	NO_API UFlowStateCondition(const UFlowStateCondition&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateCondition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateCondition(UFlowStateCondition&&); \
	NO_API UFlowStateCondition(const UFlowStateCondition&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateCondition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateCondition); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateCondition)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_PRIVATE_PROPERTY_OFFSET
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_12_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFlowStateCondition>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateCondition_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

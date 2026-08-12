// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UFlowStateContext;
#ifdef FLOWSTATEMACHINE_FSMRuntimeNodeBase_generated_h
#error "FSMRuntimeNodeBase.generated.h already included, missing '#pragma once' in FSMRuntimeNodeBase.h"
#endif
#define FLOWSTATEMACHINE_FSMRuntimeNodeBase_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetStateContext); \
	DECLARE_FUNCTION(execSwitchToByName); \
	DECLARE_FUNCTION(execTrySwitchTo);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetStateContext); \
	DECLARE_FUNCTION(execSwitchToByName); \
	DECLARE_FUNCTION(execTrySwitchTo);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMRuntimeNodeBase(); \
	friend struct Z_Construct_UClass_UFSMRuntimeNodeBase_Statics; \
public: \
	DECLARE_CLASS(UFSMRuntimeNodeBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMRuntimeNodeBase) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMRuntimeNodeBase*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUFSMRuntimeNodeBase(); \
	friend struct Z_Construct_UClass_UFSMRuntimeNodeBase_Statics; \
public: \
	DECLARE_CLASS(UFSMRuntimeNodeBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMRuntimeNodeBase) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMRuntimeNodeBase*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMRuntimeNodeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMRuntimeNodeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMRuntimeNodeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMRuntimeNodeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMRuntimeNodeBase(UFSMRuntimeNodeBase&&); \
	NO_API UFSMRuntimeNodeBase(const UFSMRuntimeNodeBase&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMRuntimeNodeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMRuntimeNodeBase(UFSMRuntimeNodeBase&&); \
	NO_API UFSMRuntimeNodeBase(const UFSMRuntimeNodeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMRuntimeNodeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMRuntimeNodeBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMRuntimeNodeBase)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__StateContext() { return STRUCT_OFFSET(UFSMRuntimeNodeBase, StateContext); } \
	FORCEINLINE static uint32 __PPO__NodeName() { return STRUCT_OFFSET(UFSMRuntimeNodeBase, NodeName); } \
	FORCEINLINE static uint32 __PPO__AllParentNodes() { return STRUCT_OFFSET(UFSMRuntimeNodeBase, AllParentNodes); } \
	FORCEINLINE static uint32 __PPO__FSMAsset() { return STRUCT_OFFSET(UFSMRuntimeNodeBase, FSMAsset); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_17_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMRuntimeNodeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNodeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

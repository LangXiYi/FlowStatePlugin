// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOWSTATEMACHINE_FSMRuntimeNode_generated_h
#error "FSMRuntimeNode.generated.h already included, missing '#pragma once' in FSMRuntimeNode.h"
#endif
#define FLOWSTATEMACHINE_FSMRuntimeNode_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMRuntimeNode(); \
	friend struct Z_Construct_UClass_UFSMRuntimeNode_Statics; \
public: \
	DECLARE_CLASS(UFSMRuntimeNode, UFSMRuntimeNodeBase, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMRuntimeNode)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUFSMRuntimeNode(); \
	friend struct Z_Construct_UClass_UFSMRuntimeNode_Statics; \
public: \
	DECLARE_CLASS(UFSMRuntimeNode, UFSMRuntimeNodeBase, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMRuntimeNode)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMRuntimeNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMRuntimeNode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMRuntimeNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMRuntimeNode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMRuntimeNode(UFSMRuntimeNode&&); \
	NO_API UFSMRuntimeNode(const UFSMRuntimeNode&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMRuntimeNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMRuntimeNode(UFSMRuntimeNode&&); \
	NO_API UFSMRuntimeNode(const UFSMRuntimeNode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMRuntimeNode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMRuntimeNode); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMRuntimeNode)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ChildStateHelpers() { return STRUCT_OFFSET(UFSMRuntimeNode, ChildStateHelpers); } \
	FORCEINLINE static uint32 __PPO__Actions() { return STRUCT_OFFSET(UFSMRuntimeNode, Actions); } \
	FORCEINLINE static uint32 __PPO__Services() { return STRUCT_OFFSET(UFSMRuntimeNode, Services); } \
	FORCEINLINE static uint32 __PPO__Conditions() { return STRUCT_OFFSET(UFSMRuntimeNode, Conditions); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_19_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMRuntimeNode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_RuntimeNode_FSMRuntimeNode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

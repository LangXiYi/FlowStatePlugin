// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOWSTATEMACHINE_EDITOR_FSMGraph_generated_h
#error "FSMGraph.generated.h already included, missing '#pragma once' in FSMGraph.h"
#endif
#define FLOWSTATEMACHINE_EDITOR_FSMGraph_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UFSMGraph, NO_API)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMGraph(); \
	friend struct Z_Construct_UClass_UFSMGraph_Statics; \
public: \
	DECLARE_CLASS(UFSMGraph, UEdGraph, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine_Editor"), NO_API) \
	DECLARE_SERIALIZER(UFSMGraph) \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_ARCHIVESERIALIZER


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUFSMGraph(); \
	friend struct Z_Construct_UClass_UFSMGraph_Statics; \
public: \
	DECLARE_CLASS(UFSMGraph, UEdGraph, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine_Editor"), NO_API) \
	DECLARE_SERIALIZER(UFSMGraph) \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_ARCHIVESERIALIZER


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMGraph(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMGraph) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMGraph); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMGraph); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMGraph(UFSMGraph&&); \
	NO_API UFSMGraph(const UFSMGraph&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMGraph(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMGraph(UFSMGraph&&); \
	NO_API UFSMGraph(const UFSMGraph&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMGraph); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMGraph); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMGraph)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ScatteredNodes() { return STRUCT_OFFSET(UFSMGraph, ScatteredNodes); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_15_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<class UFSMGraph>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Editor_Public_Graph_FSMGraph_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

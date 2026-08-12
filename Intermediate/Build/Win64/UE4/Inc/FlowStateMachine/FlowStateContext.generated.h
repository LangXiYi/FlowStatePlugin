// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGuid;
class UFSMCommonDataManager;
class UFSMRuntimeNode;
class UFlowStateWidgetLayerManager;
enum class EFlowStateWidgetLayer : uint8;
class UFlowStateLayoutWidget;
#ifdef FLOWSTATEMACHINE_FlowStateContext_generated_h
#error "FlowStateContext.generated.h already included, missing '#pragma once' in FlowStateContext.h"
#endif
#define FLOWSTATEMACHINE_FlowStateContext_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetScatteredNodeIDs); \
	DECLARE_FUNCTION(execGetCommonDataManager); \
	DECLARE_FUNCTION(execGetCurrentState); \
	DECLARE_FUNCTION(execGetLayoutManager); \
	DECLARE_FUNCTION(execGetLayoutWidget); \
	DECLARE_FUNCTION(execKillActorCache);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetScatteredNodeIDs); \
	DECLARE_FUNCTION(execGetCommonDataManager); \
	DECLARE_FUNCTION(execGetCurrentState); \
	DECLARE_FUNCTION(execGetLayoutManager); \
	DECLARE_FUNCTION(execGetLayoutWidget); \
	DECLARE_FUNCTION(execKillActorCache);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlowStateContext(); \
	friend struct Z_Construct_UClass_UFlowStateContext_Statics; \
public: \
	DECLARE_CLASS(UFlowStateContext, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateContext)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUFlowStateContext(); \
	friend struct Z_Construct_UClass_UFlowStateContext_Statics; \
public: \
	DECLARE_CLASS(UFlowStateContext, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateContext)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateContext(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateContext) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateContext); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateContext); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateContext(UFlowStateContext&&); \
	NO_API UFlowStateContext(const UFlowStateContext&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateContext(UFlowStateContext&&); \
	NO_API UFlowStateContext(const UFlowStateContext&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateContext); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateContext); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateContext)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurState() { return STRUCT_OFFSET(UFlowStateContext, CurState); } \
	FORCEINLINE static uint32 __PPO__InstanceStack() { return STRUCT_OFFSET(UFlowStateContext, InstanceStack); } \
	FORCEINLINE static uint32 __PPO__RootState() { return STRUCT_OFFSET(UFlowStateContext, RootState); } \
	FORCEINLINE static uint32 __PPO__ScatteredNodes() { return STRUCT_OFFSET(UFlowStateContext, ScatteredNodes); } \
	FORCEINLINE static uint32 __PPO__CommonDataManager() { return STRUCT_OFFSET(UFlowStateContext, CommonDataManager); } \
	FORCEINLINE static uint32 __PPO__StateMachine() { return STRUCT_OFFSET(UFlowStateContext, StateMachine); } \
	FORCEINLINE static uint32 __PPO__WidgetLayers() { return STRUCT_OFFSET(UFlowStateContext, WidgetLayers); } \
	FORCEINLINE static uint32 __PPO__CacheTemplateObjects() { return STRUCT_OFFSET(UFlowStateContext, CacheTemplateObjects); } \
	FORCEINLINE static uint32 __PPO__ScatteredNodeMapping() { return STRUCT_OFFSET(UFlowStateContext, ScatteredNodeMapping); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_28_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFlowStateContext>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FlowStateContext_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

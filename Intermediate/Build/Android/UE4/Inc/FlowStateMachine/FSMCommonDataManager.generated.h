// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
struct FVector;
class UObject;
#ifdef FLOWSTATEMACHINE_FSMCommonDataManager_generated_h
#error "FSMCommonDataManager.generated.h already included, missing '#pragma once' in FSMCommonDataManager.h"
#endif
#define FLOWSTATEMACHINE_FSMCommonDataManager_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetValueAsRotator); \
	DECLARE_FUNCTION(execSetValueAsVector); \
	DECLARE_FUNCTION(execSetValueAsName); \
	DECLARE_FUNCTION(execSetValueAsString); \
	DECLARE_FUNCTION(execSetValueAsBool); \
	DECLARE_FUNCTION(execSetValueAsFloat); \
	DECLARE_FUNCTION(execSetValueAsInt); \
	DECLARE_FUNCTION(execSetValueAsEnum); \
	DECLARE_FUNCTION(execSetValueAsClass); \
	DECLARE_FUNCTION(execSetValueAsObject); \
	DECLARE_FUNCTION(execGetValueAsRotator); \
	DECLARE_FUNCTION(execGetValueAsVector); \
	DECLARE_FUNCTION(execGetValueAsName); \
	DECLARE_FUNCTION(execGetValueAsString); \
	DECLARE_FUNCTION(execGetValueAsBool); \
	DECLARE_FUNCTION(execGetValueAsFloat); \
	DECLARE_FUNCTION(execGetValueAsInt); \
	DECLARE_FUNCTION(execGetValueAsEnum); \
	DECLARE_FUNCTION(execGetValueAsClass); \
	DECLARE_FUNCTION(execGetValueAsObject);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetValueAsRotator); \
	DECLARE_FUNCTION(execSetValueAsVector); \
	DECLARE_FUNCTION(execSetValueAsName); \
	DECLARE_FUNCTION(execSetValueAsString); \
	DECLARE_FUNCTION(execSetValueAsBool); \
	DECLARE_FUNCTION(execSetValueAsFloat); \
	DECLARE_FUNCTION(execSetValueAsInt); \
	DECLARE_FUNCTION(execSetValueAsEnum); \
	DECLARE_FUNCTION(execSetValueAsClass); \
	DECLARE_FUNCTION(execSetValueAsObject); \
	DECLARE_FUNCTION(execGetValueAsRotator); \
	DECLARE_FUNCTION(execGetValueAsVector); \
	DECLARE_FUNCTION(execGetValueAsName); \
	DECLARE_FUNCTION(execGetValueAsString); \
	DECLARE_FUNCTION(execGetValueAsBool); \
	DECLARE_FUNCTION(execGetValueAsFloat); \
	DECLARE_FUNCTION(execGetValueAsInt); \
	DECLARE_FUNCTION(execGetValueAsEnum); \
	DECLARE_FUNCTION(execGetValueAsClass); \
	DECLARE_FUNCTION(execGetValueAsObject);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMCommonDataManager(); \
	friend struct Z_Construct_UClass_UFSMCommonDataManager_Statics; \
public: \
	DECLARE_CLASS(UFSMCommonDataManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCommonDataManager)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUFSMCommonDataManager(); \
	friend struct Z_Construct_UClass_UFSMCommonDataManager_Statics; \
public: \
	DECLARE_CLASS(UFSMCommonDataManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCommonDataManager)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCommonDataManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCommonDataManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCommonDataManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCommonDataManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCommonDataManager(UFSMCommonDataManager&&); \
	NO_API UFSMCommonDataManager(const UFSMCommonDataManager&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCommonDataManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCommonDataManager(UFSMCommonDataManager&&); \
	NO_API UFSMCommonDataManager(const UFSMCommonDataManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCommonDataManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCommonDataManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCommonDataManager)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CommonDataInstance() { return STRUCT_OFFSET(UFSMCommonDataManager, CommonDataInstance); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_13_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMCommonDataManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_SM_FSMCommonDataManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EFlowStateLifetime : uint8;
class UObject;
class UFlowStateLayoutWidget;
class UUserWidget;
struct FGameplayTag;
class UWidget;
class UFSMCommonDataManager;
class UFlowStateBase;
class UFlowStateContext;
#ifdef FLOWSTATEMACHINE_FSMFunctionLibrary_generated_h
#error "FSMFunctionLibrary.generated.h already included, missing '#pragma once' in FSMFunctionLibrary.h"
#endif
#define FLOWSTATEMACHINE_FSMFunctionLibrary_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInitActorLifetimeState); \
	DECLARE_FUNCTION(execCreateAndBindWidget); \
	DECLARE_FUNCTION(execFindWidgetFromCache); \
	DECLARE_FUNCTION(execFindActorFromCache); \
	DECLARE_FUNCTION(execGetCommonDataManager); \
	DECLARE_FUNCTION(execGetCurFlowStateAs); \
	DECLARE_FUNCTION(execGetCurFlowState); \
	DECLARE_FUNCTION(execGetFlowStateContext);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInitActorLifetimeState); \
	DECLARE_FUNCTION(execCreateAndBindWidget); \
	DECLARE_FUNCTION(execFindWidgetFromCache); \
	DECLARE_FUNCTION(execFindActorFromCache); \
	DECLARE_FUNCTION(execGetCommonDataManager); \
	DECLARE_FUNCTION(execGetCurFlowStateAs); \
	DECLARE_FUNCTION(execGetCurFlowState); \
	DECLARE_FUNCTION(execGetFlowStateContext);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMFunctionLibrary(); \
	friend struct Z_Construct_UClass_UFSMFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UFSMFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMFunctionLibrary)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_INCLASS \
private: \
	static void StaticRegisterNativesUFSMFunctionLibrary(); \
	friend struct Z_Construct_UClass_UFSMFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UFSMFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMFunctionLibrary)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMFunctionLibrary(UFSMFunctionLibrary&&); \
	NO_API UFSMFunctionLibrary(const UFSMFunctionLibrary&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMFunctionLibrary(UFSMFunctionLibrary&&); \
	NO_API UFSMFunctionLibrary(const UFSMFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMFunctionLibrary)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_PRIVATE_PROPERTY_OFFSET
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_22_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Library_FSMFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

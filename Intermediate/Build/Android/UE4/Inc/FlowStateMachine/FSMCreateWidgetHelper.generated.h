// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class UWidget;
#ifdef FLOWSTATEMACHINE_FSMCreateWidgetHelper_generated_h
#error "FSMCreateWidgetHelper.generated.h already included, missing '#pragma once' in FSMCreateWidgetHelper.h"
#endif
#define FLOWSTATEMACHINE_FSMCreateWidgetHelper_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_RPC_WRAPPERS \
	virtual APlayerController* GetPlayerController_Implementation(); \
 \
	DECLARE_FUNCTION(execGetPlayerController);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual APlayerController* GetPlayerController_Implementation(); \
 \
	DECLARE_FUNCTION(execGetPlayerController);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_EVENT_PARMS \
	struct FSMCreateWidgetHelper_eventGetPlayerController_Parms \
	{ \
		APlayerController* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		FSMCreateWidgetHelper_eventGetPlayerController_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct FSMCreateWidgetHelper_eventInitializeWidget_Parms \
	{ \
		UWidget* ResultWidget; \
	}; \
	struct FSMCreateWidgetHelper_eventOverrideProperty_Parms \
	{ \
		UWidget* Widget; \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMCreateWidgetHelper(); \
	friend struct Z_Construct_UClass_UFSMCreateWidgetHelper_Statics; \
public: \
	DECLARE_CLASS(UFSMCreateWidgetHelper, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCreateWidgetHelper) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMCreateWidgetHelper*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUFSMCreateWidgetHelper(); \
	friend struct Z_Construct_UClass_UFSMCreateWidgetHelper_Statics; \
public: \
	DECLARE_CLASS(UFSMCreateWidgetHelper, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCreateWidgetHelper) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMCreateWidgetHelper*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCreateWidgetHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCreateWidgetHelper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCreateWidgetHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCreateWidgetHelper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCreateWidgetHelper(UFSMCreateWidgetHelper&&); \
	NO_API UFSMCreateWidgetHelper(const UFSMCreateWidgetHelper&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCreateWidgetHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCreateWidgetHelper(UFSMCreateWidgetHelper&&); \
	NO_API UFSMCreateWidgetHelper(const UFSMCreateWidgetHelper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCreateWidgetHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCreateWidgetHelper); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCreateWidgetHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WidgetClass() { return STRUCT_OFFSET(UFSMCreateWidgetHelper, WidgetClass); } \
	FORCEINLINE static uint32 __PPO__WidgetTag() { return STRUCT_OFFSET(UFSMCreateWidgetHelper, WidgetTag); } \
	FORCEINLINE static uint32 __PPO__WidgetLifetime() { return STRUCT_OFFSET(UFSMCreateWidgetHelper, WidgetLifetime); } \
	FORCEINLINE static uint32 __PPO__WidgetLayer() { return STRUCT_OFFSET(UFSMCreateWidgetHelper, WidgetLayer); } \
	FORCEINLINE static uint32 __PPO__Visibility() { return STRUCT_OFFSET(UFSMCreateWidgetHelper, Visibility); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_21_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMCreateWidgetHelper>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateWidgetHelper_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

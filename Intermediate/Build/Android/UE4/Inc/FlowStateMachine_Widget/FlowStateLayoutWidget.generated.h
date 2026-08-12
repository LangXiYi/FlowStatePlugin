// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
class UWidget;
class UGameplayTagSlot;
#ifdef FLOWSTATEMACHINE_WIDGET_FlowStateLayoutWidget_generated_h
#error "FlowStateLayoutWidget.generated.h already included, missing '#pragma once' in FlowStateLayoutWidget.h"
#endif
#define FLOWSTATEMACHINE_WIDGET_FlowStateLayoutWidget_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAddChildTo); \
	DECLARE_FUNCTION(execCheckSlot); \
	DECLARE_FUNCTION(execFindSlot); \
	DECLARE_FUNCTION(execClearChildSlots);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAddChildTo); \
	DECLARE_FUNCTION(execCheckSlot); \
	DECLARE_FUNCTION(execFindSlot); \
	DECLARE_FUNCTION(execClearChildSlots);


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFlowStateLayoutWidget(); \
	friend struct Z_Construct_UClass_UFlowStateLayoutWidget_Statics; \
public: \
	DECLARE_CLASS(UFlowStateLayoutWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine_Widget"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateLayoutWidget)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUFlowStateLayoutWidget(); \
	friend struct Z_Construct_UClass_UFlowStateLayoutWidget_Statics; \
public: \
	DECLARE_CLASS(UFlowStateLayoutWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine_Widget"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateLayoutWidget)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateLayoutWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateLayoutWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateLayoutWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateLayoutWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateLayoutWidget(UFlowStateLayoutWidget&&); \
	NO_API UFlowStateLayoutWidget(const UFlowStateLayoutWidget&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateLayoutWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateLayoutWidget(UFlowStateLayoutWidget&&); \
	NO_API UFlowStateLayoutWidget(const UFlowStateLayoutWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateLayoutWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateLayoutWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateLayoutWidget)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TagSlots() { return STRUCT_OFFSET(UFlowStateLayoutWidget, TagSlots); } \
	FORCEINLINE static uint32 __PPO__RootWidget() { return STRUCT_OFFSET(UFlowStateLayoutWidget, RootWidget); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_17_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_WIDGET_API UClass* StaticClass<class UFlowStateLayoutWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Widget_Public_Widgets_FlowStateLayoutWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

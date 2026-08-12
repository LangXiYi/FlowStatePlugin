// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLOWSTATEMACHINE_FlowStateCollectInterface_generated_h
#error "FlowStateCollectInterface.generated.h already included, missing '#pragma once' in FlowStateCollectInterface.h"
#endif
#define FLOWSTATEMACHINE_FlowStateCollectInterface_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_EVENT_PARMS \
	struct FlowStateCollectInterface_eventNativeGetStatePinInfos_Parms \
	{ \
		TArray<FName> Array; \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateCollectInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateCollectInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateCollectInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateCollectInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateCollectInterface(UFlowStateCollectInterface&&); \
	NO_API UFlowStateCollectInterface(const UFlowStateCollectInterface&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFlowStateCollectInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFlowStateCollectInterface(UFlowStateCollectInterface&&); \
	NO_API UFlowStateCollectInterface(const UFlowStateCollectInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFlowStateCollectInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFlowStateCollectInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFlowStateCollectInterface)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUFlowStateCollectInterface(); \
	friend struct Z_Construct_UClass_UFlowStateCollectInterface_Statics; \
public: \
	DECLARE_CLASS(UFlowStateCollectInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFlowStateCollectInterface)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_GENERATED_UINTERFACE_BODY() \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_GENERATED_UINTERFACE_BODY() \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IFlowStateCollectInterface() {} \
public: \
	typedef UFlowStateCollectInterface UClassType; \
	typedef IFlowStateCollectInterface ThisClass; \
	static void Execute_NativeGetStatePinInfos(const UObject* O, TArray<FName>& Array); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IFlowStateCollectInterface() {} \
public: \
	typedef UFlowStateCollectInterface UClassType; \
	typedef IFlowStateCollectInterface ThisClass; \
	static void Execute_NativeGetStatePinInfos(const UObject* O, TArray<FName>& Array); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_10_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFlowStateCollectInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_FlowStateCollectInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

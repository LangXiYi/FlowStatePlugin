// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef FLOWSTATEMACHINE_FSMCreateActorHelper_generated_h
#error "FSMCreateActorHelper.generated.h already included, missing '#pragma once' in FSMCreateActorHelper.h"
#endif
#define FLOWSTATEMACHINE_FSMCreateActorHelper_generated_h

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_EVENT_PARMS \
	struct FSMCreateActorHelper_eventNativeGetCreateClass_Parms \
	{ \
		TSubclassOf<AActor>  ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		FSMCreateActorHelper_eventNativeGetCreateClass_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct FSMCreateActorHelper_eventNativeInitializeActor_Parms \
	{ \
		AActor* Target; \
	}; \
	struct FSMCreateActorHelper_eventNativeOverrideProperty_Parms \
	{ \
		AActor* ResultActor; \
	};


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_CALLBACK_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFSMCreateActorHelper(); \
	friend struct Z_Construct_UClass_UFSMCreateActorHelper_Statics; \
public: \
	DECLARE_CLASS(UFSMCreateActorHelper, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCreateActorHelper) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMCreateActorHelper*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUFSMCreateActorHelper(); \
	friend struct Z_Construct_UClass_UFSMCreateActorHelper_Statics; \
public: \
	DECLARE_CLASS(UFSMCreateActorHelper, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UFSMCreateActorHelper) \
	virtual UObject* _getUObject() const override { return const_cast<UFSMCreateActorHelper*>(this); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCreateActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCreateActorHelper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCreateActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCreateActorHelper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCreateActorHelper(UFSMCreateActorHelper&&); \
	NO_API UFSMCreateActorHelper(const UFSMCreateActorHelper&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFSMCreateActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFSMCreateActorHelper(UFSMCreateActorHelper&&); \
	NO_API UFSMCreateActorHelper(const UFSMCreateActorHelper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFSMCreateActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFSMCreateActorHelper); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFSMCreateActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__UniqueName() { return STRUCT_OFFSET(UFSMCreateActorHelper, UniqueName); } \
	FORCEINLINE static uint32 __PPO__Lifetime() { return STRUCT_OFFSET(UFSMCreateActorHelper, Lifetime); } \
	FORCEINLINE static uint32 __PPO__Offset() { return STRUCT_OFFSET(UFSMCreateActorHelper, Offset); } \
	FORCEINLINE static uint32 __PPO__Rotator() { return STRUCT_OFFSET(UFSMCreateActorHelper, Rotator); } \
	FORCEINLINE static uint32 __PPO__Scale() { return STRUCT_OFFSET(UFSMCreateActorHelper, Scale); } \
	FORCEINLINE static uint32 __PPO__TransformMode() { return STRUCT_OFFSET(UFSMCreateActorHelper, TransformMode); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_21_PROLOG \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_EVENT_PARMS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_CALLBACK_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UFSMCreateActorHelper>();

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCreateSkeletalActorHelper(); \
	friend struct Z_Construct_UClass_UCreateSkeletalActorHelper_Statics; \
public: \
	DECLARE_CLASS(UCreateSkeletalActorHelper, UFSMCreateActorHelper, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UCreateSkeletalActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_INCLASS \
private: \
	static void StaticRegisterNativesUCreateSkeletalActorHelper(); \
	friend struct Z_Construct_UClass_UCreateSkeletalActorHelper_Statics; \
public: \
	DECLARE_CLASS(UCreateSkeletalActorHelper, UFSMCreateActorHelper, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UCreateSkeletalActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCreateSkeletalActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateSkeletalActorHelper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCreateSkeletalActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateSkeletalActorHelper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCreateSkeletalActorHelper(UCreateSkeletalActorHelper&&); \
	NO_API UCreateSkeletalActorHelper(const UCreateSkeletalActorHelper&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCreateSkeletalActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCreateSkeletalActorHelper(UCreateSkeletalActorHelper&&); \
	NO_API UCreateSkeletalActorHelper(const UCreateSkeletalActorHelper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCreateSkeletalActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateSkeletalActorHelper); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateSkeletalActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, Mesh); } \
	FORCEINLINE static uint32 __PPO__CollisionProfileName() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, CollisionProfileName); } \
	FORCEINLINE static uint32 __PPO__AnimationAsset() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, AnimationAsset); } \
	FORCEINLINE static uint32 __PPO__bIsAutoPlay() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, bIsAutoPlay); } \
	FORCEINLINE static uint32 __PPO__bIsLoop() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, bIsLoop); } \
	FORCEINLINE static uint32 __PPO__InitAnimPos() { return STRUCT_OFFSET(UCreateSkeletalActorHelper, InitAnimPos); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_82_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_85_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UCreateSkeletalActorHelper>();

#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_SPARSE_DATA
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_RPC_WRAPPERS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_RPC_WRAPPERS_NO_PURE_DECLS
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCreateStaticActorHelper(); \
	friend struct Z_Construct_UClass_UCreateStaticActorHelper_Statics; \
public: \
	DECLARE_CLASS(UCreateStaticActorHelper, UFSMCreateActorHelper, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UCreateStaticActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_INCLASS \
private: \
	static void StaticRegisterNativesUCreateStaticActorHelper(); \
	friend struct Z_Construct_UClass_UCreateStaticActorHelper_Statics; \
public: \
	DECLARE_CLASS(UCreateStaticActorHelper, UFSMCreateActorHelper, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FlowStateMachine"), NO_API) \
	DECLARE_SERIALIZER(UCreateStaticActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCreateStaticActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateStaticActorHelper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCreateStaticActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateStaticActorHelper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCreateStaticActorHelper(UCreateStaticActorHelper&&); \
	NO_API UCreateStaticActorHelper(const UCreateStaticActorHelper&); \
public:


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCreateStaticActorHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCreateStaticActorHelper(UCreateStaticActorHelper&&); \
	NO_API UCreateStaticActorHelper(const UCreateStaticActorHelper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCreateStaticActorHelper); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCreateStaticActorHelper); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCreateStaticActorHelper)


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(UCreateStaticActorHelper, Mesh); } \
	FORCEINLINE static uint32 __PPO__CollisionProfileName() { return STRUCT_OFFSET(UCreateStaticActorHelper, CollisionProfileName); }


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_115_PROLOG
#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_RPC_WRAPPERS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_INCLASS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_PRIVATE_PROPERTY_OFFSET \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_SPARSE_DATA \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_RPC_WRAPPERS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_INCLASS_NO_PURE_DECLS \
	IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h_118_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FLOWSTATEMACHINE_API UClass* StaticClass<class UCreateStaticActorHelper>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IPM_Plugins_FlowStateMachine_Source_FlowStateMachine_Public_Utility_FSMCreateActorHelper_h


#define FOREACH_ENUM_ECREATEACTORACTIONMODE(op) \
	op(ECreateActorActionMode::World) \
	op(ECreateActorActionMode::Relative) 

enum class ECreateActorActionMode : uint8;
template<> FLOWSTATEMACHINE_API UEnum* StaticEnum<ECreateActorActionMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

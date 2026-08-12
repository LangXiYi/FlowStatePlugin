// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/SM/FlowStateBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateBase() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateBase_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateBase();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNode_State();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFlowStateBase::execGetDeltaTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetDeltaTime();
		P_NATIVE_END;
	}
	static FName NAME_UFlowStateBase_NativeOnEnter = FName(TEXT("NativeOnEnter"));
	void UFlowStateBase::NativeOnEnter()
	{
		ProcessEvent(FindFunctionChecked(NAME_UFlowStateBase_NativeOnEnter),NULL);
	}
	static FName NAME_UFlowStateBase_NativeOnExit = FName(TEXT("NativeOnExit"));
	void UFlowStateBase::NativeOnExit()
	{
		ProcessEvent(FindFunctionChecked(NAME_UFlowStateBase_NativeOnExit),NULL);
	}
	static FName NAME_UFlowStateBase_NativeOnInitialize = FName(TEXT("NativeOnInitialize"));
	void UFlowStateBase::NativeOnInitialize(UFlowStateContext* InContext)
	{
		FlowStateBase_eventNativeOnInitialize_Parms Parms;
		Parms.InContext=InContext;
		ProcessEvent(FindFunctionChecked(NAME_UFlowStateBase_NativeOnInitialize),&Parms);
	}
	static FName NAME_UFlowStateBase_OnTick = FName(TEXT("OnTick"));
	void UFlowStateBase::OnTick(float DeltaTime)
	{
		FlowStateBase_eventOnTick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_UFlowStateBase_OnTick),&Parms);
	}
	void UFlowStateBase::StaticRegisterNativesUFlowStateBase()
	{
		UClass* Class = UFlowStateBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDeltaTime", &UFlowStateBase::execGetDeltaTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics
	{
		struct FlowStateBase_eventGetDeltaTime_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateBase_eventGetDeltaTime_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Flow State" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateBase, nullptr, "GetDeltaTime", nullptr, nullptr, sizeof(FlowStateBase_eventGetDeltaTime_Parms), Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateBase_GetDeltaTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateBase_GetDeltaTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowState" },
		{ "Comment", "/** \xe8\xbf\x9b\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6 */" },
		{ "DisplayName", "OnEnter" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
		{ "ToolTip", "\xe8\xbf\x9b\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateBase, nullptr, "NativeOnEnter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateBase_NativeOnEnter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateBase_NativeOnEnter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowState" },
		{ "Comment", "/** \xe9\x80\x80\xe5\x87\xba\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6 */" },
		{ "DisplayName", "OnExit" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
		{ "ToolTip", "\xe9\x80\x80\xe5\x87\xba\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateBase, nullptr, "NativeOnExit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateBase_NativeOnExit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateBase_NativeOnExit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InContext;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::NewProp_InContext = { "InContext", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateBase_eventNativeOnInitialize_Parms, InContext), Z_Construct_UClass_UFlowStateContext_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::NewProp_InContext,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowState" },
		{ "Comment", "/** \xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6 */" },
		{ "DisplayName", "OnIntialize" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
		{ "ToolTip", "\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe4\xba\x8b\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateBase, nullptr, "NativeOnInitialize", nullptr, nullptr, sizeof(FlowStateBase_eventNativeOnInitialize_Parms), Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateBase_OnTick_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateBase_eventOnTick_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowState" },
		{ "Comment", "/** \xe6\xaf\x8f\xe5\xb8\xa7\xe6\x89\xa7\xe8\xa1\x8c\xe4\xba\x8b\xe4\xbb\xb6 */" },
		{ "DisplayName", "Tick" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
		{ "ToolTip", "\xe6\xaf\x8f\xe5\xb8\xa7\xe6\x89\xa7\xe8\xa1\x8c\xe4\xba\x8b\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateBase, nullptr, "OnTick", nullptr, nullptr, sizeof(FlowStateBase_eventOnTick_Parms), Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateBase_OnTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateBase_OnTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateBase_NoRegister()
	{
		return UFlowStateBase::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMRuntimeNode_State,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateBase_GetDeltaTime, "GetDeltaTime" }, // 4015285282
		{ &Z_Construct_UFunction_UFlowStateBase_NativeOnEnter, "NativeOnEnter" }, // 2560380533
		{ &Z_Construct_UFunction_UFlowStateBase_NativeOnExit, "NativeOnExit" }, // 3867872885
		{ &Z_Construct_UFunction_UFlowStateBase_NativeOnInitialize, "NativeOnInitialize" }, // 2105249749
		{ &Z_Construct_UFunction_UFlowStateBase_OnTick, "OnTick" }, // 506997471
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \xe5\x8f\xaf\xe4\xbb\xa5\xe7\x94\xb1\xe8\x93\x9d\xe5\x9b\xbe\xe7\xbb\xa7\xe6\x89\xbf\xe5\xb9\xb6\xe5\xae\x9e\xe7\x8e\xb0\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe5\x9f\xba\xe7\xb1\xbb\n */" },
		{ "IncludePath", "SM/FlowStateBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SM/FlowStateBase.h" },
		{ "ToolTip", "\xe5\x8f\xaf\xe4\xbb\xa5\xe7\x94\xb1\xe8\x93\x9d\xe5\x9b\xbe\xe7\xbb\xa7\xe6\x89\xbf\xe5\xb9\xb6\xe5\xae\x9e\xe7\x8e\xb0\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe5\x9f\xba\xe7\xb1\xbb" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateBase_Statics::ClassParams = {
		&UFlowStateBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateBase, 148618307);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFlowStateBase>()
	{
		return UFlowStateBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateBase(Z_Construct_UClass_UFlowStateBase, &UFlowStateBase::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFlowStateBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

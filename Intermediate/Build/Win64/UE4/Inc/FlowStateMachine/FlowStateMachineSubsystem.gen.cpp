// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/System/FlowStateMachineSubsystem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateMachineSubsystem() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateMachineSubsystem_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateMachineSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateMachine_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFlowStateMachineSubsystem::execStopFlowStateMachine)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopFlowStateMachine();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateMachineSubsystem::execRunFlowStateMachine)
	{
		P_GET_OBJECT(UFlowStateMachine,Z_Param_StateMachine);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RunFlowStateMachine(Z_Param_StateMachine);
		P_NATIVE_END;
	}
	void UFlowStateMachineSubsystem::StaticRegisterNativesUFlowStateMachineSubsystem()
	{
		UClass* Class = UFlowStateMachineSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RunFlowStateMachine", &UFlowStateMachineSubsystem::execRunFlowStateMachine },
			{ "StopFlowStateMachine", &UFlowStateMachineSubsystem::execStopFlowStateMachine },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics
	{
		struct FlowStateMachineSubsystem_eventRunFlowStateMachine_Parms
		{
			UFlowStateMachine* StateMachine;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateMachine;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_StateMachine = { "StateMachine", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateMachineSubsystem_eventRunFlowStateMachine_Parms, StateMachine), Z_Construct_UClass_UFlowStateMachine_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowStateMachineSubsystem_eventRunFlowStateMachine_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowStateMachineSubsystem_eventRunFlowStateMachine_Parms), &Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_StateMachine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateMachineSubsystem" },
		{ "Comment", "/**\n\x09 * \xe5\x8f\xaa\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\x80\xe6\xac\xa1\xef\xbc\x8c\xe6\x89\xa7\xe8\xa1\x8c\xe5\xae\x8c\xe6\x88\x90\xe5\x90\x8e\xe7\xbb\x93\xe6\x9d\x9f\xef\xbc\x9f\n\x09 * \xe4\xbb\x80\xe4\xb9\x88\xe6\x97\xb6\xe5\x80\x99\xe7\xbb\x93\xe6\x9d\x9f\xef\xbc\x8c\xe5\x9c\xa8\xe6\x89\xa7\xe8\xa1\x8c\xe5\x88\xb0\xe6\x97\xa0\xe6\xb3\x95\xe7\xbb\xa7\xe7\xbb\xad\xe5\x90\x91\xe4\xb8\x8b\xe6\x89\xa7\xe8\xa1\x8c\xe6\x97\xb6\xef\xbc\x8c\xe8\x87\xaa\xe5\x8a\xa8\xe7\xbb\x93\xe6\x9d\x9f\n\x09 * @param StateMachine\n\x09 * @param ExecuteMode \xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f \n\x09 * @return \n\x09 */" },
		{ "ModuleRelativePath", "Public/System/FlowStateMachineSubsystem.h" },
		{ "ToolTip", "\xe5\x8f\xaa\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\x80\xe6\xac\xa1\xef\xbc\x8c\xe6\x89\xa7\xe8\xa1\x8c\xe5\xae\x8c\xe6\x88\x90\xe5\x90\x8e\xe7\xbb\x93\xe6\x9d\x9f\xef\xbc\x9f\n\xe4\xbb\x80\xe4\xb9\x88\xe6\x97\xb6\xe5\x80\x99\xe7\xbb\x93\xe6\x9d\x9f\xef\xbc\x8c\xe5\x9c\xa8\xe6\x89\xa7\xe8\xa1\x8c\xe5\x88\xb0\xe6\x97\xa0\xe6\xb3\x95\xe7\xbb\xa7\xe7\xbb\xad\xe5\x90\x91\xe4\xb8\x8b\xe6\x89\xa7\xe8\xa1\x8c\xe6\x97\xb6\xef\xbc\x8c\xe8\x87\xaa\xe5\x8a\xa8\xe7\xbb\x93\xe6\x9d\x9f\n@param StateMachine\n@param ExecuteMode \xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\n@return" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateMachineSubsystem, nullptr, "RunFlowStateMachine", nullptr, nullptr, sizeof(FlowStateMachineSubsystem_eventRunFlowStateMachine_Parms), Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateMachineSubsystem" },
		{ "ModuleRelativePath", "Public/System/FlowStateMachineSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateMachineSubsystem, nullptr, "StopFlowStateMachine", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateMachineSubsystem_NoRegister()
	{
		return UFlowStateMachineSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateMachineSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunningStateContext_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RunningStateContext;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateMachineSubsystem_RunFlowStateMachine, "RunFlowStateMachine" }, // 1985502102
		{ &Z_Construct_UFunction_UFlowStateMachineSubsystem_StopFlowStateMachine, "StopFlowStateMachine" }, // 2009851145
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "System/FlowStateMachineSubsystem.h" },
		{ "ModuleRelativePath", "Public/System/FlowStateMachineSubsystem.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::NewProp_RunningStateContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/System/FlowStateMachineSubsystem.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::NewProp_RunningStateContext = { "RunningStateContext", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateMachineSubsystem, RunningStateContext), Z_Construct_UClass_UFlowStateContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::NewProp_RunningStateContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::NewProp_RunningStateContext_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::NewProp_RunningStateContext,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateMachineSubsystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::ClassParams = {
		&UFlowStateMachineSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateMachineSubsystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateMachineSubsystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateMachineSubsystem, 3772800468);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFlowStateMachineSubsystem>()
	{
		return UFlowStateMachineSubsystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateMachineSubsystem(Z_Construct_UClass_UFlowStateMachineSubsystem, &UFlowStateMachineSubsystem::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFlowStateMachineSubsystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateMachineSubsystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/RuntimeNode/FSMRuntimeNodeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMRuntimeNodeBase() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNodeBase();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateMachine_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateCollectInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFSMRuntimeNodeBase::execGetStateContext)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFlowStateContext**)Z_Param__Result=P_THIS->GetStateContext();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMRuntimeNodeBase::execSwitchToByName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SwitchToByName(Z_Param_Name);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMRuntimeNodeBase::execTrySwitchTo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TrySwitchTo(Z_Param_Index);
		P_NATIVE_END;
	}
	void UFSMRuntimeNodeBase::StaticRegisterNativesUFSMRuntimeNodeBase()
	{
		UClass* Class = UFSMRuntimeNodeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetStateContext", &UFSMRuntimeNodeBase::execGetStateContext },
			{ "SwitchToByName", &UFSMRuntimeNodeBase::execSwitchToByName },
			{ "TrySwitchTo", &UFSMRuntimeNodeBase::execTrySwitchTo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics
	{
		struct FSMRuntimeNodeBase_eventGetStateContext_Parms
		{
			UFlowStateContext* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMRuntimeNodeBase_eventGetStateContext_Parms, ReturnValue), Z_Construct_UClass_UFlowStateContext_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMRuntimeNodeBase, nullptr, "GetStateContext", nullptr, nullptr, sizeof(FSMRuntimeNodeBase_eventGetStateContext_Parms), Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics
	{
		struct FSMRuntimeNodeBase_eventSwitchToByName_Parms
		{
			FName Name;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMRuntimeNodeBase_eventSwitchToByName_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FSMRuntimeNodeBase_eventSwitchToByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMRuntimeNodeBase_eventSwitchToByName_Parms), &Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateMachine" },
		{ "Comment", "/** \xe5\xb0\x9d\xe8\xaf\x95\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe5\x85\xb6\xe4\xbb\x96\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe5\xb0\x9d\xe8\xaf\x95\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe5\x85\xb6\xe4\xbb\x96\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMRuntimeNodeBase, nullptr, "SwitchToByName", nullptr, nullptr, sizeof(FSMRuntimeNodeBase_eventSwitchToByName_Parms), Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics
	{
		struct FSMRuntimeNodeBase_eventTrySwitchTo_Parms
		{
			int32 Index;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMRuntimeNodeBase_eventTrySwitchTo_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FSMRuntimeNodeBase_eventTrySwitchTo_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMRuntimeNodeBase_eventTrySwitchTo_Parms), &Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateMachine" },
		{ "Comment", "/** \xe5\xb0\x9d\xe8\xaf\x95\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe5\x85\xb6\xe4\xbb\x96\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe5\xb0\x9d\xe8\xaf\x95\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe5\x85\xb6\xe4\xbb\x96\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMRuntimeNodeBase, nullptr, "TrySwitchTo", nullptr, nullptr, sizeof(FSMRuntimeNodeBase_eventTrySwitchTo_Parms), Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister()
	{
		return UFSMRuntimeNodeBase::StaticClass();
	}
	struct Z_Construct_UClass_UFSMRuntimeNodeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SubNodes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsRootNode_MetaData[];
#endif
		static void NewProp_bIsRootNode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsRootNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateContext_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateContext;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NodeName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AllParentNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AllParentNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AllParentNodes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FSMAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FSMAsset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFSMRuntimeNodeBase_GetStateContext, "GetStateContext" }, // 779709677
		{ &Z_Construct_UFunction_UFSMRuntimeNodeBase_SwitchToByName, "SwitchToByName" }, // 2364914276
		{ &Z_Construct_UFunction_UFSMRuntimeNodeBase_TrySwitchTo, "TrySwitchTo" }, // 2334383722
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes_Inner = { "SubNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes_MetaData[] = {
		{ "Comment", "/** \xe6\xac\xa1\xe8\xa6\x81\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe6\xac\xa1\xe8\xa6\x81\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes = { "SubNodes", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMRuntimeNodeBase, SubNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode_MetaData[] = {
		{ "Comment", "// \xe6\x98\xaf\xe5\x90\xa6\xe4\xb8\xba\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe6\x98\xaf\xe5\x90\xa6\xe4\xb8\xba\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	void Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode_SetBit(void* Obj)
	{
		((UFSMRuntimeNodeBase*)Obj)->bIsRootNode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode = { "bIsRootNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UFSMRuntimeNodeBase), &Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode_SetBit, METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_StateContext_MetaData[] = {
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x88\x9b\xe5\xbb\xba\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe7\xae\xa1\xe7\x90\x86\xe5\xae\x9e\xe4\xbe\x8b */" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x88\x9b\xe5\xbb\xba\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe7\xae\xa1\xe7\x90\x86\xe5\xae\x9e\xe4\xbe\x8b" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_StateContext = { "StateContext", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMRuntimeNodeBase, StateContext), Z_Construct_UClass_UFlowStateContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_StateContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_StateContext_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_NodeName_MetaData[] = {
		{ "Category", "FSMRuntimeNodeBase" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMRuntimeNodeBase, NodeName), METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_NodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_NodeName_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes_Inner = { "AllParentNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes_MetaData[] = {
		{ "Comment", "/** \xe6\x89\x80\xe6\x9c\x89\xe7\x88\xb6\xe7\xba\xa7\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe6\x89\x80\xe6\x9c\x89\xe7\x88\xb6\xe7\xba\xa7\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes = { "AllParentNodes", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMRuntimeNodeBase, AllParentNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_FSMAsset_MetaData[] = {
		{ "Comment", "// \xe9\x9d\x99\xe6\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x8c\xe5\x8f\xaf\xe4\xbb\xa5\xe9\x80\x9a\xe8\xbf\x87\xe4\xbb\x96\xe8\xae\xbf\xe9\x97\xae\xe5\x88\xb0\xe6\x88\x91\xe4\xbb\xac\xe7\x9a\x84\xe9\xbb\x91\xe6\x9d\xbf\xe8\xb5\x84\xe4\xba\xa7\n" },
		{ "ModuleRelativePath", "Public/RuntimeNode/FSMRuntimeNodeBase.h" },
		{ "ToolTip", "\xe9\x9d\x99\xe6\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x8c\xe5\x8f\xaf\xe4\xbb\xa5\xe9\x80\x9a\xe8\xbf\x87\xe4\xbb\x96\xe8\xae\xbf\xe9\x97\xae\xe5\x88\xb0\xe6\x88\x91\xe4\xbb\xac\xe7\x9a\x84\xe9\xbb\x91\xe6\x9d\xbf\xe8\xb5\x84\xe4\xba\xa7" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_FSMAsset = { "FSMAsset", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMRuntimeNodeBase, FSMAsset), Z_Construct_UClass_UFlowStateMachine_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_FSMAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_FSMAsset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_SubNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_bIsRootNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_StateContext,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_NodeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_AllParentNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::NewProp_FSMAsset,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFlowStateCollectInterface_NoRegister, (int32)VTABLE_OFFSET(UFSMRuntimeNodeBase, IFlowStateCollectInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMRuntimeNodeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::ClassParams = {
		&UFSMRuntimeNodeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMRuntimeNodeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMRuntimeNodeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMRuntimeNodeBase, 109691346);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMRuntimeNodeBase>()
	{
		return UFSMRuntimeNodeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMRuntimeNodeBase(Z_Construct_UClass_UFSMRuntimeNodeBase, &UFSMRuntimeNodeBase::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMRuntimeNodeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMRuntimeNodeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

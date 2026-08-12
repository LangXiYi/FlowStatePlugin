// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/SM/FlowStateContext.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateContext() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataManager_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNode_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UEnum* Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateMachine_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFlowStateContext::execGetScatteredNodeIDs)
	{
		P_GET_TARRAY_REF(FGuid,Z_Param_Out_OutData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetScatteredNodeIDs(Z_Param_Out_OutData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execGetCommonDataManager)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFSMCommonDataManager**)Z_Param__Result=P_THIS->GetCommonDataManager();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execGetCurrentState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFSMRuntimeNode**)Z_Param__Result=P_THIS->GetCurrentState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execGetLayoutManager)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFlowStateWidgetLayerManager**)Z_Param__Result=P_THIS->GetLayoutManager();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execGetLayoutWidget)
	{
		P_GET_ENUM(EFlowStateWidgetLayer,Z_Param_Layer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFlowStateLayoutWidget**)Z_Param__Result=P_THIS->GetLayoutWidget(EFlowStateWidgetLayer(Z_Param_Layer));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execKillAllCache)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->KillAllCache();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execKillActorCache)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->KillActorCache();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateContext::execGotoScatteredNode)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_NodeName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GotoScatteredNode(Z_Param_NodeName);
		P_NATIVE_END;
	}
	void UFlowStateContext::StaticRegisterNativesUFlowStateContext()
	{
		UClass* Class = UFlowStateContext::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCommonDataManager", &UFlowStateContext::execGetCommonDataManager },
			{ "GetCurrentState", &UFlowStateContext::execGetCurrentState },
			{ "GetLayoutManager", &UFlowStateContext::execGetLayoutManager },
			{ "GetLayoutWidget", &UFlowStateContext::execGetLayoutWidget },
			{ "GetScatteredNodeIDs", &UFlowStateContext::execGetScatteredNodeIDs },
			{ "GotoScatteredNode", &UFlowStateContext::execGotoScatteredNode },
			{ "KillActorCache", &UFlowStateContext::execKillActorCache },
			{ "KillAllCache", &UFlowStateContext::execKillAllCache },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics
	{
		struct FlowStateContext_eventGetCommonDataManager_Parms
		{
			UFSMCommonDataManager* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetCommonDataManager_Parms, ReturnValue), Z_Construct_UClass_UFSMCommonDataManager_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateContext" },
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xac\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xac\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GetCommonDataManager", nullptr, nullptr, sizeof(FlowStateContext_eventGetCommonDataManager_Parms), Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics
	{
		struct FlowStateContext_eventGetCurrentState_Parms
		{
			UFSMRuntimeNode* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetCurrentState_Parms, ReturnValue), Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateContext" },
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe5\xaf\xb9\xe8\xb1\xa1 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe5\xaf\xb9\xe8\xb1\xa1" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GetCurrentState", nullptr, nullptr, sizeof(FlowStateContext_eventGetCurrentState_Parms), Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GetCurrentState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GetCurrentState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics
	{
		struct FlowStateContext_eventGetLayoutManager_Parms
		{
			UFlowStateWidgetLayerManager* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetLayoutManager_Parms, ReturnValue), Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GetLayoutManager", nullptr, nullptr, sizeof(FlowStateContext_eventGetLayoutManager_Parms), Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GetLayoutManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GetLayoutManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics
	{
		struct FlowStateContext_eventGetLayoutWidget_Parms
		{
			EFlowStateWidgetLayer Layer;
			UFlowStateLayoutWidget* ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Layer_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Layer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_Layer_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_Layer = { "Layer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetLayoutWidget_Parms, Layer), Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetLayoutWidget_Parms, ReturnValue), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_Layer_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_Layer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xb8\x83\xe5\xb1\x80\xe6\x8e\xa7\xe4\xbb\xb6 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xb8\x83\xe5\xb1\x80\xe6\x8e\xa7\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GetLayoutWidget", nullptr, nullptr, sizeof(FlowStateContext_eventGetLayoutWidget_Parms), Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics
	{
		struct FlowStateContext_eventGetScatteredNodeIDs_Parms
		{
			TArray<FGuid> OutData;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OutData_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::NewProp_OutData_Inner = { "OutData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::NewProp_OutData = { "OutData", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGetScatteredNodeIDs_Parms, OutData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::NewProp_OutData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::NewProp_OutData,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateContext" },
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x89\x80\xe6\x9c\x89\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9\xe7\x9a\x84\xe5\x94\xaf\xe4\xb8\x80ID */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x89\x80\xe6\x9c\x89\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9\xe7\x9a\x84\xe5\x94\xaf\xe4\xb8\x80ID" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GetScatteredNodeIDs", nullptr, nullptr, sizeof(FlowStateContext_eventGetScatteredNodeIDs_Parms), Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics
	{
		struct FlowStateContext_eventGotoScatteredNode_Parms
		{
			FString NodeName;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NodeName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_NodeName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateContext_eventGotoScatteredNode_Parms, NodeName), METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_NodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_NodeName_MetaData)) };
	void Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowStateContext_eventGotoScatteredNode_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowStateContext_eventGotoScatteredNode_Parms), &Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_NodeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "GotoScatteredNode", nullptr, nullptr, sizeof(FlowStateContext_eventGotoScatteredNode_Parms), Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \xe6\xb8\x85\xe7\xa9\xba\xe8\xa7\x92\xe8\x89\xb2\xe7\xbc\x93\xe5\xad\x98 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe6\xb8\x85\xe7\xa9\xba\xe8\xa7\x92\xe8\x89\xb2\xe7\xbc\x93\xe5\xad\x98" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "KillActorCache", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_KillActorCache()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_KillActorCache_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \xe6\xb8\x85\xe7\xa9\xba\xe7\xbc\x93\xe5\xad\x98 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe6\xb8\x85\xe7\xa9\xba\xe7\xbc\x93\xe5\xad\x98" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateContext, nullptr, "KillAllCache", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateContext_KillAllCache()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateContext_KillAllCache_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateContext_NoRegister()
	{
		return UFlowStateContext::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateContext_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurState;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstanceStack_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InstanceStack_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InstanceStack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootState;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ScatteredNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScatteredNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ScatteredNodes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CommonDataManager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CommonDataManager;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateMachine_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateMachine;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WidgetLayers_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WidgetLayers;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CacheTemplateObjects_ValueProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CacheTemplateObjects_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CacheTemplateObjects_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_CacheTemplateObjects;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ScatteredNodeMapping_ValueProp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScatteredNodeMapping_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScatteredNodeMapping_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ScatteredNodeMapping;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateContext_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateContext_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateContext_GetCommonDataManager, "GetCommonDataManager" }, // 707600348
		{ &Z_Construct_UFunction_UFlowStateContext_GetCurrentState, "GetCurrentState" }, // 3784108214
		{ &Z_Construct_UFunction_UFlowStateContext_GetLayoutManager, "GetLayoutManager" }, // 1107057862
		{ &Z_Construct_UFunction_UFlowStateContext_GetLayoutWidget, "GetLayoutWidget" }, // 1929792981
		{ &Z_Construct_UFunction_UFlowStateContext_GetScatteredNodeIDs, "GetScatteredNodeIDs" }, // 2866171682
		{ &Z_Construct_UFunction_UFlowStateContext_GotoScatteredNode, "GotoScatteredNode" }, // 4111532267
		{ &Z_Construct_UFunction_UFlowStateContext_KillActorCache, "KillActorCache" }, // 2456143567
		{ &Z_Construct_UFunction_UFlowStateContext_KillAllCache, "KillAllCache" }, // 699322558
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \xe5\x9b\xa0\xe4\xb8\xba\xe5\xad\x98\xe5\x9c\xa8\xe4\xb8\xa4\xe7\xa7\x8d\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8cState\xe4\xbb\xa5\xe5\x8f\x8a""Composites\xef\xbc\x8c\xe6\x89\x80\xe4\xbb\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe4\xbb\x96\xe4\xbb\xac\xe7\x9a\x84\xe5\x85\xac\xe7\x94\xa8\xe5\x9f\xba\xe7\xb1\xbb RuntimeNode\n * TODO::\xe4\xb8\x8d\xe8\xa6\x81\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe8\xbf\x99\xe4\xba\x9b\xe5\xae\x9e\xe4\xbe\x8b\xe5\x8c\x96\xe4\xba\x86\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x81\xef\xbc\x81\xef\xbc\x81\xe8\xbf\x99\xe4\xbc\x9a\xe5\xaf\xbc\xe8\x87\xb4\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa2\xab\xe4\xbf\xae\xe6\x94\xb9\n * \xe5\x88\x9b\xe5\xbb\xba\xe4\xb8\x80\xe4\xb8\xaa\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xef\xbc\x8c\xe7\xae\xa1\xe7\x90\x86\xe6\x89\x80\xe6\x9c\x89\xe5\x8a\xa0\xe8\xbd\xbd\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\n *\x09\x09\xe5\x9c\xa8\xe5\x8a\xa0\xe8\xbd\xbd\xe6\x97\xb6\xef\xbc\x8c\xe4\xbc\x9a\xe6\xb7\xb1\xe5\xba\xa6\xe6\x8b\xb7\xe8\xb4\x9d\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe4\xb8\xad\xe7\x9a\x84\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\xb0\x86\xe5\x85\xb6\xe5\x8a\xa0\xe5\x85\xa5\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe5\xa4\x8d\xe5\x88\xb6\n */" },
		{ "IncludePath", "SM/FlowStateContext.h" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "\xe5\x9b\xa0\xe4\xb8\xba\xe5\xad\x98\xe5\x9c\xa8\xe4\xb8\xa4\xe7\xa7\x8d\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8cState\xe4\xbb\xa5\xe5\x8f\x8a""Composites\xef\xbc\x8c\xe6\x89\x80\xe4\xbb\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe4\xbb\x96\xe4\xbb\xac\xe7\x9a\x84\xe5\x85\xac\xe7\x94\xa8\xe5\x9f\xba\xe7\xb1\xbb RuntimeNode\nTODO::\xe4\xb8\x8d\xe8\xa6\x81\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe8\xbf\x99\xe4\xba\x9b\xe5\xae\x9e\xe4\xbe\x8b\xe5\x8c\x96\xe4\xba\x86\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x81\xef\xbc\x81\xef\xbc\x81\xe8\xbf\x99\xe4\xbc\x9a\xe5\xaf\xbc\xe8\x87\xb4\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa2\xab\xe4\xbf\xae\xe6\x94\xb9\n\xe5\x88\x9b\xe5\xbb\xba\xe4\xb8\x80\xe4\xb8\xaa\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xef\xbc\x8c\xe7\xae\xa1\xe7\x90\x86\xe6\x89\x80\xe6\x9c\x89\xe5\x8a\xa0\xe8\xbd\xbd\xe7\x9a\x84\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\n            \xe5\x9c\xa8\xe5\x8a\xa0\xe8\xbd\xbd\xe6\x97\xb6\xef\xbc\x8c\xe4\xbc\x9a\xe6\xb7\xb1\xe5\xba\xa6\xe6\x8b\xb7\xe8\xb4\x9d\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe4\xb8\xad\xe7\x9a\x84\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\xb0\x86\xe5\x85\xb6\xe5\x8a\xa0\xe5\x85\xa5\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe5\xa4\x8d\xe5\x88\xb6" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CurState_MetaData[] = {
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CurState = { "CurState", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, CurState), Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CurState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CurState_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack_Inner = { "InstanceStack", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack_MetaData[] = {
		{ "Comment", "/** \xe6\x89\xa7\xe8\xa1\x8c\xe9\x93\xbe */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe6\x89\xa7\xe8\xa1\x8c\xe9\x93\xbe" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack = { "InstanceStack", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, InstanceStack), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_RootState_MetaData[] = {
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_RootState = { "RootState", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, RootState), Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_RootState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_RootState_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes_Inner = { "ScatteredNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes_MetaData[] = {
		{ "Comment", "// \xe6\x89\x80\xe6\x9c\x89\xe7\x9a\x84\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe6\x89\x80\xe6\x9c\x89\xe7\x9a\x84\xe9\x9b\xb6\xe6\x95\xa3\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes = { "ScatteredNodes", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, ScatteredNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CommonDataManager_MetaData[] = {
		{ "Comment", "/** \xe5\x85\xac\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe5\x85\xac\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CommonDataManager = { "CommonDataManager", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, CommonDataManager), Z_Construct_UClass_UFSMCommonDataManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CommonDataManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CommonDataManager_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_StateMachine_MetaData[] = {
		{ "Comment", "// \xe5\xbc\x95\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x88\x9b\xe5\xbb\xba\xe6\x96\xb0\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x8a\x82\xe7\x82\xb9\xe4\xbd\xbf\xe7\x94\xa8\n" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe5\xbc\x95\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x88\x9b\xe5\xbb\xba\xe6\x96\xb0\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x8a\x82\xe7\x82\xb9\xe4\xbd\xbf\xe7\x94\xa8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_StateMachine = { "StateMachine", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, StateMachine), Z_Construct_UClass_UFlowStateMachine_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_StateMachine_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_StateMachine_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_WidgetLayers_MetaData[] = {
		{ "Comment", "/** \xe5\xb8\x83\xe5\xb1\x80\xe6\x8e\xa7\xe4\xbb\xb6 */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe5\xb8\x83\xe5\xb1\x80\xe6\x8e\xa7\xe4\xbb\xb6" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_WidgetLayers = { "WidgetLayers", nullptr, (EPropertyFlags)0x0040000000082008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, WidgetLayers), Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_WidgetLayers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_WidgetLayers_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_ValueProp = { "CacheTemplateObjects", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_Key_KeyProp = { "CacheTemplateObjects_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_MetaData[] = {
		{ "Comment", "/* Dump Instance */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "Dump Instance" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects = { "CacheTemplateObjects", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, CacheTemplateObjects), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_ValueProp = { "ScatteredNodeMapping", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_Key_KeyProp = { "ScatteredNodeMapping_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_MetaData[] = {
		{ "Comment", "/** \xe7\xbc\x93\xe5\xad\x98\xe9\x9b\xb6\xe7\xa2\x8e\xe8\x8a\x82\xe7\x82\xb9\xe4\xb8\x8e\xe5\xae\x83\xe7\x9a\x84\xe5\x94\xaf\xe4\xb8\x80ID\xef\xbc\x8c\xe5\x8a\xa0\xe5\xbf\xab\xe6\x9f\xa5\xe8\xaf\xa2\xe9\x80\x9f\xe5\xba\xa6 */" },
		{ "ModuleRelativePath", "Public/SM/FlowStateContext.h" },
		{ "ToolTip", "\xe7\xbc\x93\xe5\xad\x98\xe9\x9b\xb6\xe7\xa2\x8e\xe8\x8a\x82\xe7\x82\xb9\xe4\xb8\x8e\xe5\xae\x83\xe7\x9a\x84\xe5\x94\xaf\xe4\xb8\x80ID\xef\xbc\x8c\xe5\x8a\xa0\xe5\xbf\xab\xe6\x9f\xa5\xe8\xaf\xa2\xe9\x80\x9f\xe5\xba\xa6" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping = { "ScatteredNodeMapping", nullptr, (EPropertyFlags)0x0040000000002000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateContext, ScatteredNodeMapping), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFlowStateContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CurState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_InstanceStack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_RootState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CommonDataManager,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_StateMachine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_WidgetLayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_CacheTemplateObjects,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateContext_Statics::NewProp_ScatteredNodeMapping,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateContext_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateContext>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateContext_Statics::ClassParams = {
		&UFlowStateContext::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFlowStateContext_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateContext_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateContext_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateContext()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateContext_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateContext, 43455541);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFlowStateContext>()
	{
		return UFlowStateContext::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateContext(Z_Construct_UClass_UFlowStateContext, &UFlowStateContext::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFlowStateContext"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateContext);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

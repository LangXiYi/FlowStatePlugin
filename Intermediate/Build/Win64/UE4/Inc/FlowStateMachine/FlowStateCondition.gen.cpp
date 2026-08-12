// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/SM/FlowStateCondition.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateCondition() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateCondition_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateCondition();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeSubNode_Condition();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateContext_NoRegister();
// End Cross Module References
	static FName NAME_UFlowStateCondition_BP_Condition = FName(TEXT("BP_Condition"));
	bool UFlowStateCondition::BP_Condition(UFlowStateContext* Context) const
	{
		FlowStateCondition_eventBP_Condition_Parms Parms;
		Parms.Context=Context;
		const_cast<UFlowStateCondition*>(this)->ProcessEvent(FindFunctionChecked(NAME_UFlowStateCondition_BP_Condition),&Parms);
		return !!Parms.ReturnValue;
	}
	void UFlowStateCondition::StaticRegisterNativesUFlowStateCondition()
	{
	}
	struct Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Context;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateCondition_eventBP_Condition_Parms, Context), Z_Construct_UClass_UFlowStateContext_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowStateCondition_eventBP_Condition_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowStateCondition_eventBP_Condition_Parms), &Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_Context,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Condition" },
		{ "ModuleRelativePath", "Public/SM/FlowStateCondition.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateCondition, nullptr, "BP_Condition", nullptr, nullptr, sizeof(FlowStateCondition_eventBP_Condition_Parms), Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateCondition_BP_Condition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateCondition_BP_Condition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateCondition_NoRegister()
	{
		return UFlowStateCondition::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateCondition_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateCondition_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMRuntimeSubNode_Condition,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateCondition_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateCondition_BP_Condition, "BP_Condition" }, // 2744386169
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateCondition_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SM/FlowStateCondition.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SM/FlowStateCondition.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateCondition_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateCondition>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateCondition_Statics::ClassParams = {
		&UFlowStateCondition::StaticClass,
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
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateCondition_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateCondition_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateCondition()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateCondition_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateCondition, 982635650);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFlowStateCondition>()
	{
		return UFlowStateCondition::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateCondition(Z_Construct_UClass_UFlowStateCondition, &UFlowStateCondition::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFlowStateCondition"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateCondition);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

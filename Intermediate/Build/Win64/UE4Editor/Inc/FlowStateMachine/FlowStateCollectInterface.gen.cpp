// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/FlowStateCollectInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateCollectInterface() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateCollectInterface_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFlowStateCollectInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
// End Cross Module References
	void IFlowStateCollectInterface::NativeGetStatePinInfos(TArray<FName>& Array) const
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_NativeGetStatePinInfos instead.");
	}
	void UFlowStateCollectInterface::StaticRegisterNativesUFlowStateCollectInterface()
	{
	}
	struct Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics
	{
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Array_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Array;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::NewProp_Array_Inner = { "Array", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::NewProp_Array = { "Array", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateCollectInterface_eventNativeGetStatePinInfos_Parms, Array), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::NewProp_Array_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::NewProp_Array,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \xe8\x93\x9d\xe5\x9b\xbe\xe5\xae\x9e\xe7\x8e\xb0 */" },
		{ "DisplayName", "GetStatePinInfos" },
		{ "ModuleRelativePath", "Public/FlowStateCollectInterface.h" },
		{ "ToolTip", "\xe8\x93\x9d\xe5\x9b\xbe\xe5\xae\x9e\xe7\x8e\xb0" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateCollectInterface, nullptr, "NativeGetStatePinInfos", nullptr, nullptr, sizeof(FlowStateCollectInterface_eventNativeGetStatePinInfos_Parms), Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48480800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateCollectInterface_NoRegister()
	{
		return UFlowStateCollectInterface::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateCollectInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateCollectInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateCollectInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateCollectInterface_NativeGetStatePinInfos, "NativeGetStatePinInfos" }, // 716226997
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateCollectInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FlowStateCollectInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateCollectInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IFlowStateCollectInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateCollectInterface_Statics::ClassParams = {
		&UFlowStateCollectInterface::StaticClass,
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
		0x001040A1u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateCollectInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateCollectInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateCollectInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateCollectInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateCollectInterface, 528292400);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFlowStateCollectInterface>()
	{
		return UFlowStateCollectInterface::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateCollectInterface(Z_Construct_UClass_UFlowStateCollectInterface, &UFlowStateCollectInterface::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFlowStateCollectInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateCollectInterface);
	static FName NAME_UFlowStateCollectInterface_NativeGetStatePinInfos = FName(TEXT("NativeGetStatePinInfos"));
	void IFlowStateCollectInterface::Execute_NativeGetStatePinInfos(const UObject* O, TArray<FName>& Array)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UFlowStateCollectInterface::StaticClass()));
		FlowStateCollectInterface_eventNativeGetStatePinInfos_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UFlowStateCollectInterface_NativeGetStatePinInfos);
		if (Func)
		{
			Parms.Array=Array;
			const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
			Array=Parms.Array;
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Graph/Schema/EdGraphSchema_FSM.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEdGraphSchema_FSM() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEdGraphSchemaAction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphSubNode_NoRegister();
	AIGRAPH_API UScriptStruct* Z_Construct_UScriptStruct_FGraphNodeClassData();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode();
	FLOWSTATEMACHINE_EDITOR_API UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UEdGraphSchema_FSM_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UEdGraphSchema_FSM();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
// End Cross Module References

static_assert(std::is_polymorphic<FFSMSchemaAction_NewSubNode>() == std::is_polymorphic<FEdGraphSchemaAction>(), "USTRUCT FFSMSchemaAction_NewSubNode cannot be polymorphic unless super FEdGraphSchemaAction is polymorphic");

class UScriptStruct* FFSMSchemaAction_NewSubNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_EDITOR_API uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode, Z_Construct_UPackage__Script_FlowStateMachine_Editor(), TEXT("FSMSchemaAction_NewSubNode"), sizeof(FFSMSchemaAction_NewSubNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_EDITOR_API UScriptStruct* StaticStruct<FFSMSchemaAction_NewSubNode>()
{
	return FFSMSchemaAction_NewSubNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FFSMSchemaAction_NewSubNode(FFSMSchemaAction_NewSubNode::StaticStruct, TEXT("/Script/FlowStateMachine_Editor"), TEXT("FSMSchemaAction_NewSubNode"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewSubNode
{
	FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewSubNode()
	{
		UScriptStruct::DeferCppStructOps<FFSMSchemaAction_NewSubNode>(FName(TEXT("FSMSchemaAction_NewSubNode")));
	}
} ScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewSubNode;
	struct Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeTemplateClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_NodeTemplateClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClassData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentGraphNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentGraphNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Action to add a subnode to the selected node */" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ToolTip", "Action to add a subnode to the selected node" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFSMSchemaAction_NewSubNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_NodeTemplateClass_MetaData[] = {
		{ "Comment", "/** Template of node we want to create */" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ToolTip", "Template of node we want to create" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_NodeTemplateClass = { "NodeTemplateClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewSubNode, NodeTemplateClass), Z_Construct_UClass_UFSMGraphSubNode_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_NodeTemplateClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_NodeTemplateClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ClassData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ClassData = { "ClassData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewSubNode, ClassData), Z_Construct_UScriptStruct_FGraphNodeClassData, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ClassData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ClassData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ParentGraphNode_MetaData[] = {
		{ "Comment", "/** parent node */" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ToolTip", "parent node" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ParentGraphNode = { "ParentGraphNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewSubNode, ParentGraphNode), Z_Construct_UClass_UFSMGraphNode_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ParentGraphNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ParentGraphNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_NodeTemplateClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ClassData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::NewProp_ParentGraphNode,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"FSMSchemaAction_NewSubNode",
		sizeof(FFSMSchemaAction_NewSubNode),
		alignof(FFSMSchemaAction_NewSubNode),
		Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine_Editor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("FSMSchemaAction_NewSubNode"), sizeof(FFSMSchemaAction_NewSubNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewSubNode_Hash() { return 581194954U; }

static_assert(std::is_polymorphic<FFSMSchemaAction_NewJumpNode>() == std::is_polymorphic<FFSMSchemaAction_NewNode>(), "USTRUCT FFSMSchemaAction_NewJumpNode cannot be polymorphic unless super FFSMSchemaAction_NewNode is polymorphic");

class UScriptStruct* FFSMSchemaAction_NewJumpNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_EDITOR_API uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode, Z_Construct_UPackage__Script_FlowStateMachine_Editor(), TEXT("FSMSchemaAction_NewJumpNode"), sizeof(FFSMSchemaAction_NewJumpNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_EDITOR_API UScriptStruct* StaticStruct<FFSMSchemaAction_NewJumpNode>()
{
	return FFSMSchemaAction_NewJumpNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FFSMSchemaAction_NewJumpNode(FFSMSchemaAction_NewJumpNode::StaticStruct, TEXT("/Script/FlowStateMachine_Editor"), TEXT("FSMSchemaAction_NewJumpNode"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewJumpNode
{
	FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewJumpNode()
	{
		UScriptStruct::DeferCppStructOps<FFSMSchemaAction_NewJumpNode>(FName(TEXT("FSMSchemaAction_NewJumpNode")));
	}
} ScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewJumpNode;
	struct Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpStartID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_JumpStartID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFSMSchemaAction_NewJumpNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewProp_JumpStartID_MetaData[] = {
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewProp_JumpStartID = { "JumpStartID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewJumpNode, JumpStartID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewProp_JumpStartID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewProp_JumpStartID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::NewProp_JumpStartID,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
		Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode,
		&NewStructOps,
		"FSMSchemaAction_NewJumpNode",
		sizeof(FFSMSchemaAction_NewJumpNode),
		alignof(FFSMSchemaAction_NewJumpNode),
		Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine_Editor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("FSMSchemaAction_NewJumpNode"), sizeof(FFSMSchemaAction_NewJumpNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewJumpNode_Hash() { return 2079123683U; }

static_assert(std::is_polymorphic<FFSMSchemaAction_NewNode>() == std::is_polymorphic<FEdGraphSchemaAction>(), "USTRUCT FFSMSchemaAction_NewNode cannot be polymorphic unless super FEdGraphSchemaAction is polymorphic");

class UScriptStruct* FFSMSchemaAction_NewNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_EDITOR_API uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode, Z_Construct_UPackage__Script_FlowStateMachine_Editor(), TEXT("FSMSchemaAction_NewNode"), sizeof(FFSMSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_EDITOR_API UScriptStruct* StaticStruct<FFSMSchemaAction_NewNode>()
{
	return FFSMSchemaAction_NewNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FFSMSchemaAction_NewNode(FFSMSchemaAction_NewNode::StaticStruct, TEXT("/Script/FlowStateMachine_Editor"), TEXT("FSMSchemaAction_NewNode"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewNode
{
	FScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewNode()
	{
		UScriptStruct::DeferCppStructOps<FFSMSchemaAction_NewNode>(FName(TEXT("FSMSchemaAction_NewNode")));
	}
} ScriptStruct_FlowStateMachine_Editor_StaticRegisterNativesFFSMSchemaAction_NewNode;
	struct Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeTemplateClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_NodeTemplateClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClassData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Action to add a subnode to the selected node */" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ToolTip", "Action to add a subnode to the selected node" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFSMSchemaAction_NewNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_NodeTemplateClass_MetaData[] = {
		{ "Comment", "/** Template of node we want to create */" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ToolTip", "Template of node we want to create" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_NodeTemplateClass = { "NodeTemplateClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewNode, NodeTemplateClass), Z_Construct_UClass_UFSMGraphNode_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_NodeTemplateClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_NodeTemplateClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_ClassData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_ClassData = { "ClassData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFSMSchemaAction_NewNode, ClassData), Z_Construct_UScriptStruct_FGraphNodeClassData, METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_ClassData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_ClassData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_NodeTemplateClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::NewProp_ClassData,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
		Z_Construct_UScriptStruct_FEdGraphSchemaAction,
		&NewStructOps,
		"FSMSchemaAction_NewNode",
		sizeof(FFSMSchemaAction_NewNode),
		alignof(FFSMSchemaAction_NewNode),
		Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine_Editor();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("FSMSchemaAction_NewNode"), sizeof(FFSMSchemaAction_NewNode), Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FFSMSchemaAction_NewNode_Hash() { return 1994745553U; }
	void UEdGraphSchema_FSM::StaticRegisterNativesUEdGraphSchema_FSM()
	{
	}
	UClass* Z_Construct_UClass_UEdGraphSchema_FSM_NoRegister()
	{
		return UEdGraphSchema_FSM::StaticClass();
	}
	struct Z_Construct_UClass_UEdGraphSchema_FSM_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEdGraphSchema_FSM_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEdGraphSchema_FSM_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/Schema/EdGraphSchema_FSM.h" },
		{ "ModuleRelativePath", "Public/Graph/Schema/EdGraphSchema_FSM.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEdGraphSchema_FSM_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEdGraphSchema_FSM>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UEdGraphSchema_FSM_Statics::ClassParams = {
		&UEdGraphSchema_FSM::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UEdGraphSchema_FSM_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEdGraphSchema_FSM_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEdGraphSchema_FSM()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UEdGraphSchema_FSM_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UEdGraphSchema_FSM, 2724208380);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UEdGraphSchema_FSM>()
	{
		return UEdGraphSchema_FSM::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UEdGraphSchema_FSM(Z_Construct_UClass_UEdGraphSchema_FSM, &UEdGraphSchema_FSM::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UEdGraphSchema_FSM"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEdGraphSchema_FSM);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

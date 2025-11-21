#include "K2Node_SpawnAndBindActor.h"

#include "GameplayTagContainer.h"
#include "K2Node_CallArrayFunction.h"
#include "K2Node_CallFunction.h"
#include "K2Node_EnumLiteral.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_Select.h"
#include "KismetCompiler.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Library/FSMFunctionLibrary.h"

struct FK2Node_SpawnAndBindActorHelper
{
	static const FName ClassPinName;
	
	static const FName SpawnTransformPinName;
	static const FName SpawnEvenIfCollidingPinName;
	static const FName NoCollisionFailPinName;
	static const FName CollisionHandlingOverridePinName;
	static const FName TransformScaleMethodPinName;
	static const FName OwnerPinName;
	
	static const FName LifetimeName;
	static const FName ActorTagName;
	static const FName MeshName;
};

const FName FK2Node_SpawnAndBindActorHelper::ClassPinName(TEXT("Class"));

const FName FK2Node_SpawnAndBindActorHelper::SpawnTransformPinName(TEXT("SpawnTransform"));
const FName FK2Node_SpawnAndBindActorHelper::SpawnEvenIfCollidingPinName(TEXT("SpawnEvenIfColliding"));		// deprecated pin, name kept for backwards compat
const FName FK2Node_SpawnAndBindActorHelper::NoCollisionFailPinName(TEXT("bNoCollisionFail"));		// deprecated pin, name kept for backwards compat
const FName FK2Node_SpawnAndBindActorHelper::CollisionHandlingOverridePinName(TEXT("CollisionHandlingOverride"));
const FName FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName(TEXT("TransformScaleMethod"));
const FName FK2Node_SpawnAndBindActorHelper::OwnerPinName(TEXT("Owner"));

const FName FK2Node_SpawnAndBindActorHelper::LifetimeName(TEXT("Lifetime"));
const FName FK2Node_SpawnAndBindActorHelper::ActorTagName(TEXT("ActorTag"));
const FName FK2Node_SpawnAndBindActorHelper::MeshName(TEXT("Mesh"));

#define LOCTEXT_NAMESPACE "K2Node_SpawnAndBindActor"

UK2Node_SpawnAndBindActor::UK2Node_SpawnAndBindActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeTooltip = LOCTEXT("NodeTooltip", "Spawn a new actor from class and bind for state.");
}

void UK2Node_SpawnAndBindActor::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	// Transform pin
	UScriptStruct* TransformStruct = TBaseStructure<FTransform>::Get();
	UEdGraphPin* TransformPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, TransformStruct, FK2Node_SpawnAndBindActorHelper::SpawnTransformPinName);

	// Actor Tag
	UEdGraphPin* ActorTagPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Name, FK2Node_SpawnAndBindActorHelper::ActorTagName);

	// State Lifetime Pins
	UEnum* LifetimeEnum = StaticEnum<EFlowStateLifetime>();
	UEdGraphPin* LifetimeNamePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, LifetimeEnum, FK2Node_SpawnAndBindActorHelper::LifetimeName);
	LifetimeNamePin->DefaultValue = LifetimeEnum->GetNameStringByValue(static_cast<int>(EFlowStateLifetime::Kill));
	
	// Collision handling method pin
	UEnum* const CollisionMethodEnum = StaticEnum<ESpawnActorCollisionHandlingMethod>();
	UEdGraphPin* const CollisionHandlingOverridePin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, CollisionMethodEnum, FK2Node_SpawnAndBindActorHelper::CollisionHandlingOverridePinName);
	CollisionHandlingOverridePin->DefaultValue = CollisionMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorCollisionHandlingMethod::Undefined));

#if ENGINE_MAJOR_VERSION >= 5
	// Pin to set transform scaling behavior (ie whether to multiply scale with root component or to just ignore the root component default scale)
	UEnum* const ScaleMethodEnum = StaticEnum<ESpawnActorScaleMethod>();
	UEdGraphPin* const ScaleMethodPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Byte, ScaleMethodEnum, FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName);
	ScaleMethodPin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::SelectDefaultAtRuntime));
	ScaleMethodPin->bAdvancedView = true;
#endif
	
	UEdGraphPin* OwnerPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, AActor::StaticClass(), FK2Node_SpawnAndBindActorHelper::OwnerPinName);
	OwnerPin->bAdvancedView = true;
	if (ENodeAdvancedPins::NoPins == AdvancedPinDisplay)
	{
		AdvancedPinDisplay = ENodeAdvancedPins::Hidden;
	}
}

FLinearColor UK2Node_SpawnAndBindActor::GetNodeTitleColor() const
{
	return Super::GetNodeTitleColor();
}

FText UK2Node_SpawnAndBindActor::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	FText NodeTitle = NSLOCTEXT("K2Node", "SpawnAndBindActor_BaseTitle", "Spawn And Bind Actor from Class");
	if (TitleType != ENodeTitleType::MenuTitle)
	{
		if (UEdGraphPin* ClassPin = GetClassPin())
		{
			if (ClassPin->LinkedTo.Num() > 0)
			{
				// Blueprint will be determined dynamically, so we don't have the name in this case
				NodeTitle = NSLOCTEXT("K2Node", "SpawnAndBindActor_Title_Unknown", "SpawnAndBindActor");
			}
			else if (ClassPin->DefaultObject == nullptr)
			{
				NodeTitle = NSLOCTEXT("K2Node", "SpawnAndBindActor_Title_NONE", "SpawnAndBindActor NONE");
			}
			else
			{
				if (CachedNodeTitle.IsOutOfDate(this))
				{
					FText ClassName;
					if (UClass* PickedClass = Cast<UClass>(ClassPin->DefaultObject))
					{
						ClassName = PickedClass->GetDisplayNameText();
					}

					FFormatNamedArguments Args;
					Args.Add(TEXT("ClassName"), ClassName);

					// FText::Format() is slow, so we cache this to save on performance
					CachedNodeTitle.SetCachedText(FText::Format(NSLOCTEXT("K2Node", "SpawnAndBindActor_Title_Class", "SpawnAndBindActor {ClassName}"), Args), this);
				}
				NodeTitle = CachedNodeTitle;
			} 
		}
		else
		{
			NodeTitle = NSLOCTEXT("K2Node", "SpawnAndBindActor_Title_NONE", "SpawnAndBindActor NONE");
		}
	}
	return NodeTitle;
}

FEdGraphNodeDeprecationResponse UK2Node_SpawnAndBindActor::GetDeprecationResponse(
	EEdGraphNodeDeprecationType DeprecationType) const
{
	FEdGraphNodeDeprecationResponse Response = Super::GetDeprecationResponse(DeprecationType);
	if (DeprecationType == EEdGraphNodeDeprecationType::NodeTypeIsDeprecated)
	{
		Response.MessageType = EEdGraphNodeDeprecationMessageType::None;
		Response.MessageText = LOCTEXT("SpawnActorNodeOnlyDefaultBlueprint_Deprecatio", "Spawn Actor @@ is DEPRECATED and should be replaced by SpawnActorFromClass");
	}

	return Response;
}

FSlateIcon UK2Node_SpawnAndBindActor::GetIconAndTint(FLinearColor& OutColor) const
{
#if ENGINE_MAJOR_VERSION >= 5
	static FSlateIcon Icon(FAppStyle::GetAppStyleSetName(), "GraphEditor.SpawnActor_16x");
#else
	static FSlateIcon Icon("EditorStyle", "GraphEditor.SpawnActor_16x");
#endif
	return Icon;
}

bool UK2Node_SpawnAndBindActor::IsCompatibleWithGraph(const UEdGraph* TargetGraph) const
{
	UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraph(TargetGraph);
	return Super::IsCompatibleWithGraph(TargetGraph) && (!Blueprint || (FBlueprintEditorUtils::FindUserConstructionScript(Blueprint) != TargetGraph && Blueprint->GeneratedClass->GetDefaultObject()->ImplementsGetWorld()));
}

void UK2Node_SpawnAndBindActor::PostPlacedNewNode()
{
#if ENGINE_MAJOR_VERSION >= 5
	UEdGraphPin* const ScaleMethodPin = GetScaleMethodPin();
	const UEnum* const ScaleMethodEnum = StaticEnum<ESpawnActorScaleMethod>();
	ScaleMethodPin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::MultiplyWithRoot));
#endif
}

void UK2Node_SpawnAndBindActor::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
#if ENGINE_MAJOR_VERSION >= 5
	Ar.UsingCustomVersion(FUE5MainStreamObjectVersion::GUID);
#endif
}

void UK2Node_SpawnAndBindActor::PostLoad()
{
	FixupScaleMethodPin();
	Super::PostLoad();
}

void UK2Node_SpawnAndBindActor::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	// const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FName Tag, TArray<AActor*>& OutActors
	static const FName BeginSpawningBlueprintFuncName = GET_FUNCTION_NAME_CHECKED(UGameplayStatics, BeginDeferredActorSpawnFromClass);
	static const FName ActorClassParamName(TEXT("ActorClass"));
	static const FName CollisionHandlingOverrideParamName(TEXT("CollisionHandlingOverride"));
	static const FName WorldContextParamName(TEXT("WorldContextObject"));

	static const  FName FinishSpawningFuncName = GET_FUNCTION_NAME_CHECKED(UGameplayStatics, FinishSpawningActor);
	static const  FName ActorParamName(TEXT("Actor"));
	static const  FName TransformParamName(TEXT("SpawnTransform"));
	static const  FName NoCollisionFailParamName(TEXT("bNoCollisionFail"));

	static const  FName InitObjectFuncName = GET_FUNCTION_NAME_CHECKED(UFSMFunctionLibrary, InitActorLifetimeState);
	static const  FName TargetParamName(TEXT("Target"));
	static const  FName LifetimeParamName(TEXT("Lifetime"));
	static const  FName ActorTagParamName(TEXT("ActorTag"));

	static const  FName ObjectParamName(TEXT("Object"));
	static const  FName ValueParamName(TEXT("Value"));
	static const  FName PropertyNameParamName(TEXT("PropertyName"));

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	UK2Node_SpawnAndBindActor* SpawnNode = this;

	UEdGraphPin* SpawnNodeExec = GetExecPin();
	UEdGraphPin* SpawnNodeTransform = GetSpawnTransformPin();
	UEdGraphPin* SpawnWorldContextPin = GetWorldContextPin();
	UEdGraphPin* SpawnClassPin = GetClassPin();
	UEdGraphPin* SpawnNodeThen = GetThenPin();
	UEdGraphPin* SpawnNodeResult = GetResultPin();
	UEdGraphPin* SpawnNodeOwnerPin = GetOwnerPin();
	UEdGraphPin* SpawnNodeCollisionHandlingOverride = GetCollisionHandlingOverridePin();
	UEdGraphPin* SpawnNodeScaleMethod = TryGetScaleMethodPin();

	UEdGraphPin* InitNodeLifetime = GetLifetimePin();
	UEdGraphPin* InitNodeActorTag = GetActorTagPin();

	// Cache the class to spawn. Note, this is the compile time class that the pin was set to or the variable type it was connected to. Runtime it could be a child.
	UClass* ClassToSpawn = GetClassToSpawn();

	UClass* SpawnClass = (SpawnClassPin != NULL) ? Cast<UClass>(SpawnClassPin->DefaultObject) : NULL;
	if ( !SpawnClassPin || ((0 == SpawnClassPin->LinkedTo.Num()) && (NULL == SpawnClass)))
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("SpawnActorNodeMissingClass_Error", "Spawn node @@ must have a @@ specified.").ToString(), SpawnNode, SpawnClassPin);
		// we break exec links so this is the only error we get, don't want the SpawnActor node being considered and giving 'unexpected node' type warnings
		SpawnNode->BreakAllNodeLinks();
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	// create 'Find Cache Actor' call node
	FName FindActorFuncName = (GET_FUNCTION_NAME_CHECKED(UFSMFunctionLibrary, FindActorFromCache));
	static const FName FindActorFindActorName = TEXT("FindActor");
	
	UK2Node_CallFunction* CallFindActorNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallFindActorNode->FunctionReference.SetExternalMember(FindActorFuncName, UFSMFunctionLibrary::StaticClass());
	CallFindActorNode->AllocateDefaultPins();

	UEdGraphPin* CallFindActorExecPin = CallFindActorNode->GetExecPin();
	UEdGraphPin* CallFindActorThenPin = CallFindActorNode->GetThenPin();
	UEdGraphPin* CallFindActorReturnPin = CallFindActorNode->GetReturnValuePin();
	UEdGraphPin* CallFindActorWorldPin = CallFindActorNode->FindPinChecked(WorldContextParamName);
	UEdGraphPin* CallFindActorClassPin = CallFindActorNode->FindPinChecked(ActorClassParamName);
	UEdGraphPin* CallFindActorTagPin = CallFindActorNode->FindPinChecked(ActorTagParamName);
	UEdGraphPin* CallFindActorResultPin = CallFindActorNode->FindPinChecked(FindActorFindActorName);

	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeExec, *CallFindActorExecPin);
	if (SpawnWorldContextPin)
	{
		CompilerContext.MovePinLinksToIntermediate(*SpawnWorldContextPin, *CallFindActorWorldPin);
	}

	if(SpawnClassPin->LinkedTo.Num() > 0)
	{
		// Copy the 'blueprint' connection from the spawn node to 'begin spawn'
		CompilerContext.MovePinLinksToIntermediate(*SpawnClassPin, *CallFindActorClassPin);
	}
	else
	{
		// Copy blueprint literal onto begin spawn call 
		CallFindActorClassPin->DefaultObject = ClassToSpawn;
	}
	CompilerContext.MovePinLinksToIntermediate(*InitNodeActorTag, *CallFindActorTagPin);

	//////////////////////////////////////////////////////////////////////////
	// create 'Branch Node' call node
	UK2Node_IfThenElse* BranchNode = CompilerContext.SpawnIntermediateNode<UK2Node_IfThenElse>(this, SourceGraph);
	BranchNode->AllocateDefaultPins();

	UEdGraphPin* BranchNodeExecPin = BranchNode->GetExecPin();
	UEdGraphPin* BranchNodeElsePin = BranchNode->GetElsePin();
	UEdGraphPin* BranchNodeConditionPin = BranchNode->GetConditionPin();

	CallFindActorThenPin->MakeLinkTo(BranchNodeExecPin);
	CallFindActorReturnPin->MakeLinkTo(BranchNodeConditionPin);
	
	
	//////////////////////////////////////////////////////////////////////////
	// create 'begin spawn' call node
	UK2Node_CallFunction* CallBeginSpawnNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallBeginSpawnNode->FunctionReference.SetExternalMember(BeginSpawningBlueprintFuncName, UGameplayStatics::StaticClass());
	CallBeginSpawnNode->AllocateDefaultPins();

	UEdGraphPin* CallBeginExec = CallBeginSpawnNode->GetExecPin();
	UEdGraphPin* CallBeginWorldContextPin = CallBeginSpawnNode->FindPinChecked(WorldContextParamName);
	UEdGraphPin* CallBeginActorClassPin = CallBeginSpawnNode->FindPinChecked(ActorClassParamName);
	UEdGraphPin* CallBeginTransform = CallBeginSpawnNode->FindPinChecked(TransformParamName);
	UEdGraphPin* CallBeginCollisionHandlingOverride = CallBeginSpawnNode->FindPinChecked(CollisionHandlingOverrideParamName);

	UEdGraphPin* CallBeginOwnerPin = CallBeginSpawnNode->FindPinChecked(FK2Node_SpawnAndBindActorHelper::OwnerPinName);
	UEdGraphPin* CallBeginResult = CallBeginSpawnNode->GetReturnValuePin();

	// 将分支节点的 Else 引脚指向 Begin Spawn 节点
	BranchNodeElsePin->MakeLinkTo(CallBeginExec);
	// CompilerContext.MovePinLinksToIntermediate(*SpawnNodeExec, *CallBeginExec);
	
	// if(CallFindActorClassPin->LinkedTo.Num() > 0)
	if(CallFindActorClassPin->LinkedTo.Num() > 0)
	{
		// Copy the 'blueprint' connection from the spawn node to 'begin spawn'
		// CompilerContext.MovePinLinksToIntermediate(*SpawnClassPin, *CallBeginActorClassPin);
		CompilerContext.CopyPinLinksToIntermediate(*CallFindActorClassPin, *CallBeginActorClassPin);
	}
	else
	{
		// Copy blueprint literal onto begin spawn call 
		CallBeginActorClassPin->DefaultObject = ClassToSpawn;
	}

	// Copy the world context connection from the spawn node to 'begin spawn' if necessary
	if (SpawnWorldContextPin)
	{
		// CompilerContext.MovePinLinksToIntermediate(*SpawnWorldContextPin, *CallBeginWorldContextPin);
		CompilerContext.CopyPinLinksToIntermediate(*CallFindActorWorldPin, *CallBeginWorldContextPin);
	}

	if (SpawnNodeOwnerPin != nullptr)
	{
		CompilerContext.MovePinLinksToIntermediate(*SpawnNodeOwnerPin, *CallBeginOwnerPin);
	}

	// Copy the 'transform' connection from the spawn node to 'begin spawn'
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeTransform, *CallBeginTransform);
	
	// Copy the 'CollisionHandlingOverride' connection from the spawn node to 'begin spawn'
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeCollisionHandlingOverride, *CallBeginCollisionHandlingOverride);
	// Copy the 'ScaleMethod' connection from the spawn node to 'begin spawn'
#if ENGINE_MAJOR_VERSION >= 5
	UEdGraphPin* CallBeginScaleMethod = CallBeginSpawnNode->FindPinChecked(FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName);
	if (SpawnNodeScaleMethod)
	{
		CompilerContext.MovePinLinksToIntermediate(*SpawnNodeScaleMethod, *CallBeginScaleMethod);
	}
	else
	{
		// if for some reason we couldn't find scale method pin on the spawn node, defer it's value to runtime
		const UEnum* const ScaleMethodEnum = StaticEnum<ESpawnActorScaleMethod>();
		CallBeginScaleMethod->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::SelectDefaultAtRuntime));
	}
#endif

	//////////////////////////////////////////////////////////////////////////
	// create 'finish spawn' call node
	UK2Node_CallFunction* CallFinishSpawnNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallFinishSpawnNode->FunctionReference.SetExternalMember(FinishSpawningFuncName, UGameplayStatics::StaticClass());
	CallFinishSpawnNode->AllocateDefaultPins();

	UEdGraphPin* CallFinishExec = CallFinishSpawnNode->GetExecPin();
	UEdGraphPin* CallFinishThen = CallFinishSpawnNode->GetThenPin();
	UEdGraphPin* CallFinishActor = CallFinishSpawnNode->FindPinChecked(ActorParamName);
	UEdGraphPin* CallFinishTransform = CallFinishSpawnNode->FindPinChecked(TransformParamName);
	UEdGraphPin* CallFinishResult = CallFinishSpawnNode->GetReturnValuePin();

	// Copy transform connection
	CompilerContext.CopyPinLinksToIntermediate(*CallBeginTransform, *CallFinishTransform);
	// Connect output actor from 'begin' to 'finish'
	CallBeginResult->MakeLinkTo(CallFinishActor);

	
	//////////////////////////////////////////////////////////////////////////
	// create 'Select Object' nodes
	static const FName SelectObjectFuncName = (GET_FUNCTION_NAME_CHECKED(UKismetMathLibrary, SelectObject));
	static const FName SelectObjectAName = TEXT("A");
	static const FName SelectObjectBName = TEXT("B");
	static const FName SelectConditionName = TEXT("bSelectA");
	
	UK2Node_CallFunction* CallSelectObjectNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallSelectObjectNode->FunctionReference.SetExternalMember(SelectObjectFuncName, UKismetMathLibrary::StaticClass());
	CallSelectObjectNode->AllocateDefaultPins();
	
	UEdGraphPin* SelectConditionPin = CallSelectObjectNode->FindPinChecked(SelectConditionName);
	UEdGraphPin* SelectObjectAPin = CallSelectObjectNode->FindPinChecked(SelectObjectAName);
	UEdGraphPin* SelectObjectBPin = CallSelectObjectNode->FindPinChecked(SelectObjectBName);
	UEdGraphPin* SelectObjectReturnValuePin = CallSelectObjectNode->GetReturnValuePin();
	
	CallFindActorReturnPin->MakeLinkTo(SelectConditionPin);
	CallFindActorResultPin->MakeLinkTo(SelectObjectAPin);
	CallFinishResult->MakeLinkTo(SelectObjectBPin);

	SelectObjectReturnValuePin->PinType = SpawnNodeResult->PinType; // Copy type so it uses the right actor subclass

	//////////////////////////////////////////////////////////////////////////
	// create 'init object' call node
	UK2Node_CallFunction* CallInitObjectNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallInitObjectNode->FunctionReference.SetExternalMember(InitObjectFuncName, UFSMFunctionLibrary::StaticClass());
	CallInitObjectNode->AllocateDefaultPins();

	UEdGraphPin* CallInitObjectExec = CallInitObjectNode->GetExecPin();
	UEdGraphPin* CallInitObjectThen = CallInitObjectNode->GetThenPin();
	UEdGraphPin* CallInitObjectResultPin = CallInitObjectNode->GetReturnValuePin();
	UEdGraphPin* CallInitObjectTarget = CallInitObjectNode->FindPinChecked(TargetParamName);
	UEdGraphPin* CallInitObjectLifetime = CallInitObjectNode->FindPinChecked(LifetimeParamName);
	UEdGraphPin* CallInitObjectActorTag = CallInitObjectNode->FindPinChecked(ActorTagParamName);

	CallInitObjectResultPin->PinType = SpawnNodeResult->PinType; // Copy type so it uses the right actor subclass
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeResult, *CallInitObjectResultPin);
	CompilerContext.MovePinLinksToIntermediate(*SpawnNodeThen, *CallInitObjectThen);

	SelectObjectReturnValuePin->MakeLinkTo(CallInitObjectTarget);
	// CallFinishResult->MakeLinkTo(CallInitObjectTarget); // DEBUG

	// debug
	// CallFinishResult->PinType = SpawnNodeResult->PinType; // Copy type so it uses the right actor subclass
	// CompilerContext.MovePinLinksToIntermediate(*SpawnNodeResult, *CallFinishResult);
	
	CompilerContext.MovePinLinksToIntermediate(*InitNodeLifetime, *CallInitObjectLifetime);
	CompilerContext.CopyPinLinksToIntermediate(*CallFindActorTagPin, *CallInitObjectActorTag);

	//////////////////////////////////////////////////////////////////////////
	// create 'set var' nodes
	// 初始化对象属性，在创建对象成功并调用 InitObject 后执行...
	UK2Node_CallFunction* LastNodeOnSpawn = CallBeginSpawnNode;
	UK2Node* LastNodeOnFind = BranchNode;

	// Create 'set var by name' nodes and hook them up
	for(int32 PinIdx=0; PinIdx < Pins.Num(); PinIdx++)
	{
		// Only create 'set param by name' node if this pin is linked to something
		UEdGraphPin* SpawnVarPin = Pins[PinIdx];
		/*if (SpawnVarPin->PinName == FK2Node_SpawnAndBindActorHelper::MeshName)
		{
			// set actor mesh
			UK2Node_CallFunction* MeshNode_OnSpawn = nullptr;
			UK2Node_CallFunction* MeshNode_OnFind = nullptr;
			// 设置Actor模型
			if (ClassToSpawn == AStaticMeshActor::StaticClass())
			{
				FName FuncName = GET_FUNCTION_NAME_CHECKED(UFSMFunctionLibrary, SetActorStaticMesh);
				MeshNode_OnSpawn = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				MeshNode_OnSpawn->FunctionReference.SetExternalMember(FuncName, UFSMFunctionLibrary::StaticClass());

				MeshNode_OnFind = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				MeshNode_OnFind->FunctionReference.SetExternalMember(FuncName, UFSMFunctionLibrary::StaticClass());
			}
			else if (ClassToSpawn == ASkeletalMeshActor::StaticClass())
			{
				FName FuncName = GET_FUNCTION_NAME_CHECKED(UFSMFunctionLibrary, SetActorSkeletalMesh);
				MeshNode_OnSpawn = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				MeshNode_OnSpawn->FunctionReference.SetExternalMember(FuncName, UFSMFunctionLibrary::StaticClass());

				MeshNode_OnFind = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				MeshNode_OnFind->FunctionReference.SetExternalMember(FuncName, UFSMFunctionLibrary::StaticClass());
			}
			/**
			 * Create Set Mesh Node On Spawn Actor
			 #1#
			MeshNode_OnSpawn->AllocateDefaultPins();
			// Link pin
			UEdGraphPin* LastThenOnSpawn = LastNodeOnSpawn->GetThenPin();
			UEdGraphPin* MeshExecPinOnSpawn = MeshNode_OnSpawn->GetExecPin();
			UEdGraphPin* MeshTargetPinOnSpawn = MeshNode_OnSpawn->FindPinChecked(FName("Target"));
			UEdGraphPin* MeshMeshPinOnSpawn = MeshNode_OnSpawn->FindPinChecked(FName("Mesh"));
		
			LastThenOnSpawn->MakeLinkTo(MeshExecPinOnSpawn);
			// 复制Actor指针，并移动Mesh指针至临时节点
			CallBeginResult->MakeLinkTo(MeshTargetPinOnSpawn);
			CompilerContext.MovePinLinksToIntermediate(*SpawnVarPin, *MeshMeshPinOnSpawn);
			LastNodeOnSpawn = MeshNode_OnSpawn;

			/**
			 * Create Set Mesh Node On Find Actor
			 #1#
			MeshNode_OnFind->AllocateDefaultPins();
			// Link pin
			UEdGraphPin* LastThenOnFind = LastNodeOnFind->FindPinChecked(UEdGraphSchema_K2::PN_Then);
			UEdGraphPin* MeshExecPinOnFind = MeshNode_OnFind->GetExecPin();
			UEdGraphPin* MeshTargetPinOnFind = MeshNode_OnFind->FindPinChecked(FName("Target"));
			UEdGraphPin* MeshMeshPinOnFind = MeshNode_OnFind->FindPinChecked(FName("Mesh"));
		
			LastThenOnFind->MakeLinkTo(MeshExecPinOnFind);
			// 复制Actor指针，并移动Mesh指针至临时节点
			CallFindActorResultPin->MakeLinkTo(MeshTargetPinOnFind);
			CompilerContext.CopyPinLinksToIntermediate(*MeshMeshPinOnSpawn, *MeshMeshPinOnFind);
			LastNodeOnFind = MeshNode_OnFind;
		}*/
		if(SpawnVarPin->LinkedTo.Num() > 0)
		{
			UFunction* SetByNameFunction = Schema->FindSetVariableByNameFunction(SpawnVarPin->PinType);
			if(SetByNameFunction)
			{
				UK2Node_CallFunction* SetVarNodeOnSpawn = NULL;
				if(SpawnVarPin->PinType.IsArray())
				{
					SetVarNodeOnSpawn = CompilerContext.SpawnIntermediateNode<UK2Node_CallArrayFunction>(this, SourceGraph);
				}
				else
				{
					SetVarNodeOnSpawn = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				}
				SetVarNodeOnSpawn->SetFromFunction(SetByNameFunction);
				SetVarNodeOnSpawn->AllocateDefaultPins();

				// Connect this node into the exec chain
				UEdGraphPin* LastThenOnSpawn = LastNodeOnSpawn->GetThenPin();
				UEdGraphPin* SetVarExecOnSpawn = SetVarNodeOnSpawn->GetExecPin();
				LastThenOnSpawn->MakeLinkTo(SetVarExecOnSpawn);

				// Connect the new actor to the 'object' pin
				UEdGraphPin* ObjectPinOnSpawn = SetVarNodeOnSpawn->FindPinChecked(ObjectParamName);
				CallBeginResult->MakeLinkTo(ObjectPinOnSpawn);

				// Fill in literal for 'property name' pin - name of pin is property name
				UEdGraphPin* PropertyNamePinOnSpawn = SetVarNodeOnSpawn->FindPinChecked(PropertyNameParamName);
				PropertyNamePinOnSpawn->DefaultValue = SpawnVarPin->PinName.ToString();

				// Move connection from the variable pin on the spawn node to the 'value' pin
				UEdGraphPin* ValuePinOnSpawn = SetVarNodeOnSpawn->FindPinChecked(ValueParamName);
				CompilerContext.MovePinLinksToIntermediate(*SpawnVarPin, *ValuePinOnSpawn);
				if(SpawnVarPin->PinType.IsArray())
				{
					SetVarNodeOnSpawn->PinConnectionListChanged(ValuePinOnSpawn);
				}

				// Update 'last node in sequence' var
				LastNodeOnSpawn = SetVarNodeOnSpawn;

				/*UK2Node_CallFunction* SetVarNodeOnFind = NULL;
				if(SpawnVarPin->PinType.IsArray())
				{
					SetVarNodeOnFind = CompilerContext.SpawnIntermediateNode<UK2Node_CallArrayFunction>(this, SourceGraph);
				}
				else
				{
					SetVarNodeOnFind = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
				}
				SetVarNodeOnFind->SetFromFunction(SetByNameFunction);
				SetVarNodeOnFind->AllocateDefaultPins();

				// Connect this node into the exec chain
				UEdGraphPin* LastThenOnFind = LastNodeOnSpawn->GetThenPin();
				UEdGraphPin* SetVarExecOnFind = SetVarNodeOnFind->GetExecPin();
				LastThenOnFind->MakeLinkTo(SetVarExecOnFind);

				// Connect the new actor to the 'object' pin
				UEdGraphPin* ObjectPinOnFind = SetVarNodeOnFind->FindPinChecked(ObjectParamName);
				CallBeginResult->MakeLinkTo(ObjectPinOnFind);

				// Fill in literal for 'property name' pin - name of pin is property name
				UEdGraphPin* PropertyNamePinOnFind = SetVarNodeOnFind->FindPinChecked(PropertyNameParamName);
				PropertyNamePinOnFind->DefaultValue = SpawnVarPin->PinName.ToString();

				// Move connection from the variable pin on the spawn node to the 'value' pin
				UEdGraphPin* ValuePinOnFind = SetVarNodeOnFind->FindPinChecked(ValueParamName);
				CompilerContext.CopyPinLinksToIntermediate(*ValuePinOnSpawn, *ValuePinOnFind);
				if(SpawnVarPin->PinType.IsArray())
				{
					SetVarNodeOnFind->PinConnectionListChanged(ValuePinOnFind);
				}

				// Update 'last node in sequence' var
				LastNodeOnFind = SetVarNodeOnFind;*/
			}
		}
	}
	// Make exec connection between 'then' on last node and 'finish'
	UEdGraphPin* LastThenOnSpawn = LastNodeOnSpawn->GetThenPin();
	LastThenOnSpawn->MakeLinkTo(CallFinishExec);

	// Get Find End Pin
	UEdGraphPin* LastThenOnFind = LastNodeOnFind->FindPinChecked(UEdGraphSchema_K2::PN_Then);

	// 将Branch节点与 初始化对象属性 执行引脚连接至 InitObject 节点
	CallFinishThen->MakeLinkTo(CallInitObjectExec);
	LastThenOnFind->MakeLinkTo(CallInitObjectExec);

	// Break any links to the expanded node
	BreakAllNodeLinks();
}

void UK2Node_SpawnAndBindActor::ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins)
{
	Super::ReallocatePinsDuringReconstruction(OldPins);

	MaybeUpdateCollisionPin(OldPins);
}

class FNodeHandlingFunctor* UK2Node_SpawnAndBindActor::CreateNodeHandler(
	class FKismetCompilerContext& CompilerContext) const
{
	return new FNodeHandlingFunctor(CompilerContext);
}

void UK2Node_SpawnAndBindActor::GetNodeAttributes(TArray<TKeyValuePair<FString, FString>>& OutNodeAttributes) const
{
	UClass* ClassToSpawn = GetClassToSpawn();
	const FString ClassToSpawnStr = ClassToSpawn ? ClassToSpawn->GetName() : TEXT( "InvalidClass" );
	OutNodeAttributes.Add( TKeyValuePair<FString, FString>( TEXT( "Type" ), TEXT( "SpawnActorFromClass" ) ));
	OutNodeAttributes.Add( TKeyValuePair<FString, FString>( TEXT( "Class" ), GetClass()->GetName() ));
	OutNodeAttributes.Add( TKeyValuePair<FString, FString>( TEXT( "Name" ), GetName() ));
	OutNodeAttributes.Add( TKeyValuePair<FString, FString>( TEXT( "ActorClass" ), ClassToSpawnStr ));
}

void UK2Node_SpawnAndBindActor::CreatePinsForClass(UClass* InClass, TArray<UEdGraphPin*>* OutClassPins)
{
	Super::CreatePinsForClass(InClass, OutClassPins);

	check(InClass != NULL);
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
	// Create Mesh Pin
	UEdGraphPin* MeshPin = nullptr;
	if (InClass == AStaticMeshActor::StaticClass())
	{
		// 添加 StaticMesh 属性引脚
		MeshPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, UStaticMesh::StaticClass(), FK2Node_SpawnAndBindActorHelper::MeshName);
	}
	else if (InClass == ASkeletalMeshActor::StaticClass())
	{
		// 添加 SkeletalMesh 属性引脚
		MeshPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, USkeletalMesh::StaticClass(), FK2Node_SpawnAndBindActorHelper::MeshName);
	}
	if (MeshPin != nullptr)
	{
		K2Schema->ConstructBasicPinTooltip(*MeshPin, LOCTEXT("MeshPinDescription", "Actor Mesh"), MeshPin->PinToolTip);
	}
}

bool UK2Node_SpawnAndBindActor::IsSpawnVarPin(UEdGraphPin* Pin) const
{
	UEdGraphPin* ParentPin = Pin->ParentPin;
	while (ParentPin)
	{
		if (ParentPin->PinName == FK2Node_SpawnAndBindActorHelper::SpawnTransformPinName)
		{
			return false;
		}
		ParentPin = ParentPin->ParentPin;
	}

	return(	Super::IsSpawnVarPin(Pin) &&
			Pin->PinName != FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName &&
			Pin->PinName != FK2Node_SpawnAndBindActorHelper::CollisionHandlingOverridePinName &&
			Pin->PinName != FK2Node_SpawnAndBindActorHelper::SpawnTransformPinName && 
			Pin->PinName != FK2Node_SpawnAndBindActorHelper::OwnerPinName );
}

UClass* UK2Node_SpawnAndBindActor::GetClassPinBaseClass() const
{
	return AActor::StaticClass();
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetSpawnTransformPin() const
{
	UEdGraphPin* Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::SpawnTransformPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetLifetimePin() const
{
	UEdGraphPin* Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::LifetimeName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetActorTagPin() const
{
	UEdGraphPin* Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::ActorTagName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

void UK2Node_SpawnAndBindActor::FixupScaleMethodPin()
{
#if ENGINE_MAJOR_VERSION >= 5
	// if this node is being diffed, don't fix up anything. Keep the legacy pins
	const UPackage* Package = GetPackage();
	if (Package && Package->HasAnyPackageFlags(PKG_ForDiffing))
	{
		return;
	}

	// For the sake of cook determinism, leave the scale method as ESpawnActorScaleMethod::SelectDefaultAtRuntime when cooking.
	// This shouldn't impact runtime behavior.
	if (IsRunningCookCommandlet())
	{
		return;
	}

	if (GetLinkerCustomVersion(FUE5MainStreamObjectVersion::GUID) < FUE5MainStreamObjectVersion::SpawnActorFromClassTransformScaleMethod)
	{
        if (UEdGraphPin* const ScaleMethodPin = TryGetScaleMethodPin())
        {
			const UEdGraphPin* const ClassPin = FindPin(TEXT( "Class" ));
	        const UEnum* const ScaleMethodEnum = StaticEnum<ESpawnActorScaleMethod>();
            if (const UClass* Class = Cast<UClass>(ClassPin->DefaultObject))
            {
            	if (const AActor* ActorCDO = Cast<AActor>(Class->ClassDefaultObject))
                {
                    if (const USceneComponent* Root = ActorCDO->GetRootComponent()) // native root component
                    {
                        ScaleMethodPin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::MultiplyWithRoot));
                    }
                    else
                    {
                        ScaleMethodPin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::OverrideRootScale));
                    }
                }
            }
            else
            {
            	// if the class can't be determined during compile time, defer the default value to runtime
            	ScaleMethodPin->DefaultValue = ScaleMethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorScaleMethod::SelectDefaultAtRuntime));
            }
        }
        else
        {
	        UE_LOG(LogBlueprint, Warning, TEXT("Blueprint Node '%s' is missing '%s' pin. Proceeding as if it's default is SelectDefaultAtRuntime"),
	        	*GetNodeTitle(ENodeTitleType::FullTitle).ToString(),
	        	*FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName.ToString()
	        )
        }
	}
#endif
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetCollisionHandlingOverridePin() const
{
	UEdGraphPin* const Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::CollisionHandlingOverridePinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetScaleMethodPin() const
{
	UEdGraphPin* const Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_SpawnAndBindActor::TryGetScaleMethodPin() const
{
	return FindPin(FK2Node_SpawnAndBindActorHelper::TransformScaleMethodPinName, EGPD_Input);
}

UEdGraphPin* UK2Node_SpawnAndBindActor::GetOwnerPin() const
{
	UEdGraphPin* const Pin = FindPinChecked(FK2Node_SpawnAndBindActorHelper::OwnerPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

void UK2Node_SpawnAndBindActor::MaybeUpdateCollisionPin(TArray<UEdGraphPin*>& OldPins)
{
	// see if there's a bNoCollisionFail pin
	for (UEdGraphPin* Pin : OldPins)
	{
		if (Pin->PinName == FK2Node_SpawnAndBindActorHelper::NoCollisionFailPinName || Pin->PinName == FK2Node_SpawnAndBindActorHelper::SpawnEvenIfCollidingPinName)
		{
			bool bHadOldCollisionPin = true;
			if (Pin->LinkedTo.Num() == 0)
			{
				// no links, use the default value of the pin
				bool const bOldCollisionPinValue = (Pin->DefaultValue == FString(TEXT("true")));

				UEdGraphPin* const CollisionHandlingOverridePin = GetCollisionHandlingOverridePin();
				if (CollisionHandlingOverridePin)
				{
					UEnum const* const MethodEnum = FindObjectChecked<UEnum>(nullptr, TEXT("/Script/Engine.ESpawnActorCollisionHandlingMethod"), true);
					CollisionHandlingOverridePin->DefaultValue =
						bOldCollisionPinValue
						? MethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorCollisionHandlingMethod::AlwaysSpawn))
						: MethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding));
				}
			}
			else
			{
				// something was linked. we will just move the links to the new pin
				// #note: this will be an invalid linkage and the BP compiler will complain, and that's intentional
				// so that users will be able to see and fix issues
				UEdGraphPin* const CollisionHandlingOverridePin = GetCollisionHandlingOverridePin();
				check(CollisionHandlingOverridePin);

				UEnum* const MethodEnum = FindObjectChecked<UEnum>(nullptr, TEXT("/Script/Engine.ESpawnActorCollisionHandlingMethod"), true);
				
				FGraphNodeCreator<UK2Node_EnumLiteral> AlwaysSpawnLiteralCreator(*GetGraph());
				UK2Node_EnumLiteral* const AlwaysSpawnLiteralNode = AlwaysSpawnLiteralCreator.CreateNode();
				AlwaysSpawnLiteralNode->Enum = MethodEnum;
				AlwaysSpawnLiteralNode->NodePosX = NodePosX;
				AlwaysSpawnLiteralNode->NodePosY = NodePosY;
				AlwaysSpawnLiteralCreator.Finalize();
			
				FGraphNodeCreator<UK2Node_EnumLiteral> AdjustIfNecessaryLiteralCreator(*GetGraph());
				UK2Node_EnumLiteral* const AdjustIfNecessaryLiteralNode = AdjustIfNecessaryLiteralCreator.CreateNode();
				AdjustIfNecessaryLiteralNode->Enum = MethodEnum;
				AdjustIfNecessaryLiteralNode->NodePosX = NodePosX;
				AdjustIfNecessaryLiteralNode->NodePosY = NodePosY;
				AdjustIfNecessaryLiteralCreator.Finalize();

				FGraphNodeCreator<UK2Node_Select> SelectCreator(*GetGraph());
				UK2Node_Select* const SelectNode = SelectCreator.CreateNode();
				SelectNode->NodePosX = NodePosX;
				SelectNode->NodePosY = NodePosY;
				SelectCreator.Finalize();

				// find pins we want to set and link up
				auto FindEnumInputPin = [](UK2Node_EnumLiteral const* Node)
				{
					for (UEdGraphPin* NodePin : Node->Pins)
					{
						if (NodePin->PinName == Node->GetEnumInputPinName())
						{
							return NodePin;
						}
					}
					return (UEdGraphPin*)nullptr;
				};

				UEdGraphPin* const AlwaysSpawnLiteralNodeInputPin = FindEnumInputPin(AlwaysSpawnLiteralNode);
				UEdGraphPin* const AdjustIfNecessaryLiteralInputPin = FindEnumInputPin(AdjustIfNecessaryLiteralNode);

				TArray<UEdGraphPin*> SelectOptionPins;
				SelectNode->GetOptionPins(SelectOptionPins);
				UEdGraphPin* const SelectIndexPin = SelectNode->GetIndexPin();

				auto FindResultPin = [](UK2Node const* Node)
				{
					for (UEdGraphPin* NodePin : Node->Pins)
					{
						if (EEdGraphPinDirection::EGPD_Output == NodePin->Direction)
						{
							return NodePin;
						}
					}
					return (UEdGraphPin*)nullptr;
				};
				UEdGraphPin* const AlwaysSpawnLiteralNodeResultPin = FindResultPin(AlwaysSpawnLiteralNode);
				check(AlwaysSpawnLiteralNodeResultPin);
				UEdGraphPin* const AdjustIfNecessaryLiteralResultPin = FindResultPin(AdjustIfNecessaryLiteralNode);
				check(AdjustIfNecessaryLiteralResultPin);

				UEdGraphPin* const OldBoolPin = Pin->LinkedTo[0];
				check(OldBoolPin);

				//
				// now set data and links that we want to set
				//

				AlwaysSpawnLiteralNodeInputPin->DefaultValue = MethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorCollisionHandlingMethod::AlwaysSpawn));
				AdjustIfNecessaryLiteralInputPin->DefaultValue = MethodEnum->GetNameStringByValue(static_cast<int>(ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding));

				OldBoolPin->BreakLinkTo(Pin);
				OldBoolPin->MakeLinkTo(SelectIndexPin);

				AlwaysSpawnLiteralNodeResultPin->MakeLinkTo(SelectOptionPins[0]);
				AdjustIfNecessaryLiteralResultPin->MakeLinkTo(SelectOptionPins[1]);
				
				UEdGraphPin* const SelectOutputPin = SelectNode->GetReturnValuePin();
				check(SelectOutputPin);
				SelectOutputPin->MakeLinkTo(CollisionHandlingOverridePin);

				// tell select node to update its wildcard status
				SelectNode->NotifyPinConnectionListChanged(SelectIndexPin);
				SelectNode->NotifyPinConnectionListChanged(SelectOptionPins[0]);
				SelectNode->NotifyPinConnectionListChanged(SelectOptionPins[1]);
				SelectNode->NotifyPinConnectionListChanged(SelectOutputPin);

			}
		}
	}
}
#undef LOCTEXT_NAMESPACE


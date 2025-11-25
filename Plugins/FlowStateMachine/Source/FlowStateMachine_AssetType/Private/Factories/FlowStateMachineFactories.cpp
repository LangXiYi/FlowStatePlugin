// System Class
#include "ClassViewerModule.h"
#include "KismetCompilerModule.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/SClassPickerDialog.h"
#include "Misc/MessageDialog.h"
// Asset Class
#include "SM/FlowState.h"
#include "SM/FlowStateMachine.h"
#include "Data/FSMMetaDataAsset.h"
// Factory Class
#include "Factories/Factory_FlowState.h"
#include "Factories/Factory_FlowStateData.h"
#include "Factories/Factory_FlowStateMachine.h"
// Class Filter
#include "ClassFilter/FlowStateClassParentFilter.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineFactories"


////////////////////////////////////////////////////////////////////
/// Factory For Flow State Data
////////////////////////////////////////////////////////////////////

UFactory_FlowStateData::UFactory_FlowStateData(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UFSMMetaDataAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFactory_FlowStateData::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UFSMMetaDataAsset::StaticClass()));
	return NewObject<UFSMMetaDataAsset>(InParent, Class, Name, Flags);
}

////////////////////////////////////////////////////////////////////
/// Factory For Flow State
////////////////////////////////////////////////////////////////////

UFactory_FlowState::UFactory_FlowState(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UFlowState::StaticClass();
	ParentClass = UFlowState::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UFactory_FlowState::ConfigureProperties()
{
	// nullptr the FlowStateClass so we can check for selection
	ParentClass = nullptr;

	// Fill in options
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;
	Options.DisplayMode = EClassViewerDisplayMode::TreeView;
	Options.bShowObjectRootClass = true;

	// Only want blueprint actor base classes.
	Options.bIsBlueprintBaseOnly = true;

	// This will allow unloaded blueprints to be shown.
	Options.bShowUnloadedBlueprints = true;

	// Enable Class Dynamic Loading
	Options.bEnableClassDynamicLoading = true;

	Options.NameTypeToDisplay = EClassViewerNameTypeToDisplay::Dynamic;
	
	TSharedPtr<FFlowStateClassParentFilter> Filter = MakeShareable(new FFlowStateClassParentFilter);
	Options.ClassFilter = Filter;

	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists;
	Filter->AllowedChildrenOfClasses.Add(UFlowState::StaticClass());

	const FText TitleText = LOCTEXT("CreateFlowStateOptions", "Pick Flow State Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UFlowState::StaticClass());

	if ( bPressedOk )
	{
		ParentClass = ChosenClass;
	}
	return bPressedOk;
}

UObject* UFactory_FlowState::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	// Make sure we are trying to factory a blueprint, then create and init one
	check(Class->IsChildOf(UFlowState::StaticClass()));

	if ((ParentClass == nullptr) || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass))
	{
		FFormatNamedArguments Args;
		Args.Add( TEXT("ClassName"), (ParentClass != nullptr) ? FText::FromString( ParentClass->GetName() ) : LOCTEXT("Null", "(null)") );
		FMessageDialog::Open( EAppMsgType::Ok, FText::Format( LOCTEXT("CannotCreateBlueprintFromClass", "Cannot create a blueprint based on the class '{0}'."), Args ) );
		return nullptr;
	}
	else
	{
		UClass* BlueprintClass = nullptr;
		UClass* BlueprintGeneratedClass = nullptr;

		IKismetCompilerInterface& KismetCompilerModule = FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler");
		KismetCompilerModule.GetBlueprintTypesForClass(ParentClass, BlueprintClass, BlueprintGeneratedClass);

		return FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BPTYPE_Normal, BlueprintClass, BlueprintGeneratedClass, CallingContext);
	}
}

UObject* UFactory_FlowState::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                              UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

////////////////////////////////////////////////////////////////////
/// Factory For Flow State Machine
////////////////////////////////////////////////////////////////////

UFactory_FlowStateMachine::UFactory_FlowStateMachine(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UFlowStateMachine::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFactory_FlowStateMachine::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(Class->IsChildOf(UFlowStateMachine::StaticClass()));
	return NewObject<UFlowStateMachine>(InParent, Class, Name, Flags);
}

UObject* UFactory_FlowStateMachine::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name,
                                                     EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

#undef LOCTEXT_NAMESPACE
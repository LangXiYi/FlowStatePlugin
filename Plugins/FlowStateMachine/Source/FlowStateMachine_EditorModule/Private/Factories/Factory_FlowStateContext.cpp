// Fill out your copyright notice in the Description page of Project Settings.


#include "Factories/Factory_FlowStateContext.h"

#include "ClassViewerFilter.h"
#include "ClassViewerModule.h"
#include "KismetCompilerModule.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/SClassPickerDialog.h"
#include "SM/FlowStateContext.h"


class FFlowStateContextClassParentFilter : public IClassViewerFilter
{
public:
	/** All children of these classes will be included unless filtered out by another setting. */
	TSet< const UClass* > AllowedChildrenOfClasses;

	/** Disallowed class flags. */
	EClassFlags DisallowedClassFlags = CLASS_None;

	/** Disallow blueprint base classes. */
	bool bDisallowBlueprintBase = false;

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		bool bAllowed= !InClass->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;

		if (bAllowed && bDisallowBlueprintBase)
		{
			if (FKismetEditorUtilities::CanCreateBlueprintOfClass(InClass))
			{
				return false;
			}
		}

		return bAllowed;
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		if (bDisallowBlueprintBase)
		{
			return false;
		}

		return !InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) != EFilterReturn::Failed;
	}
};


#define LOCTEXT_NAMESPACE "Factory_FlowStateContext"

UFactory_FlowStateContext::UFactory_FlowStateContext(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UFlowStateContext::StaticClass();
	ParentClass = UFlowStateContext::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


bool UFactory_FlowStateContext::ConfigureProperties()
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
	
	TSharedPtr<FFlowStateContextClassParentFilter> Filter = MakeShareable(new FFlowStateContextClassParentFilter);
	Options.ClassFilter = Filter;

	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists;
	Filter->AllowedChildrenOfClasses.Add(UFlowStateContext::StaticClass());

	const FText TitleText = LOCTEXT("CreateFlowStateOptions", "Pick Flow State Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UFlowStateContext::StaticClass());

	if ( bPressedOk )
	{
		ParentClass = ChosenClass;
	}
	return bPressedOk;
}

UObject* UFactory_FlowStateContext::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	// Make sure we are trying to factory a blueprint, then create and init one
	check(Class->IsChildOf(UFlowStateContext::StaticClass()));

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

UObject* UFactory_FlowStateContext::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                              UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

#undef LOCTEXT_NAMESPACE
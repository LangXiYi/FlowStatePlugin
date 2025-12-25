// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "CoreMinimal.h"
#include "FlowStateMachineEditorTypes.h"
#include "Widgets/Layout/SBorder.h"

class SGraphActionMenu;
class UFSMGraphNode;

class FLOWSTATEMACHINE_EDITOR_API SGraphEditorActionMenu_FSM: public SBorder
{
public:
	SLATE_BEGIN_ARGS(SGraphEditorActionMenu_FSM):
		 _GraphObj( static_cast<UEdGraph*>(NULL) )
		,_GraphNode(NULL)
		, _NewNodePosition( FVector2D::ZeroVector )
		, _AutoExpandActionMenu( false )
		, _SubNodeFlags(EFSMSubNodeType::None)
	{}
		SLATE_ARGUMENT(UEdGraph*, GraphObj)
		SLATE_ARGUMENT(UFSMGraphNode*, GraphNode)
		SLATE_ARGUMENT( FVector2D, NewNodePosition )
		SLATE_ARGUMENT( TArray<UEdGraphPin*>, DraggedFromPins )
		SLATE_ARGUMENT( SGraphEditor::FActionMenuClosed, OnClosedCallback )
		SLATE_ARGUMENT( bool, AutoExpandActionMenu )
		SLATE_ARGUMENT( EFSMSubNodeType, SubNodeFlags)
	SLATE_END_ARGS();

	void Construct( const FArguments& InArgs );

	~SGraphEditorActionMenu_FSM();
	
	TSharedRef<SEditableTextBox> GetFilterTextBox();

protected:
	UEdGraph* GraphObj;
	UFSMGraphNode* GraphNode;
	TArray<UEdGraphPin*> DraggedFromPins;
	FVector2D NewNodePosition;
	bool AutoExpandActionMenu;
	EFSMSubNodeType SubNodeFlags;

	SGraphEditor::FActionMenuClosed OnClosedCallback;
	TSharedPtr<SGraphActionMenu> GraphActionMenu;

	void OnActionSelected( const TArray< TSharedPtr<FEdGraphSchemaAction> >& SelectedAction, ESelectInfo::Type InSelectionType );

	/** Callback used to populate all actions list in SGraphActionMenu */
	void CollectAllActions(FGraphActionListBuilderBase& OutAllActions);
};
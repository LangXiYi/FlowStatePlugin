#include "FlowStateMachineEditor.h"

#include "BlueprintEditorModes.h"
#include "FlowStateMachineEditorApplicationMode.h"
#include "SM/FlowStateMachine.h"


FName const FFlowStateMachineEditor::FlowStateMachineMode = FName("FlowStateMachine");

void FFlowStateMachineEditor::InitFlowStateMachineEditor(EToolkitMode::Type Mode,
	const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject)
{
	UFlowStateMachine* FlowStateMachineInEditor = Cast<UFlowStateMachine>(InObject);

	if (FlowStateMachineInEditor != nullptr)
	{
		FlowStateMachine = FlowStateMachineInEditor;
	}
	// 将目标添加到待编辑列表
	TArray<UObject*> ObjectsToEdit;
	if (FlowStateMachine != nullptr)
	{
		ObjectsToEdit.Add(FlowStateMachine);
	}
	
	// todo:: Register Document Factories


	// if we are already editing objects, dont try to recreate the editor from scratch but update the list of objects in edition
	// ex: BehaviorTree may want to reuse an editor already opened for its associated Blackboard asset.
	const TArray<UObject*>* EditedObjects = GetObjectsCurrentlyBeingEdited();
	if (EditedObjects == nullptr || EditedObjects->Num() == 0)
	{
		// Add Application Mode
		AddApplicationMode(FlowStateMachineMode, MakeShareable(new FFlowStateMachineEditorApplicationMode(SharedThis(this))));
		// AddApplicationMode(FFlowStateMachineEditorModeHelper::BlueprintMode, MakeShareable(new FBlueprintEditorApplicationMode()));
	}
	else
	{
		for (UObject* ObjectToEdit : ObjectsToEdit)
		{
			if (!EditedObjects->Contains(ObjectToEdit))
			{
				AddEditingObject(ObjectToEdit);
			}
		}
	}
	//
	if(FlowStateMachine != nullptr)
	{
		SetCurrentMode(FlowStateMachineMode);
	}

	// OnClassListUpdated();
	RegenerateMenusAndToolbars();
}

void FFlowStateMachineEditor::SaveEditedObjectState()
{
	// todo::Save Object State
}

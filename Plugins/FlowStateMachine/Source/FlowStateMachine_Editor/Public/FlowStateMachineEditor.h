#pragma once
#include "IFlowStateMachineEditor.h"

class UFlowStateMachine;




class FFlowStateMachineEditor: public IFlowStateMachineEditor
{
public:
	FFlowStateMachineEditor():
		FlowStateMachine(nullptr)
	{
		
	}
	
	void InitFlowStateMachineEditor(EToolkitMode::Type Mode,
		const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);

	void SaveEditedObjectState();

public:
	static FName const FlowStateMachineMode; 
	
private:
	UFlowStateMachine* FlowStateMachine;
};

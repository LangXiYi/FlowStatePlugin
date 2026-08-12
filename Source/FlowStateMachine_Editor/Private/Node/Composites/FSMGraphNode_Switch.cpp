// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Composites/FSMGraphNode_Switch.h"

void UFSMGraphNode_Switch::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "ExecutePin", TEXT("Execute"));
	CreatePin(EGPD_Output, "ThenPin", TEXT("Then"));

	// 参数引脚 ？ 还是直接通过细节面板绑定？
	/*FCreatePinParams ArgsPinParams;
	// ArgsPinParams.ValueTerminalType;
	CreatePin(EGPD_Input, "ArgsPin", TEXT("Value"), ArgsPinParams);*/
}

FPinConnectionResponse UFSMGraphNode_Switch::CheckPinConnection(const UFSMGraphNodeBase* OtherNode,
	EEdGraphPinDirection FromDirection) const
{
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, "connect node and break all");
}


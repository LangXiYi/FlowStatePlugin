#pragma once
#include "Utility/FlowStateEditorHelper.h"

#include "Utility/FlowStateEditorCore.h"

USING_FLOWSTATE_EDITORHELPER

// Pin Helper Begin
const FName FPinHelper::InPut_DefaultPinName  = FName(TEXT("Execute"));
const FName FPinHelper::Output_DefaultPinName = FName(TEXT("Then"));
const FName FPinHelper::Input_PinCategory     = FName(TEXT("Then"));
const FName FPinHelper::Output_PinCategory    = FName(TEXT("ThenPin"));
// Pin Helper End~

// Editor Helper Begin
const FName FEditorHelper::FlowStateMachineAppIdentifier = FName(TEXT("FlowStateMachineEditor"));
const FName FEditorHelper::FlowStateMachineMode          = FName(TEXT("FlowStateMachine"));
const FName FEditorHelper::CommonDataMode                = FName(TEXT("CommonData"));
// Editor Helper End~

// TabSummoner Helper Begin
const FName FTabSummonerHelper::GraphDetailsID  = FName(TEXT("FSMEditorTab_GraphDetails"));
const FName FTabSummonerHelper::GraphNodeListID = FName(TEXT("FSMEditorTab_GraphNodeList"));
const FName FTabSummonerHelper::SearchID        = FName(TEXT("FSMEditorTab_Search"));

const FName FTabSummonerHelper::CommonDataEditorID  = FName(TEXT("FSMEditorTab_CommonDataEditor"));
const FName FTabSummonerHelper::CommonDataDetailsID = FName(TEXT("FSMEditorTab_CommonDataDetails"));

const FName FTabSummonerHelper::GraphEditorID = FName(TEXT("Document"));
// TabSummoner Helper End~
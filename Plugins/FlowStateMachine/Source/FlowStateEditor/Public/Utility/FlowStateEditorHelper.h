#pragma once

#define USING_FLOWSTATE_EDITORHELPER using namespace FSEH;
#define BEGIN_FLOWSTATE_EDITORHELPER namespace FSEH{
#define END_FLOWSTATE_EDITORHELPER }

/*******************************************************************************
 * 这些帮助类型不需要被外部访问，所以使用命名空间包裹可简化名称，并保证不会污染外部环境
 ******************************************************************************/

BEGIN_FLOWSTATE_EDITORHELPER

/**
 * 引脚辅助类
 * 内部定义了常用的节点引脚名称以及它们的分类
 */
struct FPinHelper
{
    static const FName Input_PinCategory;
    static const FName Output_PinCategory;

    static const FName InPut_DefaultPinName;
    static const FName Output_DefaultPinName;
};

/**
 * 编辑器辅助类
 */
struct FEditorHelper 
{
    static const FName FlowStateMachineAppIdentifier;
    static const FName FlowStateMachineMode;
    static const FName CommonDataMode;
};

/**
 * 标签页辅助类
 * 内部定义了不同标签页的唯一标识符
 */
struct FTabSummonerHelper
{
    // Tab Identifiers
    static const FName GraphDetailsID;
    static const FName GraphNodeListID;
    static const FName SearchID;

    // Common Data Tab
    static const FName CommonDataID;
    static const FName CommonDataEditorID;
    static const FName CommonDataDetailsID;

    // Document Tab Identifiers
    static const FName GraphEditorID;
};

END_FLOWSTATE_EDITORHELPER
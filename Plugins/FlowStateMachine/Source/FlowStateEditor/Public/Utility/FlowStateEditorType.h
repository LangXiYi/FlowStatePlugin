#pragma once

#define USING_FLOWSTATE_EDITORTYPE using namespace FSET;
#define BEGIN_FLOWSTATE_EDITORTYPE namespace FSET {
#define END_FLOWSTATE_EDITORTYPE }

/*******************************************************************************
 * 这些类型不需要被外部访问，所以使用命名空间包裹可简化名称，并保证不会污染外部环境
 ******************************************************************************/

BEGIN_FLOWSTATE_EDITORTYPE
    enum class ESubNodeType : uint8
    {
        None = 0,
        Condition,
        Action,
        Service,
    };

END_FLOWSTATE_EDITORTYPE

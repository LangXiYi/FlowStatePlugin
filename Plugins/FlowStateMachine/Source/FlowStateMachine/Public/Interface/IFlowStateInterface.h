#pragma once


/*
 * 状态机可以切换状态至另一个状态机
 * 状态机会根据链式结构遍历执行条件
 * 
 */

class UFlowState;
class UFlowStateContext;
class UFlowStateLayoutWidget;

class IFlowStateInterface
{
public:
	IFlowStateInterface() = default;
	virtual ~IFlowStateInterface() = default;
	
	/** 当初始化状态时触发该函数 */
	virtual void OnInitialize(UFlowStateContext* Context) = 0;
	/** 在初始化状态前调用该函数 */
	virtual void OnPreInitialize(UFlowState* LastState) = 0;
	/** 当初始化状态后触发该函数 */
	virtual void OnPostInitialize() = 0;

	/** 当进入状态时触发该函数 */
	virtual void OnEnter() = 0;
	/** 当退出状态时触发该函数 */
	virtual void OnExit() = 0;

	/** 初始化状态控件 */
	virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) = 0;

	/** 检查过度条件 */
	virtual bool CheckCondition() const = 0;
};

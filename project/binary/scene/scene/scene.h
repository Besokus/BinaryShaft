#pragma once

/*
	负责人:ja1u0va
	功能:
		1.实现特定场景的功能
		2.具有
			1.Enter    进入界面,需要重置一些数值的状态
			2.Input    接受玩家输入信息
			3.Update   根据玩家输入的信息,更新数据
			4.Draw     绘制画面
	示例:



*/

#include <graphics.h>

class Scene
{
private:

public:
	Scene() = default;
	~Scene() = default;

	// 虚函数,用于继承,基类模板
	// 进入界面方法
	virtual void OnEnter() {}
	// 刷新界面方法
	virtual void OnUpdate() {}
	// 绘制界面方法
	virtual void OnDraw() {}
	// 接受玩家输入方法
	virtual void OnInput(const ExMessage& msg) {}
	// 退出方法
	virtual void OnExit() {}

};
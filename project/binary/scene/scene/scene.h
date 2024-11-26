#pragma once

/*
	负责人:ja1u0va
	功能:
		1.
		2.
	示例:
		1.



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
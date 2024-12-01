#pragma once

/*
未完成：
	背景图的选择
	通关时打印玩家分数、耗时等信息
	下一关按钮的跳转功能的具体实现和配图






*/

#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../button/win_butoon/win_button.h"
#include <iostream>	

class WinScene :public Scene
{

private:

public:
	WinScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};

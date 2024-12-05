#pragma once
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "easyx.h"
#include <iostream>

/*
	游戏说明界面
	负责人：Besokus
	功能：
		1.根据需求文档制作内容，填充素材
*/

class ShowDetailScene : public Scene
{

private:
	bool is_A_down = false;
	bool is_D_down = false;
	int page = 0;
	const int PAGE_SUM = 10;

public:
	ShowDetailScene() = default;
	~ShowDetailScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
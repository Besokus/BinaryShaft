#pragma once
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include"../../button/achievement_button/achievement_button.h"
#include <iostream>	

/*
成就界面
	负责人：minato
	功能：根据需求文档，完成功能，填充素材
*/

class AchievementScene :public Scene
{
private:
	const int PAGE_NUM = 20;
	bool is_A_down = false;
	bool is_D_down = false;
	int current_page = 0;
public:
	AchievementScene() = default;
	~AchievementScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

};
#pragma once
#include "../scene/scene.h"

/*
成就界面
	负责人：minato
	功能：根据需求文档，完成功能，填充素材
*/

class AchieveScene :public Scene
{
private:

public:
	AchieveScene() = default;
	~AchieveScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

};
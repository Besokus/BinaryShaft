#pragma once
#include "../scene/scene.h"

/*
死亡界面
负责人：阿氟
*/

class DeathScene :public Scene
{
private:

public:
	DeathScene() = default;
	~DeathScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);
};
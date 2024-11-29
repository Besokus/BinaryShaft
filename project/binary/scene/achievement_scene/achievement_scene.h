#pragma once
#include "../scene/scene.h"

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
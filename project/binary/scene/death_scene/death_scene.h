#pragma once
#include "../scene/scene.h"

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

	int GetPlayerScore();
};
#pragma once

/*
	负责人:
	功能:
		1.
		2.
	示例:
		1.

*/

#include "../scene/scene.h"
#include <iostream>

class GameScene :public Scene
{
private:

public:
	GameScene() = default;
	~GameScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();
};
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
#include "../../platform/platform/platform.h"
#include <iostream>
#include <vector>

class GameScene :public Scene
{
private:

public:
	GameScene() = default;
	~GameScene() = default;

	void GeneratePlatform(std::vector<Platform*>& platform_list);

	void DeletePlatform(std::vector<Platform*>& platform_list);

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();
};
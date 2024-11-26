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
#include "../scene_manager/scene_manager.h"
#include <iostream>

class MenuScene :public Scene
{

private:

public:
	MenuScene() = default;
	~MenuScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
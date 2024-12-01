#pragma once
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include <iostream>	
class ShowUsScene :public Scene
{
private:

public:
	ShowUsScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};


#pragma once

#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
//#include "../../button/select_mode_button/select_mode_button.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <easyx.h>
#include <string.h>

class SelectModeScene : public Scene
{
public:
	SelectModeScene() = default;
	~SelectModeScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
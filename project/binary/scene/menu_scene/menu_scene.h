#pragma once

/*
	������:
	����:
		1.
		2.
	ʾ��:
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
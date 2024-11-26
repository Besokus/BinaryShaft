#pragma once

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

class SetUpScene :public Scene
{

private:

public:
	SetUpScene() = default;
	~SetUpScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
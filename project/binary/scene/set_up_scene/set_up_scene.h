#pragma once

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
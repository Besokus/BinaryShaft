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

class PauseScene :public Scene
{

private:

public:
	PauseScene() = default;
	~PauseScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
#pragma once

/*

*/
#include "../scene/scene.h"


class SelectLevelScene :public Scene
{

private:
	bool is_A_down = false;
	bool is_D_down = false;
	bool is_enter_down = false;
	bool is_esc_down = false;
public:
	SelectLevelScene() = default;
	~SelectLevelScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();


};
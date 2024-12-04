#pragma once

/*

*/
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "easyx.h"
#include <iostream>
#include "../../data.h"
#include <vector>



class RankScene :public Scene
{

private:
	bool is_A_down = false;
	bool is_D_down = false;
public:
	RankScene() = default;
	~RankScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();


};
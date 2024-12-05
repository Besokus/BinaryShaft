#pragma once

#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "easyx.h"
#include <iostream>
#include "../../data.h"
#include <vector>

extern int level;

class RankScene :public Scene
{

private:
	struct RankDetail
	{
		int score = 0;
		char name[12] = "xcpcer";
	};

	bool is_A_down = false;
	bool is_D_down = false;

	int page = 0;
	const int PAGE_SUM = 10;

	vector<RankDetail>rank[11];

public:
	RankScene() = default;
	~RankScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();


};
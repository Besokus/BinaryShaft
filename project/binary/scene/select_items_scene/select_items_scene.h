#pragma once


#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../map/map.h"
#include <iostream>	
#include<vector>

class SelectItemsScene :public Scene
{

private:
	int items_num;   //记录玩家选择的道具数
	std::vector<bool>* items = &map_massage[10].item_choice;
public:
	SelectItemsScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};

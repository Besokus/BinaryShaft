#pragma once

#include "../scene/scene.h"
#include "../../platform/platform/platform.h"
#include"../../map/map.h"
#include "../../items/item/item.h"
#include <iostream>
#include <vector>

extern int level;
class item;
class Platform;
class Player;
class Map_Msg;

class GameScene :public Scene
{
private:

public:
	//关卡信息
	Map_Msg* map_msg = nullptr;
	Player* player = nullptr;
	//道具信息
	std::vector<item*> item_list;
	item* current_item = nullptr;
	int current_item_num = 0;
public:
	GameScene() = default;
	~GameScene() = default;

	void GeneratePlatform(std::vector<Platform*>& platform_list);

	void DeletePlatform(std::vector<Platform*>& platform_list);

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();
};
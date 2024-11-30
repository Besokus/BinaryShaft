#pragma once
#include "../../player/player.h"
#include "../../scene/game_scene/game_scene.h"
#include"../../map/map.h"

class item
{
protected:
	int time_keeper;//计时器
	int cd;//道具cd
	int duration;//道具持续时间
	bool is_cding;//是否在cd中
	bool istriggered;//是否被使用
	Player* player;
	Map_Msg* map_msg;
public:
	item() = default;
	~item() = default;

	void OnUpdate();

	virtual void OnDarw() = 0;

	virtual void triggering() = 0;

	virtual void end_trigger() = 0;
};

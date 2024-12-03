#pragma once
#include "../../player/player.h"
#include "../../scene/game_scene/game_scene.h"
#include"../../map/map.h"

class Map_Msg;
class Player;
extern IMAGE image_item_carefully_BBQ;
extern IMAGE image_item_ctrl_Z;
extern IMAGE image_item_helpme_awei;
extern IMAGE image_item_hiraijin;
extern IMAGE image_item_once_again;
extern IMAGE image_item_the_world;

class item
{
protected:
	int id;//道具id
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

	int get_id()
	{
		return id;
	}

	bool is_ready()
	{
		return !istriggered && !is_cding;
	}

	void OnInput(const ExMessage& msg);

	void DrawBlackOverlay(int x, int y, int width, int height, float overlay_ratio);

	virtual void OnUpdate();

	virtual void OnDarw() = 0;

	virtual void triggering() = 0;

	virtual void end_trigger() = 0;
};

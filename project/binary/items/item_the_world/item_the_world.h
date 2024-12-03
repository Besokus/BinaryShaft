#pragma once
#include"../item/item.h"

class item_the_world :public item
{
public:
	float memory_speed = 0;

	item_the_world(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

#pragma once
#include"../item/item.h"

class item_hiraijin :public item
{
public:
	int trigger_time = 0;
	float memory_x = 0, memory_y = 0;

	item_hiraijin(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

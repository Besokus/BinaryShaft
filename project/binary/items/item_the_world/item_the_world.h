#pragma once
#include"../item/item.h"

class item_the_world :public item
{
public:
	item_the_world(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

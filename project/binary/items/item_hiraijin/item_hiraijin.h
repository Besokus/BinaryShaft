#pragma once
#include"../item/item.h"

class item_hiraijin :public item
{
public:
	item_hiraijin(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

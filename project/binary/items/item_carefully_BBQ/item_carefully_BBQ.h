#pragma once
#include"../item/item.h"

class item_carefully_BBQ :public item
{
public:
	item_carefully_BBQ(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

#pragma once
#include"../item/item.h"

class item_helpme_awei :public item
{
public:
	item_helpme_awei(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};

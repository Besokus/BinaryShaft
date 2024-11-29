#pragma once
#include"../item/item.h"

class item_ctrl_Z :public item
{
public:
	item_ctrl_Z(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();
};
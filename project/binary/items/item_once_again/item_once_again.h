#pragma once
#include"../item/item.h"

class item_once_again :public item
{
public:
	item_once_again(Player* player, Map_Msg* map_msg);

	void OnDarw();

	void triggering();

	void end_trigger();

	void OnUpdate();
};

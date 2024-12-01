#pragma once
#include "../platform/platform.h"

class bounce_Platform :public Platform
{
public:
	bounce_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：土豆
	功能：
		1.玩家向上的速度修改为20
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};
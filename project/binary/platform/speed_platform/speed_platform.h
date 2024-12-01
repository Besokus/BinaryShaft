#pragma once
#include "../platform/platform.h"

class speed_Platform :public Platform
{
public:
	speed_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：
	功能：
		1.玩家向右的速度 + 1.0
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};

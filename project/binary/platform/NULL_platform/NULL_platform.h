#pragma once
#include "../platform/platform.h"

class NULLPlatform :public Platform
{
public:
	NULLPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：
	功能：
		1.无事发生，不用写
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};
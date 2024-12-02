#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class WAPlatform :public Platform
{
public:
	WAPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：涵
	功能：
		1.改变贴图为NULL
		2.玩家血量-1，分数-4，通过标记使只能触发一次
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		
	}
};
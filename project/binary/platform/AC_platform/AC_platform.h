#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class ACPlatform :public Platform
{
public:
	ACPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：土豆
	功能：
		1.修改贴图为NULL平台
		2.修改map_msg的分数，direction为0分数+3，否则+6，并且血量+1，通过标记使只能触发一次
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		if (is_visited) 
		{
			img_platform = img_NULL_platform;
		}
	}
};
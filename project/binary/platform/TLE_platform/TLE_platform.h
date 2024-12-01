#pragma once
#include "../platform/platform.h"

class TLEPlatform :public Platform
{
public:
	TLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：
	功能：
		1.分数-2，修改地图speed的大小，增加0.2
		2.如果方向不为0，缩小0.2的速度，不低于0.6
		3.修改贴图为NULL，通过标记，以上两个效果总共只触发一次（不是两个各一次，只有一次）
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		if (is_visited)
		{

		}
	}
};
#pragma once
#include "../platform/platform.h"

class MLEPlatform :public Platform
{
public:
	MLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：土豆
	功能：
		1.分数-2，修改地图limit的范围，左右各缩小10
		2.如果方向不为0，则增大地图范围，左右各10，不超过（0，550）
		3.修改贴图为NULL，通过标记，以上两个效果总共只触发一次（不是两个各一次，只有一次）
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};


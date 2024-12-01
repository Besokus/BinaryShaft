#pragma once
#include "../platform/platform.h"

class CEPlatform :public Platform
{
public:
	CEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：土豆
	功能：
		1.如果direction为0， 游戏失败，修改玩家血量为0
		2.如果不为0，回满玩家的血量
		3.通过标记，以上两个效果只总共触发一次
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		
	}
};
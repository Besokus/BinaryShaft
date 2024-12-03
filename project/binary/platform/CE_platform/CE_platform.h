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
		4.修改贴图为null
	*/
	//触发标记
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//检验标记
		if (is_platform == false)
		{
			if (is_visited)
			{
				//修改贴图为NULL
				img_platform = img_NULL_platform;
				//如果direction为0修改玩家血量为0,否则回满玩家的血量
				if (direction)
					player->health = 12;
				else
					player->health = 0;
				//通过标记使只能触发一次
				is_platform = true;
			}
		}
	}
};
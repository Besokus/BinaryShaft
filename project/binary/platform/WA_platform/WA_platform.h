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
	//触发标记
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//检验标记
		if (is_platform == false)
		{
			mciSendString(_T("play resources/受伤.mp3 from 0"), NULL, 0, NULL);
			if (is_visited)
			{
				//修改贴图为NULL
				img_platform = img_NULL_platform;
				if (!direction)
				{				
					//玩家血量-1，分数-4
					map_msg->score -= 4;
					if(player->health>0)
					player->health -= 1;
				}
				else
				{
					if(player->health<12)
					player->health += 1;
				}
				//通过标记使只能触发一次
				is_platform = true;
			}
		}
	}
};
#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

extern Data* current_data;

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

	// 触发标记
	bool is_platform = false;

	void PlatformChange(Player* player, int direction = 0)
	{
		// 检验标记
		if (is_platform == false)
		{
			if (is_visited)
			{
				// 音乐播放
				mciSendString(_T("play resources/Ac音效.mp3 from 0"), NULL, 0, NULL);

				// 计数
				current_data->num_AC++;

				// 修改贴图为NULL
				img_platform = img_NULL_platform;
				// direction为1分数+6并且血量加一，否则分数+3
				if (direction)
				{
					map_msg->score += 6;
					player->health += 1;
				}
				else
					map_msg->score += 3;
				// 通过标记使只能触发一次
				is_platform = true;
			}
		}
	}
};
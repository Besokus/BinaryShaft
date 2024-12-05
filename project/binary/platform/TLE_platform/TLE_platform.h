#pragma once
#include "../platform/platform.h"

extern Data* current_data;

class TLEPlatform :public Platform
{
public:
	TLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：涵
	功能：
		1.分数-2，修改地图speed的大小，增加0.2
		2.如果方向不为0，缩小0.2的速度，不低于0.6
		3.修改贴图为NULL，通过标记，以上两个效果总共只触发一次（不是两个各一次，只有一次）
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
				current_data->num_TLE++;

				//修改贴图为NULL
				img_platform = img_NULL_platform;
				//如果为0分数-2，修改地图speed的大小，增加0.2
				if (!direction)
				{
					map_msg->score -= 2;
					map_msg->speed += 0.2f;
					map_msg->real_speed += 0.2f;
					player->velocity.y -= 0.2f;
				}
				//如果不为0缩小0.2的速度，不低于0.6
				else
				{
					map_msg->score += 2;
					if (map_msg->real_speed >= 0.8)
					{
						map_msg->speed -= 0.2f;
						map_msg->real_speed -= 0.2f;
					}
					else
					{
						map_msg->speed = 0.6f;
						map_msg->real_speed = 0.6f;
					}
				}
				//通过标记使只能触发一次
				is_platform = true;
			}
		}
	}
};
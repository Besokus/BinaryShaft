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
		2.如果direction不为0，则增大地图范围，左右各10，不超过（0，550）
		3.修改贴图为NULL，通过标记，以上两个效果总共只触发一次（不是两个各一次，只有一次）
	*/
	//触发标记
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//检验标记
		if (is_platform == false)
		{
			//修改贴图为NULL
			img_platform = img_NULL_platform;
			//如果为0修改地图limit的范围，左右各缩小10否则加10不超过（0，550）
			if (direction)
			{
				if (map_msg->left_limit >= 10)
				{
					map_msg->left_limit -= 20;
					map_msg->right_limit += 20;
					//分数+1
					map_msg->score += 1;
				}
			}
			else
			{
				if (map_msg->left_limit <= map_msg->right_limit)
				{
					map_msg->left_limit += 20;
					map_msg->right_limit -= 20;
					//分数-2
					map_msg->score -= 2;
				}
			}
			//通过标记使只能触发一次
			is_platform = true;
		}
	}
};


#pragma once
#include "../platform/platform.h"

class bounce_Platform :public Platform
{
public:
	bounce_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	负责人：土豆
	功能：
		1.direction = 1玩家y轴的速度修改为10(下为正
		2.否则玩家y轴的速度修改为-10
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		mciSendString(_T("play resources/跳跃音效.mp3 from 0"), NULL, 0, NULL);

		if (is_visited) {
			if (direction) {
				//玩家y轴的速度修改为10
				player->velocity.y = 10;
			}
			else {
				//玩家y轴的速度修改为-15
				player->velocity.y = -15;
				player->is_on_platform = false;
				player->down_platform = nullptr;
			}
		}
	}
};
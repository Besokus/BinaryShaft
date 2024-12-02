#pragma once
#include "../platform/platform.h"

class bounce_Platform :public Platform
{
public:
	bounce_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�����
	���ܣ�
		1.direction = 1���y����ٶ��޸�Ϊ10(��Ϊ��
		2.�������y����ٶ��޸�Ϊ-10
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		if (is_visited) {
			if (direction) {
				//���y����ٶ��޸�Ϊ10
				player->velocity.y = 10;
			}
			else {
				//���y����ٶ��޸�Ϊ-10
				player->velocity.y = -20;
				player->is_on_platform = false;
				player->down_platform = nullptr;
			}
		}
	}
};
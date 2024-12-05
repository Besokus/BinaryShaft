#pragma once
#include "../platform/platform.h"

extern Data* current_data;

class speed_Platform :public Platform
{
public:
	speed_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ���
	���ܣ�
		1.������ҵ��ٶ� + 1.0
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		current_data->num_speed++;

		player->position.x+=2;
	}
};

#pragma once
#include "../platform/platform.h"

class bounce_Platform :public Platform
{
public:
	bounce_Platform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�����
	���ܣ�
		1.������ϵ��ٶ��޸�Ϊ20
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};
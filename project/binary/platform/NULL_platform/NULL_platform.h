#pragma once
#include "../platform/platform.h"

class NULLPlatform :public Platform
{
public:
	NULLPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�
	���ܣ�
		1.���·���������д
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};
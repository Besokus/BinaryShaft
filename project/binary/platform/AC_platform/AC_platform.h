#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class ACPlatform :public Platform
{
public:
	ACPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�����
	���ܣ�
		1.�޸���ͼΪNULLƽ̨
		2.�޸�map_msg�ķ�����directionΪ0����+3������+6������Ѫ��+1��ͨ�����ʹֻ�ܴ���һ��
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		if (is_visited) 
		{
			img_platform = img_NULL_platform;
		}
	}
};
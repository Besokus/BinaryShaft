#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class WAPlatform :public Platform
{
public:
	WAPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ���
	���ܣ�
		1.�ı���ͼΪNULL
		2.���Ѫ��-1������-4��ͨ�����ʹֻ�ܴ���һ��
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		
	}
};
#pragma once
#include "../platform/platform.h"

class TLEPlatform :public Platform
{
public:
	TLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�
	���ܣ�
		1.����-2���޸ĵ�ͼspeed�Ĵ�С������0.2
		2.�������Ϊ0����С0.2���ٶȣ�������0.6
		3.�޸���ͼΪNULL��ͨ����ǣ���������Ч���ܹ�ֻ����һ�Σ�����������һ�Σ�ֻ��һ�Σ�
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		if (is_visited)
		{

		}
	}
};
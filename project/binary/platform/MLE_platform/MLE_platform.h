#pragma once
#include "../platform/platform.h"

class MLEPlatform :public Platform
{
public:
	MLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�����
	���ܣ�
		1.����-2���޸ĵ�ͼlimit�ķ�Χ�����Ҹ���С10
		2.�������Ϊ0���������ͼ��Χ�����Ҹ�10����������0��550��
		3.�޸���ͼΪNULL��ͨ����ǣ���������Ч���ܹ�ֻ����һ�Σ�����������һ�Σ�ֻ��һ�Σ�
	*/
	void PlatformChange(Player* player, int direction = 0)
	{

	}
};


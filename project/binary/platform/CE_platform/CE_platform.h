#pragma once
#include "../platform/platform.h"

class CEPlatform :public Platform
{
public:
	CEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ�����
	���ܣ�
		1.���directionΪ0�� ��Ϸʧ�ܣ��޸����Ѫ��Ϊ0
		2.�����Ϊ0��������ҵ�Ѫ��
		3.ͨ����ǣ���������Ч��ֻ�ܹ�����һ��
	*/
	void PlatformChange(Player* player, int direction = 0)
	{
		
	}
};
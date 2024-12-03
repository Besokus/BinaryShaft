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
		4.�޸���ͼΪnull
	*/
	//�������
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//������
		if (is_platform == false)
		{
			if (is_visited)
			{
				//�޸���ͼΪNULL
				img_platform = img_NULL_platform;
				//���directionΪ0�޸����Ѫ��Ϊ0,���������ҵ�Ѫ��
				if (direction)
					player->health = 12;
				else
					player->health = 0;
				//ͨ�����ʹֻ�ܴ���һ��
				is_platform = true;
			}
		}
	}
};
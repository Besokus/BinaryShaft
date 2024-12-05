#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

extern Data* current_data;

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

	// �������
	bool is_platform = false;

	void PlatformChange(Player* player, int direction = 0)
	{
		// ������
		if (is_platform == false)
		{
			if (is_visited)
			{
				// ���ֲ���
				mciSendString(_T("play resources/Ac��Ч.mp3 from 0"), NULL, 0, NULL);

				// ����
				current_data->num_AC++;

				// �޸���ͼΪNULL
				img_platform = img_NULL_platform;
				// directionΪ1����+6����Ѫ����һ���������+3
				if (direction)
				{
					map_msg->score += 6;
					player->health += 1;
				}
				else
					map_msg->score += 3;
				// ͨ�����ʹֻ�ܴ���һ��
				is_platform = true;
			}
		}
	}
};
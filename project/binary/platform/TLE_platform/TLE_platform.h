#pragma once
#include "../platform/platform.h"

extern Data* current_data;

class TLEPlatform :public Platform
{
public:
	TLEPlatform(IMAGE img_platform, Map_Msg* map_msg) :Platform(img_platform, map_msg) {}
	/*
	�����ˣ���
	���ܣ�
		1.����-2���޸ĵ�ͼspeed�Ĵ�С������0.2
		2.�������Ϊ0����С0.2���ٶȣ�������0.6
		3.�޸���ͼΪNULL��ͨ����ǣ���������Ч���ܹ�ֻ����һ�Σ�����������һ�Σ�ֻ��һ�Σ�
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
				current_data->num_TLE++;

				//�޸���ͼΪNULL
				img_platform = img_NULL_platform;
				//���Ϊ0����-2���޸ĵ�ͼspeed�Ĵ�С������0.2
				if (!direction)
				{
					map_msg->score -= 2;
					map_msg->speed += 0.2f;
					map_msg->real_speed += 0.2f;
					player->velocity.y -= 0.2f;
				}
				//�����Ϊ0��С0.2���ٶȣ�������0.6
				else
				{
					map_msg->score += 2;
					if (map_msg->real_speed >= 0.8)
					{
						map_msg->speed -= 0.2f;
						map_msg->real_speed -= 0.2f;
					}
					else
					{
						map_msg->speed = 0.6f;
						map_msg->real_speed = 0.6f;
					}
				}
				//ͨ�����ʹֻ�ܴ���һ��
				is_platform = true;
			}
		}
	}
};
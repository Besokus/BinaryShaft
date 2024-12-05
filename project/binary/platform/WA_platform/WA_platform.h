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
	//�������
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//������
		if (is_platform == false)
		{
			mciSendString(_T("play resources/����.mp3 from 0"), NULL, 0, NULL);
			if (is_visited)
			{
				//�޸���ͼΪNULL
				img_platform = img_NULL_platform;
				if (!direction)
				{				
					//���Ѫ��-1������-4
					map_msg->score -= 4;
					if(player->health>0)
					player->health -= 1;
				}
				else
				{
					if(player->health<12)
					player->health += 1;
				}
				//ͨ�����ʹֻ�ܴ���һ��
				is_platform = true;
			}
		}
	}
};
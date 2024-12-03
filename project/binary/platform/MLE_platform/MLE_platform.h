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
		2.���direction��Ϊ0���������ͼ��Χ�����Ҹ�10����������0��550��
		3.�޸���ͼΪNULL��ͨ����ǣ���������Ч���ܹ�ֻ����һ�Σ�����������һ�Σ�ֻ��һ�Σ�
	*/
	//�������
	bool is_platform = false;
	void PlatformChange(Player* player, int direction = 0)
	{
		//������
		if (is_platform == false)
		{
			//�޸���ͼΪNULL
			img_platform = img_NULL_platform;
			//���Ϊ0�޸ĵ�ͼlimit�ķ�Χ�����Ҹ���С10�����10��������0��550��
			if (direction)
			{
				if (map_msg->left_limit >= 10)
				{
					map_msg->left_limit -= 20;
					map_msg->right_limit += 20;
					//����+1
					map_msg->score += 1;
				}
			}
			else
			{
				if (map_msg->left_limit <= map_msg->right_limit)
				{
					map_msg->left_limit += 20;
					map_msg->right_limit -= 20;
					//����-2
					map_msg->score -= 2;
				}
			}
			//ͨ�����ʹֻ�ܴ���һ��
			is_platform = true;
		}
	}
};


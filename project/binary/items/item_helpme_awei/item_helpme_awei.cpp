#include"item_helpme_awei.h"

/*
	�����ˣ�ָ���ٳ�
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.��������ĵ�����ʼ��time_keeper=0��cd��duration��is_cding��istriggered��
*/


extern Atlas atlas_item_help;


item_helpme_awei::item_helpme_awei(Player* player, Map_Msg* map_msg)
{
	this->id = 3;
	cd = 20 * 60;
	time_keeper = 0;
	duration = 20 * 60;
	is_cding = 0;
	istriggered = 0;
	this->player = player;
	this->map_msg = map_msg;
}


void item_helpme_awei::OnUpdate()
{
	if (istriggered)
	{
		time_keeper++;
		if (time_keeper >= duration)
		{
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
		}
		else
		{
			if (map_msg->score < duration_score)
			{
				map_msg->score = duration_score;
			}
			if (map_msg->score > duration_score)
			{
				duration_score = map_msg->score;
			}
			if (player->health < duration_health)
			{
				player->health = duration_health;
			}
			if (player->health > duration_health)
			{
				duration_health = player->health;
			}


			if (map_msg->speed > duration_help_speed)//����
			{
				map_msg->speed = duration_help_speed;
			}

			if ((map_msg->right_limit - map_msg->left_limit) < duration_limit)
			{
				map_msg->right_limit = duration_limit;
			}
		}
	}
	else if (is_cding)
	{
		time_keeper++;
		if (time_keeper >= cd)
		{
			is_cding = false;
			time_keeper = 0;
		}
	}
}


/*
	�����ˣ�
	���ܣ�
		1.����һ��100*100�ĵ���ͼ�������Ͻ�
		2.���������cd�У�is_cding == true��������time_keeper��cd�ı������Ƶ���ͼ���ϵĺ�ɫ�ɰ�
*/
void item_helpme_awei::OnDarw()
{
	DWORD start_time = GetTickCount();
	if (is_cding == 0)//cd���ˣ�time_keeper����
	{
		putimage(550, 100, atlas_item_help.GetImage(0));
	}
	else//��20s��cd�����Ը�19������cd��ͼƬ
	{
		putimage(550, 100, atlas_item_help.GetImage(cd - time_keeper));
	}
}

/*
	�����ˣ�
	���ܣ�
		1.����ʱ���ڷ������ٽ��ͣ�Ѫ�����ٽ��͡�map_msg�е�speed�������ߡ�limit���ٱ�С���������Ҫ������OnUpdata������
		2.����istriggeredΪtrue
*/
void item_helpme_awei::triggering()
{
	istriggered = 1;
	duration_score = map_msg->score;
	duration_help_speed = map_msg->speed;
	duration_limit = map_msg->right_limit - map_msg->left_limit;
	duration_health = player->health;
	//����ʹ�õ���ʱ����Ϣ

}

/*
	�����ˣ�
	���ܣ�
		1.����triggering��Ч��
*/
void item_helpme_awei::end_trigger()
{

}
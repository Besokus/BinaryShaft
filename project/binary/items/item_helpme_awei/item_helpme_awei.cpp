#include"item_helpme_awei.h"

/*
	�����ˣ�ָ���ٳ�
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.��������ĵ�����ʼ��time_keeper=0��cd��duration��is_cding��istriggered��
*/

item_helpme_awei::item_helpme_awei(Player* player, Map_Msg* map_msg)
{
	this->id = 3;
	cd = 30 * 60;
	time_keeper = 0;
	duration = 15 * 60;
	is_cding = 0;
	istriggered = 0;
	this->player = player;
	this->map_msg = map_msg;
	duration_score=0;     //ʹ�õ����ڼ���ҷ���
	duration_health=12;    //ʹ�õ����ڼ����Ѫ��
	duration_speed=1.0;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	duration_help_speed=1.0;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	duration_left_limit = 0;  //ʹ�õ����ڼ�߽��С
	duration_right_limit = 550;  //ʹ�õ����ڼ�߽��С
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
			if (map_msg->score < duration_score)//����
			{
				map_msg->score = duration_score;
			}
			else if (map_msg->score > duration_score)
			{
				duration_score = map_msg->score;
			}

			if (player->health < duration_health)//Ѫ��
			{
				player->health = duration_health;
			}
			else if (player->health > duration_health)
			{
				duration_health = player->health;
			}


			if (map_msg->speed > duration_help_speed)//�ٶ�
			{
				map_msg->speed = duration_help_speed;
			}
			else if (map_msg->speed < duration_help_speed)
			{
				duration_help_speed = map_msg->speed;
			}

			if (map_msg->left_limit > duration_left_limit)//��߽�
			{
				map_msg->left_limit = duration_left_limit;
			}
			else if (map_msg->left_limit < duration_left_limit)
			{
				duration_left_limit = map_msg->left_limit;
			}

			if (map_msg->right_limit < duration_right_limit)//�ұ߽�
			{
				map_msg->right_limit = duration_right_limit;
			}
			else if (map_msg->right_limit > duration_right_limit)
			{
				duration_right_limit = map_msg->right_limit;
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
	// ����ͼ������Ͻ�����
	int x = 550;
	int y = 50;
	// ����ͼ��Ŀ�Ⱥ͸߶�
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_helpme_awei;
	// ���Ƶ���ͼ�����Ͻ�

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("��ΰ���ң�"));
	outtextxy(530, 170, _T("�������и���"));

	// �������Ƿ���CD��
	if (is_cding) {
		// �����ɰ渲�ǵı���
		float overlay_ratio = static_cast<float>(time_keeper) / cd;
		// ȷ���������ᳬ��1.0
		if (overlay_ratio > 1.0f) {
			overlay_ratio = 1.0f;
		}

		// �ڵ���ͼ���ϻ��ƺ�ɫ�ɰ�
		DrawBlackOverlay(x, y, width, height, overlay_ratio);
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
	duration_left_limit = map_msg->left_limit;
	duration_right_limit = map_msg->right_limit;
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
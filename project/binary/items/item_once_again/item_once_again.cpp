#include"item_once_again.h"

extern IMAGE img_NULL_platform;

/*
	�����ˣ�yuuki
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.��������ĵ�����ʼ��time_keeper��cd��duration��is_cding��istriggered��
*/
item_once_again::item_once_again(Player* player, Map_Msg* map_msg)
{
	this->id = 5;
	cd = 2147483647;
	time_keeper = 0;
	duration = 5 * 60;
	is_cding = 0;
	istriggered = 0;
	this->player = player;
	this->map_msg = map_msg;
}

/*
	�����ˣ�
	���ܣ�
		1.����һ��100*100�ĵ���ͼ�������Ͻ�
		2.���������cd�У�is_cding == true��������time_keeper��cd�ı������Ƶ���ͼ���ϵĺ�ɫ�ɰ�
*/
void item_once_again::OnDarw()
{
	// ����ͼ������Ͻ�����
	int x = 550;
	int y = 50;
	// ����ͼ��Ŀ�Ⱥ͸߶�
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_once_again; /***/
	// ���Ƶ���ͼ�����Ͻ�

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("���ߵıӻ�"));
	outtextxy(530, 170, _T("���������"));

	if (istriggered)
	{
		PutImage(230, 300 + (int)player->size.y, &img_NULL_platform);
	}

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
		1.������ң����õ�һ����ʼλ�ã�ֻ�ܴ���һ��
		2.����istriggeredΪtrue
*/
void item_once_again::triggering()
{
	mciSendString(_T("play resources/����.mp3 from 0"), NULL, 0, NULL);
	istriggered = true;
	player->health = 9;
	player->SetPosition(250, 300);
	player->is_alive = true;
	player->is_on_platform = true;
}
void item_once_again::OnUpdate()
{
	if (istriggered)
	{
		if (!player->is_left_key_down && !player->is_right_key_down && !player->is_jumping) 
		{
			player->health = 9;
			player->SetPosition(250, 300);
			
		}
		else
		{
			player->is_on_platform = false;
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
		}
		time_keeper++;
		if (time_keeper >= duration)
		{
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
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
		1.��
*/
void item_once_again::end_trigger()
{

}
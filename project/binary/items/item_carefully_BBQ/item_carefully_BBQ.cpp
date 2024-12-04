#include"item_carefully_BBQ.h"

/*
	�����ˣ�Minato
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.����doc����ĵ�����ʼ��time_keeper��cd��duration��is_cding��istriggered��
*/
extern IMAGE image_item_carefully_BBQ;
item_carefully_BBQ::item_carefully_BBQ(Player* player, Map_Msg* map_msg)
{
	this->id = 1;
	cd = 20 * 60;
	time_keeper = 0;
	duration = 20 * 60;
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
void item_carefully_BBQ::OnDarw()
{
	// ����ͼ������Ͻ�����
	int x = 550;
	int y = 50;
	// ����ͼ��Ŀ�Ⱥ͸߶�
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_carefully_BBQ;
	// ���Ƶ���ͼ�����Ͻ�

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("��ϸ�տ�"));
	outtextxy(530, 170, _T("����+����"));

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
		1.speed���͵� 0.5
		2.����istriggeredΪtrue
*/
void item_carefully_BBQ::triggering()
{
	mciSendString(_T("play resources/�ٶȼ���.mp3 from 0"), NULL, 0, NULL);
	istriggered = 1;
	player->max_speed_y = 2.5;
	map_msg->speed = 0.5f;
	if (player->is_on_platform)
	{
		player->velocity.y = -0.5f;
	}
}

/*
	�����ˣ�
	���ܣ�
		1.����triggering��Ч��
*/
void item_carefully_BBQ::end_trigger()
{
	istriggered = 0;
	player->max_speed_y = 10;
	map_msg->speed = map_msg->real_speed;
	if (player->is_on_platform)
	{
		player->velocity.y = -map_msg->speed;
	}
}

void  item_carefully_BBQ::during_change()
{
	map_msg->speed = 0.5f;
}

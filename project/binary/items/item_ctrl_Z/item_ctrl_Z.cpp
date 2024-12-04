#include"item_ctrl_Z.h"
extern Atlas atlas_item_help;
/*
	�����ˣ�Minato
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.��������ĵ�����ʼ��time_keeper��cd��duration��is_cding��istriggered��
*/

item_ctrl_Z::item_ctrl_Z(Player* player, Map_Msg* map_msg)
{
	this->id = 2;
	cd = 20 * 60;
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
void item_ctrl_Z::OnDarw()
{
	// ����ͼ������Ͻ�����
	int x = 550;
	int y = 50;
	// ����ͼ��Ŀ�Ⱥ͸߶�
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_ctrl_Z; /***/
	// ���Ƶ���ͼ�����Ͻ�

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("CTRL Z"));
	outtextxy(530, 170, _T("ʱ�⵹��"));

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
		1.�޸�map_msg��speed������
		2.����istriggeredΪtrue
*/
void item_ctrl_Z::triggering()
{
	istriggered = 1;
	map_msg->speed = -map_msg->speed;
	if (player->is_on_platform)
	{
		player->velocity.y = -player->velocity.y;
	}
}

/*
	�����ˣ�
	���ܣ�
		1.����triggering��Ч��
*/
void item_ctrl_Z::end_trigger()
{
	istriggered = 0;
	map_msg->speed = map_msg->real_speed;
	if (player->is_on_platform)
	{
		player->velocity.y = -player->velocity.y;
	}
}

void item_ctrl_Z::during_change()
{
	map_msg->speed = -map_msg->real_speed;
}
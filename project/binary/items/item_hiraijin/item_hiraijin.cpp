#include"item_hiraijin.h"

extern IMAGE item_hiraijin_sign;

/*
	�����ˣ�ָ���ٳ�
	��������ͼ������ָ����Ϣ
	���ܣ�
		1.��ָ����Ϣ�洢��protected�е���Ϣ��
		2.��������ĵ�����ʼ��time_keeper��cd��duration��is_cding��istriggered��
*/
item_hiraijin::item_hiraijin(Player* player, Map_Msg* map_msg)
{
	this->id = 4;
	cd = 5 * 60;
	time_keeper = 0;
	duration = 0 * 60;
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
void item_hiraijin::OnDarw()
{
	if (trigger_time == 1)
	{
		PutImage((int)memory_x, (int)memory_y, &item_hiraijin_sign);
	}

	// ����ͼ������Ͻ�����
	int x = 550;
	int y = 50;
	// ����ͼ��Ŀ�Ⱥ͸߶�
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_hiraijin; /***/
	// ���Ƶ���ͼ�����Ͻ�

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("������֮��"));
	outtextxy(530, 170, _T("���ͻر��"));

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
		1.��һ��ʹ��ʱ��¼λ�ã��ڶ���ʹ��ʱ�ص����λ��
		2.�ڶ���ʹ�ú󣬸���istriggeredΪtrue
*/
void item_hiraijin::triggering()
{
	trigger_time++;
	switch (trigger_time)
	{
	case 1:
		memory_x = player->position.x;
		memory_y = player->position.y;
		break;
	case 2:
		trigger_time = 0;
		player->SetPosition((int)memory_x, (int)memory_y);
		istriggered = true;
		break;
	default:
		break;
	}
}

/*
	�����ˣ�
	���ܣ�
		1.����triggering��Ч��
*/
void item_hiraijin::end_trigger()
{
	player->is_on_platform = false;
}
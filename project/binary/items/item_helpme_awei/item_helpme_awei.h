#pragma once
#include"../item/item.h"

class item_helpme_awei :public item
{
protected:
	int duration_score;     //ʹ�õ����ڼ���ҷ���
	int duration_health;    //ʹ�õ����ڼ����Ѫ��
	float duration_speed;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	float duration_help_speed;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	int duration_left_limit;  //ʹ�õ����ڼ�߽��С
	int duration_right_limit;  //ʹ�õ����ڼ�߽��С
public:
	item_helpme_awei(Player* player, Map_Msg* map_msg);

	void OnUpdate();

	void OnDarw();

	void triggering();

	void end_trigger();
};

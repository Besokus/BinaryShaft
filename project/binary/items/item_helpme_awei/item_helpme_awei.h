#pragma once
#include"../item/item.h"

class item_helpme_awei :public item
{
protected:
	int duration_score;     //ʹ�õ����ڼ���ҷ���
	int duration_health;    //ʹ�õ����ڼ����Ѫ��
	double duration_speed;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	double duration_help_speed;  //ʹ�õ����ڼ�ƽ̨�ٶ�
	double duration_limit;  //ʹ�õ����ڼ�߽��С
public:
	item_helpme_awei(Player* player, Map_Msg* map_msg);

	void OnUpdate();

	void OnDarw();

	void triggering();

	void end_trigger();
};

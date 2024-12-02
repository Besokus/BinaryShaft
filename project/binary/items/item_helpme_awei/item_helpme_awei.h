#pragma once
#include"../item/item.h"

class item_helpme_awei :public item
{
protected:
	int duration_score;     //使用道具期间玩家分数
	int duration_health;    //使用道具期间玩家血量
	double duration_speed;  //使用道具期间平台速度
	double duration_help_speed;  //使用道具期间平台速度
	double duration_limit;  //使用道具期间边界大小
public:
	item_helpme_awei(Player* player, Map_Msg* map_msg);

	void OnUpdate();

	void OnDarw();

	void triggering();

	void end_trigger();
};

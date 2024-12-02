#include"item_helpme_awei.h"

/*
	负责人：指端琴长
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper=0、cd、duration、is_cding、istriggered。
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


			if (map_msg->speed > duration_help_speed)//加速
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
	负责人：
	功能：
		1.绘制一个100*100的道具图像在右上角
		2.如果道具在cd中（is_cding == true），根据time_keeper与cd的比例绘制道具图像上的黑色蒙版
*/
void item_helpme_awei::OnDarw()
{
	DWORD start_time = GetTickCount();
	if (is_cding == 0)//cd好了，time_keeper不动
	{
		putimage(550, 100, atlas_item_help.GetImage(0));
	}
	else//有20s的cd，所以搞19张正在cd的图片
	{
		putimage(550, 100, atlas_item_help.GetImage(cd - time_keeper));
	}
}

/*
	负责人：
	功能：
		1.持续时间内分数不再降低，血量不再降低、map_msg中的speed不再升高、limit不再变小（这可能需要你重载OnUpdata函数）
		2.更新istriggered为true
*/
void item_helpme_awei::triggering()
{
	istriggered = 1;
	duration_score = map_msg->score;
	duration_help_speed = map_msg->speed;
	duration_limit = map_msg->right_limit - map_msg->left_limit;
	duration_health = player->health;
	//记下使用道具时的信息

}

/*
	负责人：
	功能：
		1.抵消triggering的效果
*/
void item_helpme_awei::end_trigger()
{

}
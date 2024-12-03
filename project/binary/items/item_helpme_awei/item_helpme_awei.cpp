#include"item_helpme_awei.h"

/*
	负责人：指端琴长
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper=0、cd、duration、is_cding、istriggered。
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
	duration_score=0;     //使用道具期间玩家分数
	duration_health=12;    //使用道具期间玩家血量
	duration_speed=1.0;  //使用道具期间平台速度
	duration_help_speed=1.0;  //使用道具期间平台速度
	duration_left_limit = 0;  //使用道具期间边界大小
	duration_right_limit = 550;  //使用道具期间边界大小
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
			if (map_msg->score < duration_score)//分数
			{
				map_msg->score = duration_score;
			}
			else if (map_msg->score > duration_score)
			{
				duration_score = map_msg->score;
			}

			if (player->health < duration_health)//血量
			{
				player->health = duration_health;
			}
			else if (player->health > duration_health)
			{
				duration_health = player->health;
			}


			if (map_msg->speed > duration_help_speed)//速度
			{
				map_msg->speed = duration_help_speed;
			}
			else if (map_msg->speed < duration_help_speed)
			{
				duration_help_speed = map_msg->speed;
			}

			if (map_msg->left_limit > duration_left_limit)//左边界
			{
				map_msg->left_limit = duration_left_limit;
			}
			else if (map_msg->left_limit < duration_left_limit)
			{
				duration_left_limit = map_msg->left_limit;
			}

			if (map_msg->right_limit < duration_right_limit)//右边界
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
	负责人：
	功能：
		1.绘制一个100*100的道具图像在右上角
		2.如果道具在cd中（is_cding == true），根据time_keeper与cd的比例绘制道具图像上的黑色蒙版
*/
void item_helpme_awei::OnDarw()
{
	// 道具图像的右上角坐标
	int x = 550;
	int y = 50;
	// 道具图像的宽度和高度
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_helpme_awei;
	// 绘制道具图像到左上角

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("阿伟助我！"));
	outtextxy(530, 170, _T("免疫所有负面"));

	// 检查道具是否在CD中
	if (is_cding) {
		// 计算蒙版覆盖的比例
		float overlay_ratio = static_cast<float>(time_keeper) / cd;
		// 确保比例不会超过1.0
		if (overlay_ratio > 1.0f) {
			overlay_ratio = 1.0f;
		}

		// 在道具图像上绘制黑色蒙版
		DrawBlackOverlay(x, y, width, height, overlay_ratio);
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
	duration_left_limit = map_msg->left_limit;
	duration_right_limit = map_msg->right_limit;
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
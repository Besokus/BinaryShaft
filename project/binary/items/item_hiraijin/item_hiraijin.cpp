#include"item_hiraijin.h"

extern IMAGE item_hiraijin_sign;

/*
	负责人：指端琴长
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper、cd、duration、is_cding、istriggered。
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
	负责人：
	功能：
		1.绘制一个100*100的道具图像在左上角
		2.如果道具在cd中（is_cding == true），根据time_keeper与cd的比例绘制道具图像上的黑色蒙版
*/
void item_hiraijin::OnDarw()
{
	if (trigger_time == 1)
	{
		PutImage((int)memory_x, (int)memory_y, &item_hiraijin_sign);
	}

	// 道具图像的左上角坐标
	int x = 550;
	int y = 50;
	// 道具图像的宽度和高度
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_hiraijin; /***/
	// 绘制道具图像到左上角

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("飞雷神之术"));
	outtextxy(530, 170, _T("传送回标记"));

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
		1.第一次使用时记录位置，第二次使用时回到这个位置
		2.第二次使用后，更新istriggered为true
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
	负责人：
	功能：
		1.抵消triggering的效果
*/
void item_hiraijin::end_trigger()
{
	player->is_on_platform = false;
}
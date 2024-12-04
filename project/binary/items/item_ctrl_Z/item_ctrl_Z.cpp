#include"item_ctrl_Z.h"
extern Atlas atlas_item_help;
/*
	负责人：Minato
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper、cd、duration、is_cding、istriggered。
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
	负责人：
	功能：
		1.绘制一个100*100的道具图像在左上角
		2.如果道具在cd中（is_cding == true），根据time_keeper与cd的比例绘制道具图像上的黑色蒙版
*/
void item_ctrl_Z::OnDarw()
{
	// 道具图像的左上角坐标
	int x = 550;
	int y = 50;
	// 道具图像的宽度和高度
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_ctrl_Z; /***/
	// 绘制道具图像到左上角

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("CTRL Z"));
	outtextxy(530, 170, _T("时光倒流"));

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
		1.修改map_msg的speed的正负
		2.更新istriggered为true
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
	负责人：
	功能：
		1.抵消triggering的效果
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
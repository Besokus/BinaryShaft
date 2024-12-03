#include"item_the_world.h"

/*
	负责人：yuuki
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper、cd、duration、is_cding、istriggered。
*/
item_the_world::item_the_world(Player* player, Map_Msg* map_msg)
{
	this->id = 5;
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
void item_the_world::OnDarw()
{
	// 道具图像的左上角坐标
	int x = 550;
	int y = 50;
	// 道具图像的宽度和高度
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_the_world; /***/
	// 绘制道具图像到左上角

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("THE WORLD！"));
	outtextxy(530, 170, _T("砸瓦鲁多！时停"));

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
		1.修改map_msg的速度为0
		2.更新istriggered为true
*/
void item_the_world::triggering()
{
	memory_speed = map_msg->speed;
	map_msg->speed = 0;
	if (player->is_on_platform)
	{
		player->velocity.y = 0;
	}
	istriggered = true;
}

/*
	负责人：
	功能：
		1.抵消triggering的效果
*/
void item_the_world::end_trigger()
{
	map_msg->speed = memory_speed;
}
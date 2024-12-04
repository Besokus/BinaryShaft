#include"item_once_again.h"

extern IMAGE img_NULL_platform;

/*
	负责人：yuuki
	参数：地图、人物指针信息
	功能：
		1.将指针信息存储到protected中的信息中
		2.根据设计文档，初始化time_keeper、cd、duration、is_cding、istriggered。
*/
item_once_again::item_once_again(Player* player, Map_Msg* map_msg)
{
	this->id = 5;
	cd = 2147483647;
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
void item_once_again::OnDarw()
{
	// 道具图像的左上角坐标
	int x = 550;
	int y = 50;
	// 道具图像的宽度和高度
	int width = 100;
	int height = 100;

	IMAGE* itemImage = &image_item_once_again; /***/
	// 绘制道具图像到左上角

	PutImage(x, y, itemImage);
	outtextxy(530, 150, _T("贤者的庇护"));
	outtextxy(530, 170, _T("复活，非主动"));

	if (istriggered)
	{
		PutImage(230, 300 + (int)player->size.y, &img_NULL_platform);
	}

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
		1.复活玩家，重置到一个初始位置，只能触发一次
		2.更新istriggered为true
*/
void item_once_again::triggering()
{
	mciSendString(_T("play resources/复活.mp3 from 0"), NULL, 0, NULL);
	istriggered = true;
	player->health = 9;
	player->SetPosition(250, 300);
	player->is_alive = true;
	player->is_on_platform = true;
}
void item_once_again::OnUpdate()
{
	if (istriggered)
	{
		if (!player->is_left_key_down && !player->is_right_key_down && !player->is_jumping) 
		{
			player->health = 9;
			player->SetPosition(250, 300);
			
		}
		else
		{
			player->is_on_platform = false;
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
		}
		time_keeper++;
		if (time_keeper >= duration)
		{
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
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
		1.无
*/
void item_once_again::end_trigger()
{

}
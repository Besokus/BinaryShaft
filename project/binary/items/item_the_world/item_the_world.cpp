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

}

/*
	负责人：
	功能：
		1.绘制一个100*100的道具图像在左上角
		2.如果道具在cd中（is_cding == true），根据time_keeper与cd的比例绘制道具图像上的黑色蒙版
*/
void item_the_world::OnDarw()
{

}

/*
	负责人：
	功能：
		1.修改map_msg的速度为0
		2.更新istriggered为true
*/
void item_the_world::triggering()
{

}

/*
	负责人：
	功能：
		1.抵消triggering的效果
*/
void item_the_world::end_trigger()
{

}
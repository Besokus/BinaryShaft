#include "select_items_scene.h"
#include "../../scene/scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../button/menu_button/menu_button.h"

extern IMAGE image_item_carefully_BBQ;
extern IMAGE image_item_ctrl_Z;
extern IMAGE image_item_helpme_awei;
extern IMAGE image_item_hiraijin;
extern IMAGE image_item_once_again;
extern IMAGE image_item_the_world;

extern IMAGE select_items_yes;
extern IMAGE img_menu_background;

extern void PutImage(int x, int y, IMAGE* img);

//{1.3f, 2147483647, {35,21,10,6,6,9,9,4}, {0,0,0,0,0,0} }
//{仔细烧烤、回溯、阿伟助我、飞雷神、再来一次、世界！（时停）}


void SelectItemsScene::OnEnter()
{
	int cnt = 0;
	for (auto item : *items)
	{
		if (item)
			cnt++;
	}
	items_num = cnt;
}


void SelectItemsScene::OnUpdate()
{

}

void SelectItemsScene::OnDraw()
{
	putimage(0, 0, &img_menu_background);
	const int x1 = 100, x2 = 300, x3 = 500;
	const int y1 = 250, y2 = 450;
	const int width = 100;
	const int height = 100;
	settextcolor(BLACK);
	for (int i = 0; i < (*items).size(); i++)
	{
		switch (i)
		{
		case 0:
			PutImage(x1, y1, &image_item_carefully_BBQ);
			outtextxy(x1, y1-60, _T("仔细烧烤"));
			outtextxy(x1, y1-30, _T("缓速+缓降"));
			if ((*items)[i])
			{
				PutImage(x1, y1, &select_items_yes);
			}
			break;
		case 1:
			PutImage(x2, y1, &image_item_ctrl_Z);
			outtextxy(x2, y1-60, _T("CTRL Z"));
			outtextxy(x2, y1-30, _T("时光倒流"));
			if ((*items)[i])
			{
				PutImage(x2, y1, &select_items_yes);
			}
			break;
		case 2:
			PutImage(x3, y1, &image_item_helpme_awei);
			outtextxy(x3, y1-60, _T("阿伟助我！"));
			outtextxy(x3, y1-30, _T("免疫所有负面"));
			if ((*items)[i])
			{
				PutImage(x3, y1, &select_items_yes);
			}
			break;
		case 3:
			PutImage(x1, y2, &image_item_hiraijin);
			outtextxy(x1, y2-60, _T("飞雷神之术"));
			outtextxy(x1, y2-30, _T("传送回标记"));
			if ((*items)[i])
			{
				PutImage(x1, y2, &select_items_yes);
			}
			break;
		case 4:
			PutImage(x2, y2, &image_item_once_again);
			outtextxy(x2, y2-60, _T("贤者的庇护"));
			outtextxy(x2, y2-30, _T("复活，非主动"));
			if ((*items)[i])
			{
				PutImage(x2, y2, &select_items_yes);
			}
			break;
		case 5:
			PutImage(x3, y2, &image_item_the_world);
			outtextxy(x3, y2 - 60, _T("THE WORLD！"));
			outtextxy(x3, y2 - 30, _T("砸瓦鲁多！时停"));
			if ((*items)[i])
			{
				PutImage(x3, y2, &select_items_yes);
			}
			break;
		}
	}
	settextcolor(WHITE);
	outtextxy(100, 600, _T("按Enter键进入游戏,ESC返回"));
}

void SelectItemsScene::OnInput(const ExMessage& msg)
{
	const int x1 = 100, x2 = 300, x3 = 500;
	const int y1 = 250, y2 = 450;
	const int width = 100;
	const int height = 100;
	if (items_num >= 3)
	{
		outtextxy(350, 530, _T("你已经选择三个道具了"));
		//return;
	}
	switch (msg.message)
	{
	case WM_LBUTTONUP:
		if (msg.y >= y1 && msg.y <= y1 + 100)
		{
			if (msg.x >= x1 && msg.x <= x1 + 100)
			{
				if ((*items)[0])
				{
					(*items)[0] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[0] = true;
						items_num++;
					}
				}
			}
			else if (msg.x >= x2 && msg.x <= x2 + 100)
			{
				if ((*items)[1])
				{
					(*items)[1] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[1] = true;
						items_num++;
					}
				}
			}
			else if (msg.x >= x3 && msg.x <= x3 + 100)
			{
				if ((*items)[2])
				{
					(*items)[2] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[2] = true;
						items_num++;
					}
				}
			}
		}
		else if (msg.y >= y2 && msg.y <= y2 + 100)
		{
			if (msg.x >= x1 && msg.x <= x1 + 100)
			{
				if ((*items)[3])
				{
					(*items)[3] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[3] = true;
						items_num++;
					}
				}
			}
			else if (msg.x >= x2 && msg.x <= x2 + 100)
			{
				if ((*items)[4])
				{
					(*items)[4] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[4] = true;
						items_num++;
					}
				}
			}
			else if (msg.x >= x3 && msg.x <= x3 + 100)
			{
				if ((*items)[5])
				{
					(*items)[5] = false;
					items_num--;
				}
				else
				{
					if (items_num < 3)
					{
						(*items)[5] = true;
						items_num++;
					}
				}
			}
		}
		break;
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
			break;
		case VK_RETURN:
			level = 10;
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
			break;
		}
		break;
	default:
		break;
	}
}

void SelectItemsScene::OnExit()
{

}
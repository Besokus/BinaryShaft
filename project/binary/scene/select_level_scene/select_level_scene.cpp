#include "../../data.h"
#include "select_level_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include <iostream>

extern SceneManager scene_manager;
extern int level;
extern const int LEVEL_NUM;

extern Data* current_data;

extern IMAGE img_select_level_background;

void SelectLevelScene::OnEnter()
{
	level = current_data->unlocked_level;
	if (level >= 10)
	{
		level = 9;
	}
}

void SelectLevelScene::OnDraw()
{
	putimage(0, 0, &img_select_level_background);
	setbkmode(TRANSPARENT);

	settextstyle(35, 0, _T("IPix"));
	outtextxy(205, 190, _T("关卡"));
	outtextxy(545, 190, _T("说明"));


	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(100, 290, _T("A"));
		outtextxy(150, 290, _T("<"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(100, 290, _T("A"));
		outtextxy(150, 290, _T("<"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(340, 290, _T("D"));
		outtextxy(290, 290, _T(">"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(340, 290, _T("D"));
		outtextxy(290, 290, _T(">"));
	}

	if (is_enter_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(80, 410, _T("开始"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(80, 410, _T("开始"));
	}

	if (is_esc_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(300, 410, _T("返回"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(300, 410, _T("返回"));
	}

	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), level + 1);
	outtextxy(225, 290, text);

	switch (level)
	{
	case 0:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("你貌似需要通过"));
		outtextxy(480, 300, _T("所有样例。"));
		break;
	case 1:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("借用道具来通关"));
		outtextxy(480, 300, _T("按下Q或E使用"));
		break;
	case 2:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("小心TLE平台"));
		outtextxy(480, 300, _T("要开始加速了"));
		outtextxy(480, 350, _T("（顶它有奇效）"));
		break;
	case 3:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("小心MLE平台"));
		outtextxy(480, 300, _T("你获得了新道具"));
		outtextxy(480, 350, _T("咋瓦鲁多！"));
		outtextxy(480, 400, _T("按CTRL切换道具"));
		break;
	case 4:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("去试一下CE平台"));
		outtextxy(480, 300, _T("（试试就逝世"));
		outtextxy(480, 350, _T("新道具：复活甲"));
		break;
	case 5:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("空间有限"));
		outtextxy(480, 300, _T("好多的MLE！"));
		outtextxy(480, 350, _T("新道具："));
		outtextxy(480, 400, _T("时间回溯"));
		break;
	case 6:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("时间有限"));
		outtextxy(480, 300, _T("暴力是有极限的"));
		outtextxy(480, 350, _T("新道具："));
		outtextxy(480, 400, _T("仔细烧烤"));
		break;
	case 7:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("展示身法"));
		outtextxy(480, 300, _T("新道具：飞雷神"));
		outtextxy(480, 350, _T("肩负火影之名"));
		outtextxy(480, 400, _T("我不能输！"));
		break;
	case 8:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("死亡地带"));
		outtextxy(480, 300, _T("小心每一个CE"));
		break;
	case 9:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("最后一战"));
		outtextxy(480, 300, _T("你要逃出这里了"));
		outtextxy(480, 350, _T("真的吗？"));
		break;
	case 10:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("你貌似来到了"));
		outtextxy(480, 300, _T("不该来的地方"));
		outtextxy(480, 350, _T("你逃走了吗？"));
		outtextxy(480, 400, _T("如逃"));
		break;
	}
}

void SelectLevelScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			level = (level - 1 + LEVEL_NUM) % LEVEL_NUM;
			is_A_down = true;
			break;
		case 'D':
			level = (level + 1) % LEVEL_NUM;
			is_D_down = true;
			break;
		case VK_RETURN:
			if (level > current_data->unlocked_level + 1)
			{
				static TCHAR text[64];
				_stprintf_s(text, _T("建议通过前面的关卡之后,再来挑战!"));

				MessageBox(GetHWnd(), text, _T("温馨提示"), MB_OK);
			}
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
			break;
		}
	}
	if (msg.message == WM_KEYUP)
	{
		switch (msg.vkcode)
		{
		case 'A':
			is_A_down = false;
			break;
		case 'D':
			is_D_down = false;
			break;
		}
	}

	if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN)
	{
		if (msg.x <= 340 + 30 * 2 && msg.x >= 290 && msg.y >= 290 && msg.y <= 290 + 30)
		{
			is_D_down = true;
			if (msg.message == WM_LBUTTONDOWN)
			{
				level = (level + 1) % LEVEL_NUM;
			}
		}
		else
		{
			is_D_down = false;
		}

		if (msg.x <= 150 + 30 * 2 && msg.x >= 100 && msg.y >= 290 && msg.y <= 290 + 30)
		{
			is_A_down = true;
			if (msg.message == WM_LBUTTONDOWN)
			{
				level = (level - 1 + LEVEL_NUM) % LEVEL_NUM;
			}
		}
		else
		{
			is_A_down = false;
		}


		if (msg.x <= 80 + 30 * 2 && msg.x >= 80 && msg.y >= 410 && msg.y <= 410 + 30)
		{
			is_enter_down = true;


			if (msg.message == WM_LBUTTONDOWN)
			{
				if (level > current_data->unlocked_level + 1)
				{
					static TCHAR text[64];
					_stprintf_s(text, _T("建议通过前面的关卡之后,再来挑战!"));

					MessageBox(GetHWnd(), text, _T("温馨提示"), MB_OK);
				}

				scene_manager.SwitchTo(SceneManager::SceneType::Game);

			}
		}
		else
		{
			is_enter_down = false;
		}


		if (msg.x <= 300 + 30 * 2 && msg.x >= 300 && msg.y >= 410 && msg.y <= 410 + 30)
		{
			is_esc_down = true;
			if (msg.message == WM_LBUTTONDOWN)
			{
				scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
			}
		}
		else
		{
			is_esc_down = false;
		}
	}

}

void SelectLevelScene::OnUpdate()
{

}

void SelectLevelScene::OnExit()
{


}
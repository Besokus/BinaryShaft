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
	outtextxy(205, 190, _T("�ؿ�"));
	outtextxy(545, 190, _T("˵��"));


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
		outtextxy(80, 410, _T("��ʼ"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(80, 410, _T("��ʼ"));
	}

	if (is_esc_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(300, 410, _T("����"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(300, 410, _T("����"));
	}

	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), level + 1);
	outtextxy(225, 290, text);

	switch (level)
	{
	case 0:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("��ò����Ҫͨ��"));
		outtextxy(480, 300, _T("����������"));
		break;
	case 1:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("���õ�����ͨ��"));
		outtextxy(480, 300, _T("����Q��Eʹ��"));
		break;
	case 2:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("С��TLEƽ̨"));
		outtextxy(480, 300, _T("Ҫ��ʼ������"));
		outtextxy(480, 350, _T("����������Ч��"));
		break;
	case 3:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("С��MLEƽ̨"));
		outtextxy(480, 300, _T("�������µ���"));
		outtextxy(480, 350, _T("զ��³�࣡"));
		outtextxy(480, 400, _T("��CTRL�л�����"));
		break;
	case 4:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("ȥ��һ��CEƽ̨"));
		outtextxy(480, 300, _T("�����Ծ�����"));
		outtextxy(480, 350, _T("�µ��ߣ������"));
		break;
	case 5:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("�ռ�����"));
		outtextxy(480, 300, _T("�ö��MLE��"));
		outtextxy(480, 350, _T("�µ��ߣ�"));
		outtextxy(480, 400, _T("ʱ�����"));
		break;
	case 6:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("ʱ������"));
		outtextxy(480, 300, _T("�������м��޵�"));
		outtextxy(480, 350, _T("�µ��ߣ�"));
		outtextxy(480, 400, _T("��ϸ�տ�"));
		break;
	case 7:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("չʾ��"));
		outtextxy(480, 300, _T("�µ��ߣ�������"));
		outtextxy(480, 350, _T("�縺��Ӱ֮��"));
		outtextxy(480, 400, _T("�Ҳ����䣡"));
		break;
	case 8:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("�����ش�"));
		outtextxy(480, 300, _T("С��ÿһ��CE"));
		break;
	case 9:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("���һս"));
		outtextxy(480, 300, _T("��Ҫ�ӳ�������"));
		outtextxy(480, 350, _T("�����"));
		break;
	case 10:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("��ò��������"));
		outtextxy(480, 300, _T("�������ĵط�"));
		outtextxy(480, 350, _T("����������"));
		outtextxy(480, 400, _T("����"));
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
				_stprintf_s(text, _T("����ͨ��ǰ��Ĺؿ�֮��,������ս!"));

				MessageBox(GetHWnd(), text, _T("��ܰ��ʾ"), MB_OK);
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
					_stprintf_s(text, _T("����ͨ��ǰ��Ĺؿ�֮��,������ս!"));

					MessageBox(GetHWnd(), text, _T("��ܰ��ʾ"), MB_OK);
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
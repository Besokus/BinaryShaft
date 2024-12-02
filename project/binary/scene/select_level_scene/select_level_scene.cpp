#include "select_level_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include <iostream>

extern SceneManager scene_manager;
extern int level;
extern const int LEVEL_NUM;


extern IMAGE img_select_level_background;

void SelectLevelScene::OnEnter()
{
	level = 0;
}



void SelectLevelScene::OnDraw()
{
	putimage(0, 0, &img_select_level_background);
	setbkmode(TRANSPARENT);

	settextstyle(35, 0, _T("IPix"));
	outtextxy(205, 190, _T("关卡"));
	outtextxy(545, 190, _T("说明"));

	outtextxy(60, 410, _T("Enter开始  Esc返回"));

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
		outtextxy(480, 250, _T("无"));
		break;
	case 2:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("无"));
		break;
	case 3:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("无"));
		break;
	case 4:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("无"));
		break;
	case 5:
		settextstyle(30, 0, _T("IPix"));
		outtextxy(480, 250, _T("无"));
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
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
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

}

void SelectLevelScene::OnUpdate()
{

}

void SelectLevelScene::OnExit()
{


}
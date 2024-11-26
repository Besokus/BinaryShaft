#include "select_level_scene.h"
#include "../scene_manager/scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;
extern int level;

void SelectLevelScene::OnEnter()
{
	std::cout << "进入选关界面" << std::endl;
	level = 0;
}

void SelectLevelScene::OnUpdate()
{
	std::cout << "正在选关" << std::endl;
}

void SelectLevelScene::OnDraw()
{
	outtextxy(10, 10, _T("A D选关"));
	outtextxy(10, 30, _T("ESC返回菜单"));
	static TCHAR text[64];
	_stprintf_s(text, _T("level:%d"), level + 1);
	outtextxy(10, 50, text);
	outtextxy(10, 70, _T("Enter进入关卡"));
}

void SelectLevelScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			level = (level - 1 + LEVELNUM) % LEVELNUM;
			break;
		case 'D':
			level = (level + 1) % LEVELNUM;
			break;
		case VK_RETURN:
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		}

	}
}

void SelectLevelScene::OnExit()
{


}
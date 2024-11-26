#include "menu_scene.h"

extern bool running;
extern SceneManager scene_manager;

void MenuScene::OnEnter()
{
	std::cout << "进入主菜单" << std::endl;
}

void MenuScene::OnUpdate()
{
	std::cout << "主菜单正在运行" << std::endl;
}

void MenuScene::OnDraw()
{
	outtextxy(10, 10, _T("A选关 D退出"));
}

void MenuScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
			break;
		case 'D':
			running = false;
			break;
			
		}
		
	}
}

void MenuScene::OnExit()
{
	std::cout << "主菜单退出" << std::endl;
}

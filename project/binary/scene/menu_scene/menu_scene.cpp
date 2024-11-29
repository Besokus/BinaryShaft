#include "menu_scene.h"
#include "../../button/button/button.h"
#include "../../button/menu_button/menu_start_button.h"
#include "../../button/menu_button/menu_setup_button.h"

extern bool running;
extern SceneManager scene_manager;

extern IMAGE img_menu_background;

extern MenuStartButton* btn_menu_start;

void MenuScene::OnEnter()
{
	btn_menu_start->OnEnter();

	std::cout << "进入主菜单" << std::endl;
}

void MenuScene::OnUpdate()
{
	std::cout << "主菜单正在运行" << std::endl;
}

void MenuScene::OnDraw()
{
	putimage(0, 0, &img_menu_background);
	btn_menu_start->OnDraw();

	// outtextxy(10, 10, _T("A选关 D退出"));
}

void MenuScene::OnInput(const ExMessage& msg)
{
	btn_menu_start->OnInput(msg);


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

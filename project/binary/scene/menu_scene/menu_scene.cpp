#include "menu_scene.h"
#include "../../button/button/button.h"

extern bool running;
extern SceneManager scene_manager;


extern IMAGE img_menu_background;

extern IMAGE img_menu_start_idle;
extern IMAGE img_menu_start_hovered;
extern IMAGE img_menu_start_pushed;

extern StartButton* btn_menu_start;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const int BUTTON_WIDTH = 175;
const int BUTTON_HEIGHT = 45;

void MenuScene::OnEnter()
{
	RECT region_menu_start;
	region_menu_start.left = 300;
	region_menu_start.right = region_menu_start.left+ BUTTON_WIDTH;
	region_menu_start.top = 235;
	region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

	btn_menu_start = new StartButton(region_menu_start,
		_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

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

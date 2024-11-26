#include "menu_scene.h"

extern bool running;
extern SceneManager scene_manager;

extern IMAGE img_menu_background;

extern IMAGE img_menu_start_idle;
extern IMAGE img_menu_start_hovered;
extern IMAGE img_menu_start_pushed;


void MenuScene::OnEnter()
{

	std::cout << "�������˵�" << std::endl;
}

void MenuScene::OnUpdate()
{
	std::cout << "���˵���������" << std::endl;
}

void MenuScene::OnDraw()
{
	putimage(0, 0, &img_menu_background);
	// outtextxy(10, 10, _T("Aѡ�� D�˳�"));
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
	std::cout << "���˵��˳�" << std::endl;
}

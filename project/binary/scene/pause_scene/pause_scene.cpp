#include "pause_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../button/pause_button/pause_button.h"
#include <iostream>

extern SceneManager scene_manager;

extern PauseBackGameButton* btn_pause_backgame;//返回游戏按钮
extern PauseBackMenuButton* btn_pause_backmenu;//返回菜单
extern PauseSetUpButton* btn_pause_setup;//设置按钮

extern IMAGE img_pause_background;//暂停界面背景图

void PauseScene::OnEnter()
{
	btn_pause_backgame->OnEnter();
	btn_pause_backmenu->OnEnter();
	btn_pause_setup->OnEnter();

}

void PauseScene::OnUpdate()
{
	std::cout << "暂停界面" << "\n";
}

void PauseScene::OnDraw()
{
	//outtextxy(10, 10, _T("施工中..."));
	//outtextxy(10, 30, _T("ESC返回游戏"));

	putimage(0, 0, &img_pause_background);
	btn_pause_backgame->OnDraw();
	btn_pause_backmenu->OnDraw();
	btn_pause_setup->OnDraw();

}

void PauseScene::OnInput(const ExMessage& msg)
{
	btn_pause_backgame->OnInput(msg);
	btn_pause_backmenu->OnInput(msg);
	btn_pause_setup->OnInput(msg);
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
			break;
		}
	}
}

void PauseScene::OnExit()
{

}
#include "pause_scene.h"
#include "../scene_manager/scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;

void PauseScene::OnEnter()
{

}

void PauseScene::OnUpdate()
{
	std::cout << "暂停界面" << "\n";
}

void PauseScene::OnDraw()
{
	outtextxy(10, 10, _T("施工中..."));
	outtextxy(10, 30, _T("ESC返回游戏"));

}

void PauseScene::OnInput(const ExMessage& msg)
{
	switch (msg.vkcode)
	{
	case VK_ESCAPE:
		scene_manager.SwitchTo(SceneManager::SceneType::Game);
		break;
	}

}

void PauseScene::OnExit()
{

}
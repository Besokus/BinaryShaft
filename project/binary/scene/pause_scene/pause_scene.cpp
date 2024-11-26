#include "pause_scene.h"
#include "../scene_manager/scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;

void PauseScene::OnEnter()
{

}

void PauseScene::OnUpdate()
{
	std::cout << "��ͣ����" << "\n";
}

void PauseScene::OnDraw()
{
	outtextxy(10, 10, _T("ʩ����..."));
	outtextxy(10, 30, _T("ESC������Ϸ"));

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
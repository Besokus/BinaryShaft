#include "pause_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../button/pause_button/pause_button.h"
#include <iostream>

extern SceneManager scene_manager;

extern PauseBackGameButton* btn_pause_backgame;//������Ϸ��ť
extern PauseBackMenuButton* btn_pause_backmenu;//���ز˵�
extern PauseSetUpButton* btn_pause_setup;//���ð�ť

extern IMAGE img_pause_background;//��ͣ���汳��ͼ

void PauseScene::OnEnter()
{
	btn_pause_backgame->OnEnter();
	btn_pause_backmenu->OnEnter();
	btn_pause_setup->OnEnter();

}

void PauseScene::OnUpdate()
{
	std::cout << "��ͣ����" << "\n";
}

void PauseScene::OnDraw()
{
	//outtextxy(10, 10, _T("ʩ����..."));
	//outtextxy(10, 30, _T("ESC������Ϸ"));

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
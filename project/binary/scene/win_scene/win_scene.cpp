#include "win_scene.h"
#include "../../data.h"

extern IMAGE img_win_background;
extern WinReturnButton* btn_win_return;
extern WinNextButton* btn_win_next;

extern int level;
extern Data* current_data;

void WinScene::OnEnter()
{
	// btn_win_next->OnEnter();
	// btn_win_return->OnEnter();

	mciSendString(_T("play resources/ʤ��.mp3 from 0"), NULL, 0, NULL);
	if (level < 10)
		level++;
	else
		level = 10;
}


void WinScene::OnUpdate()
{

}


void WinScene::OnDraw()
{
	putimage(0, 0, &img_win_background);


}

void WinScene::OnInput(const ExMessage& msg)
{
	// ���̰���
	if (msg.message == WM_KEYUP)
	{
		// �л������˵�����
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

	// ������
	if (msg.message == WM_LBUTTONDOWN)
	{
		// �л������˵�����
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

}

void WinScene::OnExit()
{

}
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

	mciSendString(_T("play resources/胜利.mp3 from 0"), NULL, 0, NULL);

	if (level > current_data->unlocked_level && level < 10) 
	{
		current_data->unlocked_level = level;
	}

	level++;
}


void WinScene::OnUpdate()
{

}


void WinScene::OnDraw()
{
	putimage(0, 0, &img_win_background);

	// btn_win_return->OnDraw();
	// btn_win_next->OnDraw();

}

void WinScene::OnInput(const ExMessage& msg)
{
	// btn_win_next->OnInput(msg);
	// btn_win_return->OnInput(msg);
		// 键盘按键
	if (msg.message == WM_KEYUP)
	{
		// 切换到主菜单场景
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

	// 鼠标左键
	if (msg.message == WM_LBUTTONDOWN)
	{
		// 切换到主菜单场景
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
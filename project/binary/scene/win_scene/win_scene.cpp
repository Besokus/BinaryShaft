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
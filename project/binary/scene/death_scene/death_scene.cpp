#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  

extern SceneManager scene_manager;
extern IMAGE img_death_background;

void DeathScene::OnEnter()
{
	static TCHAR text[64];
	_stprintf_s(text, _T("最终得分:%d !"), 114514);

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
}

void DeathScene::OnUpdate()
{


}

int DeathScene::GetPlayerScore()
{
	//接收玩家分数
	return 1;
}

void DeathScene::OnDraw()
{
	putimage(0, 0, &img_death_background);
}

void DeathScene::OnInput(const ExMessage& msg)
{
	// 键盘按键
	if (msg.message == WM_KEYUP)
	{
		// 切换到主菜单场景
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
	}

	// 鼠标左键
	if (msg.message == WM_LBUTTONDOWN)
	{
		// 切换到主菜单场景
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
	}

}

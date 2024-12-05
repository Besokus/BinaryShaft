#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  
#include "../../data.h"

extern SceneManager scene_manager;
extern IMAGE img_death_background;


extern int current_level;//本轮关卡数



//在本轮游戏结束后就将排行榜更新，current_score,current_level，避免到排行榜界面更改出现不必要的麻
void DeathScene::OnEnter()
{
}


void DeathScene::OnUpdate()
{


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
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
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
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

}

#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  
#include "../../data.h"

extern SceneManager scene_manager;
extern IMAGE img_death_background;

//Besokus写的
extern vector<Data> data_list;							// 定义数据链表,用来存储现有的玩家数据
extern Data* current_data;
extern int current_score;//本轮游戏玩家得分
extern int current_level;//本轮关卡数

extern Data* current_rank_data;
//int rank_num;//排行榜人数
extern vector<Data>rank_list[9];//十个榜单	
extern const int RANKPAGE;

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
		}	}

}

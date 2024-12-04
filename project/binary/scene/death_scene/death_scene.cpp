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
extern void WriteData();
extern void WriteRankData();
extern Data* current_rank_data;
//int rank_num;//排行榜人数
extern vector<Data>rank_list[9];//十个榜单	
extern const int RANKPAGE;

//在本轮游戏结束后就将排行榜更新，current_score,current_level，避免到排行榜界面更改出现不必要的麻烦

void DeathScene::OnEnter()
{
	mciSendString(_T("play resources/死亡.mp3 from 0"), NULL, 0, NULL);
	mciSendString(_T("stop bgm_normal_1"), NULL, 0, NULL);
	static TCHAR text[64];
	_stprintf_s(text, _T("最终得分:%d !"), 114514);

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
}

/*
* 
* Besokus写的
void DeathScene::OnEnter()
{
	static TCHAR text[64];
	_stprintf_s(text, _T("最终得分:%d !"), 114514);
	//在游戏结束后将本轮得分计入该玩家该关卡的数组下（选最高的得分计入）
	//获得玩家本轮游戏分数
	current_score = GetPlayerScore();
	//当前得分大于的时候再将得分写入该玩家下
	if (current_score > current_data->level_score[current_level]) {
		//更新玩家分数
		for (int i = 0; i < data_list.size(); i++) {
			if ((strcmp(data_list[i].name, current_data->name))==0) {
				data_list[i].level_score[current_level] = current_score;
				break;
			}
		}
		//将排行榜对应信息更改
		for (int i = 0; i < data_list.size(); i++) {
			if ((strcmp(rank_list[current_level][i].name, current_data->name)) == 0) {
				rank_list[current_level][i].level_score[current_level] = current_score;
				break;
			}
		}

	}

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
}
*/

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

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
	// 绘制死亡界面的内容
	// 使用特定的绘图API或框架函数来显示“游戏结束”、“你的分数”等信息
	// 例如，使用outtextxy（如果可用）或其他绘图函数
	//outtextxy(10, 10, _T("GAME OVER"));
	// 有一个函数来获取玩家的分数
	//int score = GetPlayerScore();
	//static TCHAR text[64];
	//_stprintf_s(text, _T("本次获得分数:%d"), score);  //显示分数
	//outtextxy(10, 30, text);
	//outtextxy(10, 50, _T("按任意键返回主菜单"));
	putimage(0, 0, &img_death_background);
}

void DeathScene::OnInput(const ExMessage& msg)
{

	if (msg.message == WM_KEYUP)
	{
		// 切换到主菜单场景
		scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
	}


}

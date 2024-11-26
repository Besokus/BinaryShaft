#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"

extern SceneManager scene_manager;
extern Player *player;
extern int level;
extern std::vector<Platform*> platform_list;

// 初始化游戏界面
// 重置游戏参数,例如：
// 1.玩家位置
// 2.分数
// 3.平台数量,平台位置
void GameScene::OnEnter()
{
	player = new Player();
	player->SetPosition(114,514);
}

// 更新游戏数据
// 1.更新玩家位置:
//		1.水平
//		2.竖直
// 2.更新平台位置:
//		1.如果有道具控制,否则一直向上移动,
//		2.移动的速度可能受其他因素影响(改变platform_speed)
// 3.碰撞判定:
//		1.遍历平台list
//		2.修改玩家数值方向速度
//		3.修改额外的数值
// 4.平台随机刷新:
//	
// 5.平台delete:


void GameScene::OnUpdate()
{
	player->OnUpdate();
	for (Platform* platform : platform_list) 
	{
		if (platform->CheckCollision(*player)) 
		{
		
		
		}
	}
}

// 1.绘制玩家
// 2.绘制平台
// 3.绘制窗口
// 4.绘制分数
//		1.AC
//		2.time
//		3.memory
// 
//
void GameScene::OnDraw()
{
	outtextxy(10, 10, _T("游戏绘图内容"));
	static TCHAR text[64];
	_stprintf_s(text, _T("level:%d"), level + 1);
	outtextxy(10, 50, text);
	
	outtextxy(10, 70, _T("P暂停 ESC退出到主菜单"));

	// player->OnDraw();
}

void GameScene::OnInput(const ExMessage& msg)
{
	
	if (msg.message == WM_KEYDOWN)
	{
		player->OnInput(msg);
		if (msg.message == WM_KEYDOWN)
		{
			switch (msg.vkcode)
			{
			case 'P':
				scene_manager.SwitchTo(SceneManager::SceneType::Pause);
				break;
			case VK_ESCAPE:
				scene_manager.SwitchTo(SceneManager::SceneType::Menu);
				break;
			}

		}
	}


}

void GameScene::OnExit()
{
	std::cout << "游戏退出" << std::endl;
}

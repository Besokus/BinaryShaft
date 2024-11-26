#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"


extern int level;

extern SceneManager scene_manager;

extern Player* player;

extern std::vector<Platform*> platform_list;

// 初始化游戏界面
// 重置游戏参数,例如：
// 1.玩家位置
// 2.分数
// 3.平台数量,平台位置
void GameScene::OnEnter()
{
	player = new Player();
	player->SetPosition(114, 514);
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

	// 生成新的平台到场景中
	GeneratePlatform(platform_list);

	// 对于所有在场景中的平台,调用其更新方法
	for (Platform* platform : platform_list)
	{
		platform->OnUpdate();
	}

	DeletePlatform(platform_list);
}

void GameScene::OnDraw()
{
	outtextxy(10, 10, _T("游戏绘图内容"));
	static TCHAR text[64];
	_stprintf_s(text, _T("level:%d"), level + 1);
	outtextxy(10, 50, text);
	outtextxy(10, 70, _T("P暂停 ESC退出到主菜单"));

	// 绘制玩家
	// player->OnDraw();
	// 
	// 绘制平台
	// for (Platform* platform : platform_list) 
	// {
	// 	  platform->OnDraw();
	// }
	//
	// 绘制游戏窗口
	// 
	// 
	// 绘制分数
	// 
	// outtext(); // level(关卡数) living_time(存活时间) memory_size(地图大小)

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

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	// 间隔一段时间后更新平台
	// INTERVAL的值可能需要随平台速度改变
	const int INTERVAL = 200;
	static int counter = 0;
	if ((++counter) % INTERVAL == 0)
	{
		// int seed = rand() % MOD;
		// 设置概率,生成不同的平台
		// switch(seed){...}
		// platform_list.push_back(new NULL_Platform());
		// platform_list.push_back(new NULL_Platform());
	}

}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list) {

		// 此处写入坐标位置判定
		if (platform->GetCollisonShape().y < 0)
		{
			platform->Disappear();
		}
	}

	for (size_t i = 0;i < platform_list.size();i++) {
		Platform* platform  = platform_list[i];
		if (!platform->CheckExist())
		{
			std::swap(platform_list[i], platform_list.back());
			platform_list.pop_back();
			delete platform;
		}
	}

}
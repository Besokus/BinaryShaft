#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"
#include "../../platform/AC_platform/AC_platform.h"
#include "../../platform/WA_platform/WA_platform.h"
#include "../../platform/NULL_platform/NULL_platform.h"

extern bool is_debug;
extern int level;

extern IMAGE img_menu_background;
extern IMAGE img_game_background_1;

extern IMAGE img_NULL_platform;
extern IMAGE img_AC_platform;
extern IMAGE img_WA_platform;
extern IMAGE img_CE_platform;
extern IMAGE img_SPEED_RIGHT_platform;
extern IMAGE img_SPEED_LEFT_platform;
extern IMAGE img_TLE_platform;
extern IMAGE img_MLE_platform;

extern SceneManager scene_manager;

extern Player* player;

extern std::vector<Platform*> platform_list;

// 初始化游戏界面
// 重置游戏参数,例如：
// 1.玩家位置
// 2.分数
// 3.平台数量,平台位置
// 注意:
// 1.暂停界面跳转到这,不应该重置参数
// 2.其他界面跳转到这,应该重置参数
void GameScene::OnEnter()
{
	// 重置随机数种子
	srand((unsigned)time(NULL));

	// 设置玩家初始位置
	player->SetPosition(200, 0);

	//初始化关卡信息
	map_msg=new Map_Msg(level);

	// 重置平台参数
	platform_list.clear();

	// 放置初始的几个平台
	platform_list.push_back(new ACPlatform(img_AC_platform));
	platform_list.back()->SetPosition(0, 514);
	platform_list.push_back(new NULLPlatform(img_NULL_platform));
	platform_list.back()->SetPosition(114, 414);
	platform_list.push_back(new WAPlatform(img_WA_platform));
	platform_list.back()->SetPosition(100, 314);
	platform_list.push_back(new NULLPlatform(img_NULL_platform));
	platform_list.back()->SetPosition(230, 214);
	platform_list.push_back(new NULLPlatform(img_NULL_platform));
	platform_list.back()->SetPosition(214, 114);
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
	// 生成新的平台到场景中
	GeneratePlatform(platform_list);

	if (!platform_list.empty())
	{
		for (Platform* platform : platform_list)
		{
			platform->OnUpdate();
		}
	}

	player->OnUpdate();

	// 删除出界的平台
	DeletePlatform(platform_list);

	if (!player->is_alive)
	{
		//player->is_alive = true;
		//scene_manager.SwitchTo(SceneManager::SceneType::Death);
	}
}

void GameScene::OnDraw()
{
	// 绘制背景图
	putimage(0, 0, &img_game_background_1);

	// 绘制平台
	for (Platform* platform : platform_list)
	{
		platform->OnDraw();
	}

	// 绘制玩家

	player->OnDraw();


	settextstyle(20, 0, _T("IPix"));
	outtextxy(0, 0, _T("按Z开启调试模式"));
	// 绘制分数
	// 
	// outtext(); // level(关卡数) living_time(存活时间) memory_size(地图大小)
}

void GameScene::OnInput(const ExMessage& msg)
{
	// 玩家移动输入
	player->OnInput(msg);

	// 界面跳转
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
		case 'Z':
			if (is_debug)
				is_debug = false;
			else
				is_debug = true;
			break;
		}
	}
}

void GameScene::OnExit()
{

}

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	// 这里等我回来改
	// 这里等我回来改	
	// 这里等我回来改
	// 这里等我回来改
	// 这里等我回来改
	// 这里等我回来改
	const int MOD = 10;
	// 间隔一段时间后更新平台
	// INTERVAL的值可能需要随平台速度改变
	const int INTERVAL = 100;
	static int counter = 0;

	if ((++counter) % INTERVAL == 0)
	{
		int seed = rand() % MOD;
		
		// seed
		// 0~4 NULL
		// 5   AC
		// 6~7 WA
		// 8   SPEED_RIGHT
		// 9   SPEED_LEFT

		// 生成位置
		int generater_x = rand() % (500-100);

		if (seed <= 4 && seed >= 0) 
		{
			// 将生成的平台加入链表
			platform_list.push_back(new NULLPlatform(img_NULL_platform));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 5) 
		{
			// 将生成的平台加入链表
			platform_list.push_back(new ACPlatform(img_AC_platform));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 6 || seed == 7)
		{
			// 将生成的平台加入链表
			platform_list.push_back(new WAPlatform(img_WA_platform));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 8)
		{
			// 将生成的平台加入链表
			platform_list.push_back(new WAPlatform(img_SPEED_RIGHT_platform));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 9)
		{
			// 将生成的平台加入链表
			platform_list.push_back(new WAPlatform(img_SPEED_LEFT_platform));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
		}

	}
}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list)
	{
		// 如果超出游戏范围
		if (platform->shape.top < 0)
		{
			platform->Disappear();
		}
	}

	for (size_t i = 0;i < platform_list.size();i++) {
		Platform* platform = platform_list[i];
		if (!platform->CheckExist())
		{
			// 将平台移出[链表
			std::swap(platform_list[i], platform_list.back());
			platform_list.pop_back();
			// 清空内存
			delete platform;
		}
	}
}
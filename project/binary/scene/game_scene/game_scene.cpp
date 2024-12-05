#include "../../data.h"
#include <algorithm>
//场景
#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
//玩家
#include "../../player/player.h"
//平台
#include "../../platform/platform/platform.h"
#include "../../platform/AC_platform/AC_platform.h"
#include "../../platform/WA_platform/WA_platform.h"
#include "../../platform/NULL_platform/NULL_platform.h"
#include "../../platform/bounce_platform/bounce_platform.h"
#include "../../platform/CE_platform/CE_platform.h"
#include "../../platform/speed_platform/speed_platform.h"
#include "../../platform/TLE_platform/TLE_platform.h"
#include "../../platform/MLE_platform/MLE_platform.h"
//道具
#include "../../items/item_carefully_BBQ/item_carefully_BBQ.h"
#include "../../items/item_ctrl_Z/item_ctrl_Z.h"
#include "../../items/item_helpme_awei/item_helpme_awei.h"
#include "../../items/item_hiraijin/item_hiraijin.h"
#include "../../items/item_once_again/item_once_again.h"
#include "../../items/item_the_world/item_the_world.h"

extern bool is_debug;
extern int level;

extern bool pause_back;
extern Map_Msg* static_map;
extern Player* static_player;

extern IMAGE img_menu_background;
extern IMAGE img_game_background_1;
extern IMAGE img_game_background_2;

extern IMAGE img_NULL_platform;
extern IMAGE img_AC_platform;
extern IMAGE img_WA_platform;
extern IMAGE img_CE_platform;
extern IMAGE img_SPEED_RIGHT_platform;
extern IMAGE img_SPEED_LEFT_platform;
extern IMAGE img_TLE_platform;
extern IMAGE img_MLE_platform;

extern SceneManager scene_manager;

extern std::vector<Platform*> platform_list;

extern vector<Data> data_list;
extern Data* current_data;

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
	mciSendString(_T("stop bgm_menu_1 "), NULL, 0, NULL);
	if (level == 10)
	{
		mciSendString(_T("play bgm_challenge_1 repeat"), NULL, 0, NULL);
	}
	else
	{
		mciSendString(_T("play bgm_normal_1 repeat"), NULL, 0, NULL);
	}
	// 重置随机数种子
	srand((unsigned)time(NULL));
	if (!pause_back)
	{
		// 初始化关卡信息
		map_msg = new Map_Msg(level);

		// 设置玩家初始位置
		player = new Player(map_msg);
		player->SetPosition(200, 100);

		// 初始化道具信息
		item_list.clear();
		current_item = nullptr;
		for (int i = 0; i < map_msg->item_choice.size(); i++)
		{
			if (map_msg->item_choice[i])
			{
				switch (i)
				{
				case 0:
					item_list.push_back(new item_carefully_BBQ(player, map_msg));
					break;
				case 1:
					item_list.push_back(new item_ctrl_Z(player, map_msg));
					break;
				case 2:
					item_list.push_back(new item_helpme_awei(player, map_msg));
					break;
				case 3:
					item_list.push_back(new item_hiraijin(player, map_msg));
					break;
				case 4:
					item_list.push_back(new item_once_again(player, map_msg));
					break;
				case 5:
					item_list.push_back(new item_the_world(player, map_msg));
					break;
				default:
					break;
				}
			}
		}
		if (!item_list.empty())
		{
			current_item = *(item_list.begin());
			current_item_num = 0;
		}

		// 重置平台参数
		platform_list.clear();

		// 放置初始的几个平台
		platform_list.push_back(new ACPlatform(img_AC_platform, map_msg));
		platform_list.back()->SetPosition(0, 514+100);
		platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
		platform_list.back()->SetPosition(114, 414+100);
		platform_list.push_back(new WAPlatform(img_WA_platform, map_msg));
		platform_list.back()->SetPosition(100, 314+100);
		platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
		platform_list.back()->SetPosition(330, 214+100);
		platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
		platform_list.back()->SetPosition(214, 114+100);
	}
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

	if (!item_list.empty())
	{
		for (auto i = item_list.begin(); i != item_list.end(); i++)
		{
			(*i)->OnUpdate();
		}
	}

	// 删除出界的平台
	DeletePlatform(platform_list);

	//判断胜利
	if (map_msg->score >= map_msg->target_score)
	{
		mciSendString(_T("stop bgm_normal_1"), NULL, 0, NULL);
		mciSendString(_T("stop bgm_challenge_1"), NULL, 0, NULL);

		static TCHAR text[64];
		_stprintf_s(text, _T("你通关了!"));
		MessageBox(GetHWnd(), text, _T("Win"), MB_OK);

		if (level >= current_data->unlocked_level)
		{
			current_data->unlocked_level = level + 1;
		}

		if (map_msg->score >= current_data->level_score[level][0])
		{
			current_data->level_score[level][0] = map_msg->score;
			sort(current_data->level_score[level], current_data->level_score[level] + 2);
		}

		scene_manager.SwitchTo(SceneManager::SceneType::Win);

		return;
	}

	// 判断死亡
	bool flag = 1;
	if (!player->is_alive)
	{
		if (this->map_msg->item_choice[4])
		{
			for (auto i = item_list.begin(); i != item_list.end(); i++)
			{
				if ((*i)->get_id() == 5)
				{
					if ((*i)->is_ready())
					{
						(*i)->triggering();
						player->is_alive = true;
						flag = 0;
					}
					else
					{
						break;
					}
				}
			}
		}
		if (flag)
		{
			// 音乐控制
			mciSendString(_T("play resources/死亡.mp3 from 0"), NULL, 0, NULL);
			mciSendString(_T("stop bgm_normal_1"), NULL, 0, NULL);
			mciSendString(_T("stop bgm_challenge_1"), NULL, 0, NULL);

			// 显示得分
			static TCHAR text[64];
			_stprintf_s(text, _T("最终得分:%d !"), map_msg->score);
			MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);

			// 记录得分
			if (map_msg->score > current_data->level_score[level][0])
			{
				current_data->level_score[level][0] = map_msg->score;
				sort(current_data->level_score[level], current_data->level_score[level] + 3);
			}

			current_data->num_death++;

			// 界面跳转
			pause_back = 0;
			scene_manager.SwitchTo(SceneManager::SceneType::Death);
		}
	}
}

void GameScene::OnDraw()
{
	// 绘制背景图
	putimage(0, 0, &img_game_background_1);

	if (level == 10)
	{
		putimage(0, 0, &img_game_background_2);
	}

	// 绘制平台
	for (Platform* platform : platform_list)
	{
		platform->OnDraw();
	}

	// 绘制玩家
	player->OnDraw();

	//绘制道具
	if (!item_list.empty())
	{
		if (current_item != nullptr)
		{
			current_item->OnDarw();
		}
	}

	//绘制信息
	map_msg->OnDraw();

	settextstyle(20, 0, _T("IPix"));
	// outtextxy(0, 0, _T("按Z开启调试模式"));
}

void GameScene::OnInput(const ExMessage& msg)
{
	// 玩家移动输入
	player->OnInput(msg);

	//道具输入
	if (!map_msg->item_choice.empty())
		if (current_item != nullptr)
			current_item->OnInput(msg);

	// 界面跳转
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case VK_ESCAPE:
			pause_back = true;
			scene_manager.SwitchTo(SceneManager::SceneType::Pause);
			break;
		case 'Z':
			if (is_debug)
				is_debug = false;
			else
				is_debug = true;
			break;
		case VK_CONTROL:
			if (!item_list.empty())
			{
				if (!current_item->is_in_duration())
				{
					current_item_num = (current_item_num + 1) % item_list.size();
					current_item = item_list[current_item_num];
				}
			}
			break;
		}
	}
}

void GameScene::OnExit()
{
	if (!pause_back)
	{
		delete player;
		delete map_msg;
		while (!item_list.empty())
		{
			auto x = item_list.back();
			item_list.pop_back();
			delete x;
			current_item = nullptr;
		}
	}
}

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	const int MOD = 100;
	// 间隔一段时间后更新平台
	// INTERVAL的值可能需要随平台速度改变
	int INTERVAL = 100;
	if (map_msg->speed > 0)
	{
		INTERVAL = (int)(100 / map_msg->speed);
	}
	else if (map_msg->speed <= 0)
	{
		INTERVAL = 2147483647;
	}
	static int counter = 0;

	static int cnt = 0;

	if ((++counter) % INTERVAL == 0)
	{
		//随机种类
		int seed = rand() % MOD + 1;
		int type = 0;
		int sum_weight = 0;
		for (int i = 0; i < 8; i++)
		{
			if (map_msg->platform_weight[i] != 0)
			{
				sum_weight += map_msg->platform_weight[i];
				if (seed <= sum_weight)
				{
					type = i;
					break;
				}
			}
			else
			{
				continue;
			}
		}
		if (type != 0)
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		if (cnt >= 5)
		{
			type = 0;
		}
		// 生成位置
		int generater_x = rand() % (500 - 100);
		// { AC, WA, NULL, speed, bounce, MLE, TLE, CE }
		switch (type)
		{
		case 0://AC
			// 将生成的平台加入链表
			platform_list.push_back(new ACPlatform(img_AC_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 1://WA
			// 将生成的平台加入链表
			platform_list.push_back(new WAPlatform(img_WA_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 2://NULL
			// 将生成的平台加入链表
			platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 3://speed
			// 将生成的平台加入链表
			platform_list.push_back(new speed_Platform(img_SPEED_RIGHT_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 4://bounce
			// 将生成的平台加入链表
			platform_list.push_back(new bounce_Platform(img_SPEED_LEFT_platform, map_msg));//有图了再说
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 5://MLE
			// 将生成的平台加入链表
			platform_list.push_back(new MLEPlatform(img_MLE_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 6://TLE
			// 将生成的平台加入链表
			platform_list.push_back(new TLEPlatform(img_TLE_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 7://CE
			// 将生成的平台加入链表
			platform_list.push_back(new CEPlatform(img_CE_platform, map_msg));
			// 设置初始位置
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		default:
			break;
		}
	}
}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list)
	{
		// 如果超出游戏范围
		if (platform->shape.top < -500 || platform->shape.top > 721)
		{
			platform->Disappear();
		}
	}

	for (size_t i = 0;i < platform_list.size();i++) {
		Platform* platform = platform_list[i];
		if (!platform->CheckExist())
		{

			// 将平台移出链表
			std::swap(platform_list[i], platform_list.back());
			platform_list.pop_back();
			// 清空内存
			delete platform;
		}
	}
}
//����
#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
//���
#include "../../player/player.h"
//ƽ̨
#include "../../platform/platform/platform.h"
#include "../../platform/AC_platform/AC_platform.h"
#include "../../platform/WA_platform/WA_platform.h"
#include "../../platform/NULL_platform/NULL_platform.h"
#include "../../platform/bounce_platform/bounce_platform.h"
#include "../../platform/CE_platform/CE_platform.h"
#include "../../platform/speed_platform/speed_platform.h"
#include "../../platform/TLE_platform/TLE_platform.h"
#include "../../platform/MLE_platform/MLE_platform.h"
//����
#include "../../items/item_carefully_BBQ/item_carefully_BBQ.h"
#include "../../items/item_ctrl_Z/item_ctrl_Z.h"
#include "../../items/item_helpme_awei/item_helpme_awei.h"
#include "../../items/item_hiraijin/item_hiraijin.h"
#include "../../items/item_once_again/item_once_again.h"
#include "../../items/item_the_world/item_the_world.h"

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

extern std::vector<Platform*> platform_list;

// ��ʼ����Ϸ����
// ������Ϸ����,���磺
// 1.���λ��
// 2.����
// 3.ƽ̨����,ƽ̨λ��
// ע��:
// 1.��ͣ������ת����,��Ӧ�����ò���
// 2.����������ת����,Ӧ�����ò���
void GameScene::OnEnter()
{
	// �������������
	srand((unsigned)time(NULL));

	// ��ʼ���ؿ���Ϣ
	map_msg = new Map_Msg(level);

	// ������ҳ�ʼλ��
	player = new Player(map_msg);
	player->SetPosition(200, 0);

	// ��ʼ��������Ϣ
	for (int i = 0;i<map_msg->item_choice.size();i++)
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
	}

	// ����ƽ̨����
	platform_list.clear();

	// ���ó�ʼ�ļ���ƽ̨
	platform_list.push_back(new ACPlatform(img_AC_platform, map_msg));
	platform_list.back()->SetPosition(0, 514);
	platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
	platform_list.back()->SetPosition(114, 414);
	platform_list.push_back(new WAPlatform(img_WA_platform, map_msg));
	platform_list.back()->SetPosition(100, 314);
	platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
	platform_list.back()->SetPosition(230, 214);
	platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
	platform_list.back()->SetPosition(214, 114);
}

// ������Ϸ����
// 1.�������λ��:
//		1.ˮƽ
//		2.��ֱ
// 2.����ƽ̨λ��:
//		1.����е��߿���,����һֱ�����ƶ�,
//		2.�ƶ����ٶȿ�������������Ӱ��(�ı�platform_speed)
// 3.��ײ�ж�:
//		1.����ƽ̨list
//		2.�޸������ֵ�����ٶ�
//		3.�޸Ķ������ֵ
// 4.ƽ̨���ˢ��:
//	
// 5.ƽ̨delete:
void GameScene::OnUpdate()
{
	// �����µ�ƽ̨��������
	GeneratePlatform(platform_list);

	if (!platform_list.empty())
	{
		for (Platform* platform : platform_list)
		{
			platform->OnUpdate();
		}
	}

	player->OnUpdate();

	if (current_item != nullptr)
		current_item->OnUpdate();

	// ɾ�������ƽ̨
	DeletePlatform(platform_list);

	if (!player->is_alive)
	{
		//player->is_alive = true;
		//scene_manager.SwitchTo(SceneManager::SceneType::Death);
	}
}

void GameScene::OnDraw()
{
	// ���Ʊ���ͼ
	putimage(0, 0, &img_game_background_1);

	// ����ƽ̨
	for (Platform* platform : platform_list)
	{
		platform->OnDraw();
	}

	// �������
	player->OnDraw();

	//���Ƶ���
	if(current_item!=nullptr)
		current_item->OnDarw();

	//������Ϣ
	map_msg->OnDraw();

	settextstyle(20, 0, _T("IPix"));
	outtextxy(0, 0, _T("��Z��������ģʽ"));
}

void GameScene::OnInput(const ExMessage& msg)
{
	// ����ƶ�����
	player->OnInput(msg);

	//��������
	if (current_item != nullptr)
		current_item->OnInput(msg);

	// ������ת
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
		case VK_CONTROL:
			if (!item_list.empty())
			{
				current_item_num = (current_item_num + 1) % item_list.size();
				current_item = item_list[current_item_num];
			}
			break;
		}
	}
}

void GameScene::OnExit()
{
	delete player;
	delete map_msg;
	for (auto i = item_list.begin(); i != item_list.end(); i++)
	{
		delete* i;
	}
}

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	// ������һ�����
	// ������һ�����	
	// ������һ�����
	// ������һ�����
	// ������һ�����
	// ������һ�����
	const int MOD = 100;
	// ���һ��ʱ������ƽ̨
	// INTERVAL��ֵ������Ҫ��ƽ̨�ٶȸı�
	const int INTERVAL = 100;
	static int counter = 0;

	if ((++counter) % INTERVAL == 0)
	{
		//�������
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
		// ����λ��
		int generater_x = rand() % (500-100);
		// { AC, WA, NULL, speed, bounce, MLE, TLE, CE }
		switch (type)
		{
		case 0://AC
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new ACPlatform(img_AC_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 1://WA
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new WAPlatform(img_WA_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 2://NULL
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new NULLPlatform(img_NULL_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 3://speed
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new speed_Platform(img_SPEED_RIGHT_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 4://bounce
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new bounce_Platform(img_NULL_platform, map_msg));//��ͼ����˵
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 5://MLE
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new MLEPlatform(img_MLE_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 6://TLE
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new TLEPlatform(img_TLE_platform, map_msg));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
			break;
		case 7://CE
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new CEPlatform(img_CE_platform, map_msg));
			// ���ó�ʼλ��
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
		// ���������Ϸ��Χ
		if (platform->shape.top < -500 || platform->shape.top > 730)
		{
			platform->Disappear();
		}
	}

	for (size_t i = 0;i < platform_list.size();i++) {
		Platform* platform = platform_list[i];
		if (!platform->CheckExist())
		{
			// ��ƽ̨�Ƴ�[����
			std::swap(platform_list[i], platform_list.back());
			platform_list.pop_back();
			// ����ڴ�
			delete platform;
		}
	}
}
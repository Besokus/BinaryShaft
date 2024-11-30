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

	// ������ҳ�ʼλ��
	player->SetPosition(200, 0);

	//��ʼ���ؿ���Ϣ
	map_msg=new Map_Msg(level);

	// ����ƽ̨����
	platform_list.clear();

	// ���ó�ʼ�ļ���ƽ̨
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


	settextstyle(20, 0, _T("IPix"));
	outtextxy(0, 0, _T("��Z��������ģʽ"));
	// ���Ʒ���
	// 
	// outtext(); // level(�ؿ���) living_time(���ʱ��) memory_size(��ͼ��С)
}

void GameScene::OnInput(const ExMessage& msg)
{
	// ����ƶ�����
	player->OnInput(msg);

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
		}
	}
}

void GameScene::OnExit()
{

}

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	// ������һ�����
	// ������һ�����	
	// ������һ�����
	// ������һ�����
	// ������һ�����
	// ������һ�����
	const int MOD = 10;
	// ���һ��ʱ������ƽ̨
	// INTERVAL��ֵ������Ҫ��ƽ̨�ٶȸı�
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

		// ����λ��
		int generater_x = rand() % (500-100);

		if (seed <= 4 && seed >= 0) 
		{
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new NULLPlatform(img_NULL_platform));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 5) 
		{
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new ACPlatform(img_AC_platform));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 6 || seed == 7)
		{
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new WAPlatform(img_WA_platform));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 8)
		{
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new WAPlatform(img_SPEED_RIGHT_platform));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
		}
		else if (seed == 9)
		{
			// �����ɵ�ƽ̨��������
			platform_list.push_back(new WAPlatform(img_SPEED_LEFT_platform));
			// ���ó�ʼλ��
			platform_list.back()->SetPosition(generater_x, 720);
		}

	}
}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list)
	{
		// ���������Ϸ��Χ
		if (platform->shape.top < 0)
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
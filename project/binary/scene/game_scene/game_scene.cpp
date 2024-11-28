#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"

extern bool is_debug;
extern int level;

extern IMAGE img_menu_background;
extern IMAGE img_AC_platform;

extern SceneManager scene_manager;

extern Player* player;

extern Platform* AC_platform;
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
	// ������ҳ�ʼλ��
	player->SetPosition(514, 0);


	// ����ƽ̨����
	platform_list.clear();

	// ���ó�ʼ�ļ���ƽ̨
	platform_list.push_back(new Platform(img_AC_platform));
	platform_list.back()->SetPosition(570, 514);
	platform_list.push_back(new Platform(img_AC_platform));
	platform_list.back()->SetPosition(330, 414);
	platform_list.push_back(new Platform(img_AC_platform));
	platform_list.back()->SetPosition(430, 314);
	platform_list.push_back(new Platform(img_AC_platform));
	platform_list.back()->SetPosition(500, 214);
	platform_list.push_back(new Platform(img_AC_platform));
	platform_list.back()->SetPosition(514, 114);
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
}

void GameScene::OnDraw()
{
	// ���Ʊ���ͼ
	putimage(0, 0, &img_menu_background);

	// ����ƽ̨
	for (Platform* platform : platform_list)
	{
		platform->OnDraw();
	}

	// �������


	player->OnDraw();


	// ������Ϸ����
	// 
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
	const int MOD = 10;
	// ���һ��ʱ������ƽ̨
	// INTERVAL��ֵ������Ҫ��ƽ̨�ٶȸı�
	const int INTERVAL = 100;
	static int counter = 0;

	if ((++counter) % INTERVAL == 0)
	{
		int seed = rand() % MOD;

		// ���ø���,���ɲ�ͬ��ƽ̨
		// switch(seed){...}

		// ����λ��
		int generater_x = rand() % 300 + 300;

		// �����ɵ�ƽ̨��������
		platform_list.push_back(new Platform(img_AC_platform));
		// ���ó�ʼλ��
		platform_list.back()->SetPosition(generater_x, 720);
	}
}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list)
	{
		// ���������Ϸ��Χ
		if (platform->shape.y < 0)
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
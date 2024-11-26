#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"


extern int level;

extern SceneManager scene_manager;

extern Player* player;

extern std::vector<Platform*> platform_list;

// ��ʼ����Ϸ����
// ������Ϸ����,���磺
// 1.���λ��
// 2.����
// 3.ƽ̨����,ƽ̨λ��
void GameScene::OnEnter()
{
	player = new Player();
	player->SetPosition(114, 514);
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
	player->OnUpdate();

	// �����µ�ƽ̨��������
	GeneratePlatform(platform_list);

	// ���������ڳ����е�ƽ̨,��������·���
	for (Platform* platform : platform_list)
	{
		platform->OnUpdate();
	}

	DeletePlatform(platform_list);
}

void GameScene::OnDraw()
{
	outtextxy(10, 10, _T("��Ϸ��ͼ����"));
	static TCHAR text[64];
	_stprintf_s(text, _T("level:%d"), level + 1);
	outtextxy(10, 50, text);
	outtextxy(10, 70, _T("P��ͣ ESC�˳������˵�"));

	// �������
	// player->OnDraw();
	// 
	// ����ƽ̨
	// for (Platform* platform : platform_list) 
	// {
	// 	  platform->OnDraw();
	// }
	//
	// ������Ϸ����
	// 
	// 
	// ���Ʒ���
	// 
	// outtext(); // level(�ؿ���) living_time(���ʱ��) memory_size(��ͼ��С)

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
	std::cout << "��Ϸ�˳�" << std::endl;
}

void GameScene::GeneratePlatform(std::vector<Platform*>& platform_list)
{
	// ���һ��ʱ������ƽ̨
	// INTERVAL��ֵ������Ҫ��ƽ̨�ٶȸı�
	const int INTERVAL = 200;
	static int counter = 0;
	if ((++counter) % INTERVAL == 0)
	{
		// int seed = rand() % MOD;
		// ���ø���,���ɲ�ͬ��ƽ̨
		// switch(seed){...}
		// platform_list.push_back(new NULL_Platform());
		// platform_list.push_back(new NULL_Platform());
	}

}

void GameScene::DeletePlatform(std::vector<Platform*>& platform_list)
{
	for (Platform* platform : platform_list) {

		// �˴�д������λ���ж�
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
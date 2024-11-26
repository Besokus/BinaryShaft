#include "game_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../player/player.h"
#include "../../platform/platform/platform.h"

extern SceneManager scene_manager;
extern Player *player;
extern int level;
extern std::vector<Platform*> platform_list;

// ��ʼ����Ϸ����
// ������Ϸ����,���磺
// 1.���λ��
// 2.����
// 3.ƽ̨����,ƽ̨λ��
void GameScene::OnEnter()
{
	player = new Player();
	player->SetPosition(114,514);
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
	for (Platform* platform : platform_list) 
	{
		if (platform->CheckCollision(*player)) 
		{
		
		
		}
	}
}

// 1.�������
// 2.����ƽ̨
// 3.���ƴ���
// 4.���Ʒ���
//		1.AC
//		2.time
//		3.memory
// 
//
void GameScene::OnDraw()
{
	outtextxy(10, 10, _T("��Ϸ��ͼ����"));
	static TCHAR text[64];
	_stprintf_s(text, _T("level:%d"), level + 1);
	outtextxy(10, 50, text);
	
	outtextxy(10, 70, _T("P��ͣ ESC�˳������˵�"));

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
	std::cout << "��Ϸ�˳�" << std::endl;
}

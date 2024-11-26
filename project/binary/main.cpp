#include <graphics.h>
#include "animation/animation.h"
#include "atlas/atlas.h"
#include "platform/platform/platform.h"
#include "player/player.h"
#include "scene/menu_scene/menu_scene.h"
#include "scene/select_level_scene/select_level_scene.h"
#include "scene/pause_scene/pause_scene.h"
#include "scene/set_up_scene/set_up_scene.h"

// ȥ��GetTickCount()�����ľ���
#pragma warning(disable:28159)

extern bool running;

extern SceneManager scene_manager;
extern Scene* menu_scene;
extern Scene* game_scene;
extern Scene* pause_scene;
extern Scene* select_Level_scene;

extern std::vector<Platform*> platform_list;

extern void LoadGameResources();

int main()
{

	ExMessage msg;
	const int FPS = 60;

	LoadGameResources();

	initgraph(1280, 720, EW_SHOWCONSOLE);// ��ʾ���ÿ���̨
	// initgraph(1280, 720);

	// ��ʼ������


	// ��ʼ������Ϊ�˵�
	scene_manager.SetCurrentScene(menu_scene);

	// ��Ⱦ��������,��EndBatchDraw(),FlushBatchDraw()����һ��ʹ��
	BeginBatchDraw();

	while (running)
	{
		DWORD start_time = GetTickCount();

		// ��������
		while (peekmessage(&msg))
		{
			scene_manager.OnInput(msg);
		}

		// ������������,��������
		scene_manager.OnUpdate();

		// ���ԭʼ����
		cleardevice();
		// ���ݸ�������,�����»���
		scene_manager.OnDraw();
		FlushBatchDraw();

		// �ȶ�֡��
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / FPS)
			Sleep(1000 / FPS - delta_time);
	}

	EndBatchDraw();

	return 0;
}
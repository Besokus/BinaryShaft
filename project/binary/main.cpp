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
extern void ReadData();
extern void WriteData();

int main()
{
	ExMessage msg;
	const int FPS = 144;

	// ������Ϸ�ز���Դ
	LoadGameResources();
	// ��ȡ��Ϸ�洢����
	ReadData();

	initgraph(700, 700, EX_SHOWCONSOLE);

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
		//line(500, 0, 500, 700);
		FlushBatchDraw();

		// �ȶ�֡��
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / FPS)
			Sleep(1000 / FPS - delta_time);
	}

	EndBatchDraw();

	WriteData();

	return 0;
}
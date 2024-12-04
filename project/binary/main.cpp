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

// mciSendString
#pragma comment(lib,"Winmm.lib")

extern bool running;

extern SceneManager scene_manager;
extern Scene* CG_scene;

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

	initgraph(700, 700);

	// ��ʼ������Ϊ�˵�
	scene_manager.SetCurrentScene(CG_scene);

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
	
	// д����Ϸ����
	WriteData();

	return 0;
}
#include <graphics.h>
#include "animation/animation.h"
#include "atlas/atlas.h"
#include "platform/platform/platform.h"
#include "player/player.h"
#include "scene/menu_scene/menu_scene.h"
#include "scene/select_level_scene/select_level_scene.h"
#include "scene/pause_scene/pause_scene.h"
#include "scene/set_up_scene/set_up_scene.h"

// 去除GetTickCount()函数的警告
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

	// 导入游戏素材资源
	LoadGameResources();
	// 读取游戏存储数据
	ReadData();

	initgraph(700, 700, EX_SHOWCONSOLE);

	// 初始化场景为菜单
	scene_manager.SetCurrentScene(menu_scene);

	// 渲染辅助函数,与EndBatchDraw(),FlushBatchDraw()搭配一起使用
	BeginBatchDraw();

	while (running)
	{
		DWORD start_time = GetTickCount();

		// 接受输入
		while (peekmessage(&msg))
		{
			scene_manager.OnInput(msg);
		}

		// 根据输入内容,更新数据
		scene_manager.OnUpdate();

		// 清空原始画面
		cleardevice();
		// 根据更新内容,绘制新画面
		scene_manager.OnDraw();
		//line(500, 0, 500, 700);
		FlushBatchDraw();

		// 稳定帧数
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / FPS)
			Sleep(1000 / FPS - delta_time);
	}

	EndBatchDraw();

	WriteData();

	return 0;
}
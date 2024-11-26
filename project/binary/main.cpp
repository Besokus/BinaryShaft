#include <graphics.h>
#include "animation/animation.h"
#include "atlas/atlas.h"
#include "global/global.h"
#include "platform/platform/platform.h"
#include "player/player.h"
#include "scene/scene/scene.h"
#include "scene/game_scene/game_scene.h"
#include "scene/menu_scene/menu_scene.h"
#include "scene/select_level_scene/select_level_scene.h"
#include "scene/pause_scene/pause_scene.h"

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

int main()
{
	ExMessage msg;
	const int FPS = 60;

	LoadGameResources();

	initgraph(1280, 720, EW_SHOWCONSOLE);// 显示外置控制台
	// initgraph(1280, 720);

	// 初始化界面
	menu_scene = new MenuScene();
	game_scene = new GameScene();
	select_Level_scene = new SelectLevelScene();
	pause_scene =new PauseScene();

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
		FlushBatchDraw();

		// 稳定帧数
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / FPS)
			Sleep(1000 / FPS - delta_time);
	}

	EndBatchDraw();

	return 0;
}
/*
	负责人:ja1u0va
	功能:
		1.定义全局变量





*/
#include "scene/scene_manager/scene_manager.h"
#include "scene/scene/scene.h"
#include "scene/game_scene/game_scene.h"
#include "scene/menu_scene/menu_scene.h"
#include "scene/select_level_scene/select_level_scene.h"
#include "scene/pause_scene/pause_scene.h"
#include "scene/set_up_scene/set_up_scene.h"
#include "player/player.h"
#include "platform/platform/platform.h"
#include "button/button/button.h"
#include <vector>

extern const int WINDOW_WIDTH = 1280;
extern const int WINDOW_HEIGHT = 720;
extern const int BUTTON_WIDTH = 175;
extern const int BUTTON_HEIGHT = 45;

// 定义bool变量
bool running = true;

int level = 0;

// 定义图片对象
// example:
// IMAGE img_menu_background;
// img_(class)_(xxx)_(status)_(direction)
//IMAGE img_menu_background;
IMAGE img_menu_background;

IMAGE img_menu_start_idle;
IMAGE img_menu_start_hovered;
IMAGE img_menu_start_pushed;

IMAGE img_menu_find_idle;
IMAGE img_menu_find_hovered;
IMAGE img_menu_find_pushed;

IMAGE img_menu_setup_idle;
IMAGE img_menu_setup_hovered;
IMAGE img_menu_setup_pushed;

// 定义图集对象
// example:
// Atlas atlas_peashooter_idle_left;
// atlas_(class)_(status)_(direction)


// 定义按钮对象
StartButton* btn_menu_start = nullptr;
FindButton* btn_menu_find = nullptr;
SetUpButton* btn_menu_setup = nullptr;

// 定义按钮的区域
RECT region_menu_start;
RECT region_menu_find;
RECT region_menu_setup;

// 定义场景对象
Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* select_level_scene = nullptr;
Scene* pause_scene = nullptr;
Scene* setup_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;

SceneManager scene_manager;

// 定义玩家对象
Player* player = nullptr;

// 定义平台对象
// 
std::vector<Platform*> platform_list;

void LoadGameResources()
{
	menu_scene = new MenuScene();
	game_scene = new GameScene();
	select_level_scene = new SelectLevelScene();
	pause_scene = new PauseScene();
	setup_scene = new SetUpScene();

	// 导入菜单背景
	loadimage(&img_menu_background, _T("resources/menu_background.png"));

	// 导入start按键素材并且设置其范围
	region_menu_start.left = 300;
	region_menu_start.right = region_menu_start.left + BUTTON_WIDTH;
	region_menu_start.top = 235;
	region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

	btn_menu_start = new StartButton(region_menu_start,
		_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

	// 导入find按键素材并且设置其范围
	region_menu_find.left = 300;
	region_menu_find.right = region_menu_find.left + BUTTON_WIDTH;
	region_menu_find.top = 365;
	region_menu_find.bottom = region_menu_find.top + BUTTON_HEIGHT;

	btn_menu_find = new FindButton(region_menu_find,
		_T("resources/menu_find_idle.png"), _T("resources/menu_find_hovered.png"), _T("resources/menu_find_pushed.png"));

	region_menu_setup.left = 300;
	region_menu_setup.right = region_menu_setup.left + BUTTON_WIDTH;
	region_menu_setup.top = 495;
	region_menu_setup.bottom = region_menu_setup.top + BUTTON_HEIGHT;

	btn_menu_setup = new SetUpButton(region_menu_setup,
		_T("resources/menu_setup_idle.png"), _T("resources/menu_setup_hovered.png"), _T("resources/menu_setup_pushed.png"));

}
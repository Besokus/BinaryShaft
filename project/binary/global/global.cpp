/*
	负责人:ja1u0va
	功能:
		1.定义全局变量





*/
#include "../scene/scene_manager/scene_manager.h"
#include "../scene/scene/scene.h"
#include "../player/player.h"
#include "../platform/platform/platform.h"
#include <vector>


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


bool running = true;

int level = 0;


Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* select_Level_scene = nullptr;
Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;

SceneManager scene_manager;

Player* player = nullptr;
std::vector<Platform*> platform_list;


void LoadGameResources()
{
	loadimage(&img_menu_background, _T("resources/menu_background.png"));
	loadimage(&img_menu_start_idle, _T("../resources/menu_start_idle.png"));
	loadimage(&img_menu_start_hovered, _T("../resources/menu_start_hovered.png"));
	loadimage(&img_menu_start_pushed, _T("../resources/menu_start_pushed.png"));

}
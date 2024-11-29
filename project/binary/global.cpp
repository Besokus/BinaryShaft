/*
	负责人:ja1u0va
	功能:
		1.定义全局变量

*/

#include <vector>

// 场景相关头文件
#include "scene/game_scene/game_scene.h"					// 游戏界面
#include "scene/menu_scene/menu_scene.h"					// 菜单界面
//#include "scene/achievement_scene/achievement_scene.h"		// 成就界面
#include "scene/death_scene/death_scene.h"					// 死亡界面
#include "scene/select_mode_scene/select_mode_scene.h"		// 选择模式界面
#include "scene/pause_scene/pause_scene.h"					// 暂停界面
#include "scene/scene/scene.h"								// 场景基类
#include "scene/scene_manager/scene_manager.h"				// 场景管理器
#include "scene/select_level_scene/select_level_scene.h"	// 选择关卡界面
#include "scene/set_up_scene/set_up_scene.h"				// 设置界面

// 玩家相关头文件
#include "player/player.h"

// 平台相关头文件
#include "platform/platform/platform.h"

// 按钮相关头文件
#include "button/button/button.h"

// 菜单按钮
#include "button/menu_button/menu_start_button.h"
#include "button/menu_button/menu_setup_button.h"


extern void FlipAtlas(Atlas& src, Atlas& dst);

extern const int PLAYER_WIDTH = 70;
extern const int PLAYER_HEIGHT = 70;

extern const int PLATFORM_WIDTH = 100;
extern const int PLATFORM_HEIGHT = 10;


extern const int WINDOW_WIDTH = 720;
extern const int WINDOW_HEIGHT = 1280;
extern const int BUTTON_WIDTH = 175;
extern const int BUTTON_HEIGHT = 45;


// 定义bool变量
bool running = true;
bool is_debug = false;

int level = 0;

// 定义图片对象
IMAGE img_menu_background;
IMAGE img_game_background_1;

IMAGE img_menu_start_idle;
IMAGE img_menu_start_hovered;
IMAGE img_menu_start_pushed;

IMAGE img_menu_find_idle;
IMAGE img_menu_find_hovered;
IMAGE img_menu_find_pushed;

IMAGE img_player_idle;

IMAGE img_AC_platform;


// 定义图集对象
Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_player_fall_idle;

// 定义按钮对象
MenuStartButton* btn_menu_start = nullptr;// btn button


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


SceneManager scene_manager;

Animation* animation_player_left = nullptr;
Animation* animation_player_right = nullptr;
Animation* animation_player_idle = nullptr;
Animation* animation_player_fall_idle = nullptr;

// 定义玩家对象
Player* player = nullptr;

// 定义平台对象
// Platform 

Platform* AC_platform = nullptr;
std::vector<Platform*> platform_list;

// 成就
//std::vector<Achievement*> achievement_list;

void LoadImageAndAtlas()
{
	// 导入菜单背景
	loadimage(&img_menu_background, _T("resources/menu_background.png"));
	// 导入菜单背景
	loadimage(&img_game_background_1, _T("resources/game_background_1.png"));

	// 玩家默认图片
	loadimage(&img_player_idle, _T("resources/player_idle_1.png"), PLAYER_WIDTH, PLAYER_HEIGHT);

	// 玩家向左图集
	atlas_player_left.LoadFromFile(_T("resources/left_walk_%d.png"), 6);
	// 玩家向右图集
	FlipAtlas(atlas_player_left, atlas_player_right);

	atlas_player_fall_idle.LoadFromFile(_T("resources/idle_fall_%d.png"), 5);

	// 导入AC平台
	loadimage(&img_AC_platform, _T("resources/AC_platform.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
}


void LoadButton()
{
	// 导入start按键素材并且设置其范围
	// 设定范围region
	region_menu_start.left = 300;
	region_menu_start.right = region_menu_start.left + BUTTON_WIDTH;
	region_menu_start.top = 235;
	region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

	// 导入素材
	btn_menu_start = new MenuStartButton(region_menu_start,
		_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

	
}

void LoadGameResources()
{
	menu_scene = new MenuScene();
	game_scene = new GameScene();
	select_level_scene = new SelectLevelScene();
	pause_scene = new PauseScene();
	setup_scene = new SetUpScene();


	animation_player_left = new Animation();
	animation_player_right = new Animation();
	animation_player_fall_idle = new Animation();

	player = new Player();

	LoadButton();

	LoadImageAndAtlas();

	animation_player_left->SetAtlas(&atlas_player_left);
	animation_player_right->SetAtlas(&atlas_player_right);
	animation_player_fall_idle->SetAtlas(&atlas_player_fall_idle);


}



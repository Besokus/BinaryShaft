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

// 关卡相关头文件
#include "map/map.h"

// 玩家相关头文件
#include "player/player.h"

// 平台相关头文件
#include "platform/platform/platform.h"

// 按钮相关头文件
#include "button/button/button.h"
#include "button/menu_button/menu_button.h"
#include "button/select_mode_button/select_mode_button.h"


extern void FlipAtlas(Atlas& src, Atlas& dst);


extern const int PLAYER_WIDTH = 70;		  // 玩家宽度
extern const int PLAYER_HEIGHT = 70;	  // 玩家高度

extern const int PLATFORM_WIDTH = 100;	  // 平台宽度
extern const int PLATFORM_HEIGHT = 30;	  // 平台高度


extern const int WINDOW_WIDTH = 700;	  // 窗口宽度
extern const int WINDOW_HEIGHT = 700;	  // 窗口高度

extern const int LEVEL_NUM = 10;

// 定义bool变量
bool running = true;	// 游戏运行
bool is_debug = false;  // 调试模式


// 定义游戏全局参数
int level = 0;          //关卡数


// 定义图片对象
// 背景图
// 菜单
IMAGE img_menu_background;
// 选择模式
IMAGE img_select_mode_background;
// 选择关卡
IMAGE img_select_level_background;
// 普通模式
IMAGE img_game_background_1;
// 死亡
IMAGE img_death_background;

// 玩家默认图片
IMAGE img_player_idle;

// 平台
IMAGE img_NULL_platform;
IMAGE img_AC_platform;
IMAGE img_WA_platform;
IMAGE img_CE_platform;
IMAGE img_SPEED_RIGHT_platform;
IMAGE img_SPEED_LEFT_platform;
IMAGE img_TLE_platform;
IMAGE img_MLE_platform;

// 定义图集对象
Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_player_fall_idle;

// 定义按钮对象
// 菜单
MenuStartButton* btn_menu_start = nullptr;// btn button
MenuSetUpButton* btn_menu_setup = nullptr;
MenuShowDetailButton* btn_menu_show_detail = nullptr;
MenuRankButton* btn_menu_rank = nullptr;
MenuAchievementButton* btn_menu_achievement = nullptr;
MenuExitButton* btn_menu_exit = nullptr;
// 选择模式
SelectModeNormalButton* btn_select_mode_normal = nullptr;// btn button
SelectModeChallengeButton* btn_select_mode_challenge = nullptr;
SelectModeReturnButton* btn_select_mode_return = nullptr;


// 定义按钮的区域
// 菜单
RECT region_menu_start;
RECT region_menu_show_detail;
RECT region_menu_setup;
RECT region_menu_rank;
RECT region_menu_achievement;
RECT region_menu_exit;
// 选择模式
RECT region_select_mode_normal;
RECT region_select_mode_challenge;
RECT region_select_mode_return;

// 定义场景对象
Scene* game_scene = nullptr;
Scene* menu_scene = nullptr;
Scene* achievement_scene = nullptr;
Scene* death_scene = nullptr;
Scene* select_mode_scene = nullptr;
Scene* pause_scene = nullptr;
Scene* select_level_scene = nullptr;
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

std::vector<Platform*> platform_list;

// 成就
//std::vector<Achievement*> achievement_list;
struct Map_massage map_massage[11] =
{
	//速度、通关分数、{AC, WA, NULL, speed, bounce, MLE, TLE, CE}、
	//{仔细烧烤、回溯、阿伟助我、飞雷神、再来一次、世界！（时停）}
	{1.0f, 100, {40,20,20,10,10,0,0,0}, {0,0,0,0,0,0} },
	{1.0f, 100, {40,20,20,10,10,0,0,0}, {0,0,1,0,0,0} },
	{1.0f, 100, {40,20,10,10,10,10,0,0}, {0,0,1,0,0,0} },
	{1.3f, 100, {40,20,10,10,5,5,0,0}, {0,0,1,0,0,1} },
	{1.3f, 100, {40,20,10,5,5,5,5,10}, {0,0,1,0,1,1} },
	{1.3f, 100, {40,20,5,5,5,0,24,1}, {0,1,0,0,1,1} },
	{1.5f, 100, {40,20,5,5,5,24,0,1}, {1,0,0,0,1,1} },
	{1.5f, 100, {30,20,10,10,10,10,10,0}, {0,1,1,1,0,0} },
	{1.5f, 100, {30,20,10,10,10,0,0,20}, {0,0,1,1,0,1} },
	{1.8f, 100, {25,25,5,5,5,15,15,5}, {1,1,0,0,0,1} },
	{1.0f, 2147483647, {40,20,20,10,10,0,0,0}, {0,0,0,0,0,0} }
};

void LoadImageAndAtlas()
{
	// 导入菜单背景
	loadimage(&img_menu_background, _T("resources/menu_background.png"));

	// 导入选择模式背景
	loadimage(&img_select_mode_background, _T("resources/select_mode_background.png"));

	// 导入选择关卡背景
	loadimage(&img_select_level_background, _T("resources/select_level_background.png"));

	// 导入普通游戏背景
	loadimage(&img_game_background_1, _T("resources/game_background_1.png"));

	// 导入死亡背景
	loadimage(&img_death_background, _T("resources/game_over.png"));

	// 玩家默认图片
	loadimage(&img_player_idle, _T("resources/player_idle_1.png"), PLAYER_WIDTH, PLAYER_HEIGHT);

	// 玩家向左图集
	atlas_player_left.LoadFromFile(_T("resources/left_walk_%d.png"), 6);
	// 玩家向右图集
	FlipAtlas(atlas_player_left, atlas_player_right);
	// 玩家下坠图集
	atlas_player_fall_idle.LoadFromFile(_T("resources/idle_fall_%d.png"), 5);


	loadimage(&img_NULL_platform, _T("resources/NULL.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_AC_platform, _T("resources/AC.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_WA_platform, _T("resources/WA.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_CE_platform, _T("resources/CE.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_SPEED_RIGHT_platform, _T("resources/SPEED_RIGHT.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_SPEED_LEFT_platform, _T("resources/SPEED_LEFT.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_TLE_platform, _T("resources/TLE.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
	loadimage(&img_MLE_platform, _T("resources/MLE.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
}


void LoadButton()
{
	// 菜单按钮
	const int MENU_BUTTON_WIDTH = 115;
	const int MENU_BUTTON_HEIGHT = 45;

	// 导入start_game(开始游戏)按键素材并且设置其范围
	region_menu_start.left = 200;
	region_menu_start.right = region_menu_start.left + MENU_BUTTON_WIDTH;
	region_menu_start.top = 210;
	region_menu_start.bottom = region_menu_start.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_start = new MenuStartButton(region_menu_start,
		_T("resources/menu_start_game_idle.png"), _T("resources/menu_start_game_hovered.png"), _T("resources/menu_start_game_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// 导入show_detail(游戏说明)按键素材并且设置其范围
	region_menu_show_detail.left = 200;
	region_menu_show_detail.right = region_menu_show_detail.left + MENU_BUTTON_WIDTH;
	region_menu_show_detail.top = 280;
	region_menu_show_detail.bottom = region_menu_show_detail.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_show_detail = new MenuShowDetailButton(region_menu_show_detail,
		_T("resources/menu_show_detail_idle.png"), _T("resources/menu_show_detail_hovered.png"), _T("resources/menu_show_detail_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// 导入setup(游戏设置)按键素材并且设置其范围
	region_menu_setup.left = 200;
	region_menu_setup.right = region_menu_setup.left + MENU_BUTTON_WIDTH;
	region_menu_setup.top = 350;
	region_menu_setup.bottom = region_menu_setup.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_setup = new MenuSetUpButton(region_menu_setup,
		_T("resources/menu_setup_idle.png"), _T("resources/menu_setup_hovered.png"), _T("resources/menu_setup_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// 导入rank(排行榜)按键素材并且设置其范围
	region_menu_rank.left = 370;
	region_menu_rank.right = region_menu_rank.left + MENU_BUTTON_WIDTH;
	region_menu_rank.top = 210;
	region_menu_rank.bottom = region_menu_rank.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_rank = new MenuRankButton(region_menu_rank,
		_T("resources/menu_rank_idle.png"), _T("resources/menu_rank_hovered.png"), _T("menu_rank_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// 导入achievement(成就)按键素材并且设置其范围
	region_menu_achievement.left = 370;
	region_menu_achievement.right = region_menu_achievement.left + MENU_BUTTON_WIDTH;
	region_menu_achievement.top = 280;
	region_menu_achievement.bottom = region_menu_achievement.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_achievement = new MenuAchievementButton(region_menu_achievement,
		_T("resources/menu_achievement_idle.png"), _T("resources/menu_achievement_hovered.png"), _T("resources/menu_achievement_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// 导入exit(退出游戏)按键素材并且设置其范围
	region_menu_exit.left = 370;
	region_menu_exit.right = region_menu_exit.left + MENU_BUTTON_WIDTH;
	region_menu_exit.top = 350;
	region_menu_exit.bottom = region_menu_exit.top + MENU_BUTTON_HEIGHT;

	// 导入素材
	btn_menu_exit = new MenuExitButton(region_menu_exit,
		_T("resources/menu_exit_idle.png"), _T("resources/menu_exit_hovered.png"), _T("resources/menu_exit_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);

	//--------------------------------------------------------------------------------------------------------------------------

	// 选择模式按钮
	const int SELECT_MODE_BUTTON_WIDTH = 155;
	const int SELECT_MODE_BUTTON_HEIGHT = 60;

	// 导入normal(普通模式)按键素材并且设置其范围
	region_select_mode_normal.left = 260;
	region_select_mode_normal.right = region_select_mode_normal.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_normal.top = 190;
	region_select_mode_normal.bottom = region_select_mode_normal.top + SELECT_MODE_BUTTON_HEIGHT;

	// 导入素材
	btn_select_mode_normal = new SelectModeNormalButton(region_select_mode_normal,
		_T("resources/select_mode_normal_idle.png"), _T("resources/select_mode_normal_hovered.png"), _T("resources/select_mode_normal_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);

	// 导入challenge(挑战模式)按键素材并且设置其范围
	region_select_mode_challenge.left = 260;
	region_select_mode_challenge.right = region_select_mode_challenge.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_challenge.top = 280;
	region_select_mode_challenge.bottom = region_select_mode_challenge.top + SELECT_MODE_BUTTON_HEIGHT;

	// 导入素材
	btn_select_mode_challenge = new SelectModeChallengeButton(region_select_mode_challenge,
		_T("resources/select_mode_challenge_idle.png"), _T("resources/select_mode_challenge_hovered.png"), _T("resources/select_mode_challenge_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);


	// 导入return(返回菜单)按键素材并且设置其范围
	region_select_mode_return.left = 260;
	region_select_mode_return.right = region_select_mode_return.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_return.top = 370;
	region_select_mode_return.bottom = region_select_mode_return.top + SELECT_MODE_BUTTON_HEIGHT;

	// 导入素材
	btn_select_mode_return = new SelectModeReturnButton(region_select_mode_return,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);

}

void LoadGameResources()
{
	// 导入字体资源
	AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

	game_scene = new GameScene();
	menu_scene = new MenuScene();
	// achievement_scene = new AchievementScene();
	death_scene = new DeathScene();
	// show_detail_scene = new ShowDetailScene();
	select_mode_scene = new SelectModeScene();
	pause_scene = new PauseScene();
	select_level_scene = new SelectLevelScene();
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
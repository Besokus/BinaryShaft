/*
	������:ja1u0va
	����:
		1.����ȫ�ֱ���





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
#include "button/menu_button/menu_start_button.h"
#include "button/menu_button/menu_setup_button.h"
#include <vector>

extern void FlipAtlas(Atlas& src, Atlas& dst);

extern const int PLAYER_WIDTH = 70;
extern const int PLAYER_HEIGHT = 70;

extern const int PLATFORM_WIDTH = 100;
extern const int PLATFORM_HEIGHT = 10;


extern const int WINDOW_WIDTH = 1280;
extern const int WINDOW_HEIGHT = 720;
extern const int BUTTON_WIDTH = 175;
extern const int BUTTON_HEIGHT = 45;


// ����bool����
bool running = true;
bool is_debug = false;

int level = 0;

// ����ͼƬ����
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

IMAGE img_AC_platform;


// ����ͼ������
// example:
// Atlas atlas_peashooter_idle_left;
// atlas_(class)_(status)_(direction)
IMAGE img_player_idle;

Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_player_fall_idle;

// ���尴ť����
MenuStartButton* btn_menu_start = nullptr;// btn button
FindButton* btn_menu_find = nullptr;
MenuSetUpButton* btn_menu_setup = nullptr;

// ���尴ť������
RECT region_menu_start;
RECT region_menu_find;
RECT region_menu_setup;

// ���峡������
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

Animation* animation_player_left = nullptr;
Animation* animation_player_right = nullptr;
Animation* animation_player_idle = nullptr;
Animation* animation_player_fall_idle = nullptr;

// ������Ҷ���
Player* player = nullptr;

// ����ƽ̨����
// Platform 

Platform* AC_platform = nullptr;
std::vector<Platform*> platform_list;

void LoadImageAndAtlas()
{
	// ����˵�����
	loadimage(&img_menu_background, _T("resources/menu_background.png"));

	// ���Ĭ��ͼƬ
	loadimage(&img_player_idle, _T("resources/player_idle_1.png"), PLAYER_WIDTH, PLAYER_HEIGHT);

	// �������ͼ��
	atlas_player_left.LoadFromFile(_T("resources/left_walk_%d.png"), 6);
	// �������ͼ��
	FlipAtlas(atlas_player_left, atlas_player_right);

	atlas_player_fall_idle.LoadFromFile(_T("resources/idle_fall_%d.png"), 5);

	// ����ACƽ̨
	loadimage(&img_AC_platform, _T("resources/AC_platform.png"), PLATFORM_WIDTH, PLATFORM_HEIGHT);
}


void LoadButton()
{
	// ����start�����زĲ��������䷶Χ
	// �趨��Χregion
	region_menu_start.left = 300;
	region_menu_start.right = region_menu_start.left + BUTTON_WIDTH;
	region_menu_start.top = 235;
	region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

	// �����ز�
	btn_menu_start = new MenuStartButton(region_menu_start,
		_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

	// ����find�����زĲ��������䷶Χ
	region_menu_find.left = 300;
	region_menu_find.right = region_menu_find.left + BUTTON_WIDTH;
	region_menu_find.top = 365;
	region_menu_find.bottom = region_menu_find.top + BUTTON_HEIGHT;

	btn_menu_find = new FindButton(region_menu_find,
		_T("resources/menu_find_idle.png"), _T("resources/menu_find_hovered.png"), _T("resources/menu_find_pushed.png"));

	// ����setup�����زĲ������䷶Χ
	region_menu_setup.left = 300;
	region_menu_setup.right = region_menu_setup.left + BUTTON_WIDTH;
	region_menu_setup.top = 495;
	region_menu_setup.bottom = region_menu_setup.top + BUTTON_HEIGHT;

	// �����ز�
	btn_menu_setup = new MenuSetUpButton(region_menu_setup,
		_T("resources/menu_setup_idle.png"), _T("resources/menu_setup_hovered.png"), _T("resources/menu_setup_pushed.png"));
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



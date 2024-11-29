/*
	������:ja1u0va
	����:
		1.����ȫ�ֱ���

*/

#include <vector>

// �������ͷ�ļ�
#include "scene/game_scene/game_scene.h"					// ��Ϸ����
#include "scene/menu_scene/menu_scene.h"					// �˵�����
//#include "scene/achievement_scene/achievement_scene.h"		// �ɾͽ���
#include "scene/death_scene/death_scene.h"					// ��������
#include "scene/select_mode_scene/select_mode_scene.h"		// ѡ��ģʽ����
#include "scene/pause_scene/pause_scene.h"					// ��ͣ����
#include "scene/scene/scene.h"								// ��������
#include "scene/scene_manager/scene_manager.h"				// ����������
#include "scene/select_level_scene/select_level_scene.h"	// ѡ��ؿ�����
#include "scene/set_up_scene/set_up_scene.h"				// ���ý���

// ������ͷ�ļ�
#include "player/player.h"

// ƽ̨���ͷ�ļ�
#include "platform/platform/platform.h"

// ��ť���ͷ�ļ�
#include "button/button/button.h"

// �˵���ť
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


// ����bool����
bool running = true;
bool is_debug = false;

int level = 0;

// ����ͼƬ����
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


// ����ͼ������
Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_player_fall_idle;

// ���尴ť����
MenuStartButton* btn_menu_start = nullptr;// btn button


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

// �ɾ�
//std::vector<Achievement*> achievement_list;

void LoadImageAndAtlas()
{
	// ����˵�����
	loadimage(&img_menu_background, _T("resources/menu_background.png"));
	// ����˵�����
	loadimage(&img_game_background_1, _T("resources/game_background_1.png"));

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



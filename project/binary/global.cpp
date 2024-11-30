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

// �ؿ����ͷ�ļ�
#include "map/map.h"

// ������ͷ�ļ�
#include "player/player.h"

// ƽ̨���ͷ�ļ�
#include "platform/platform/platform.h"

// ��ť���ͷ�ļ�
#include "button/button/button.h"
#include "button/menu_button/menu_button.h"
#include "button/select_mode_button/select_mode_button.h"


extern void FlipAtlas(Atlas& src, Atlas& dst);


extern const int PLAYER_WIDTH = 70;		  // ��ҿ��
extern const int PLAYER_HEIGHT = 70;	  // ��Ҹ߶�

extern const int PLATFORM_WIDTH = 100;	  // ƽ̨���
extern const int PLATFORM_HEIGHT = 30;	  // ƽ̨�߶�


extern const int WINDOW_WIDTH = 700;	  // ���ڿ��
extern const int WINDOW_HEIGHT = 700;	  // ���ڸ߶�

extern const int LEVEL_NUM = 10;

// ����bool����
bool running = true;	// ��Ϸ����
bool is_debug = false;  // ����ģʽ


// ������Ϸȫ�ֲ���
int level = 0;          //�ؿ���


// ����ͼƬ����
// ����ͼ
// �˵�
IMAGE img_menu_background;
// ѡ��ģʽ
IMAGE img_select_mode_background;
// ѡ��ؿ�
IMAGE img_select_level_background;
// ��ͨģʽ
IMAGE img_game_background_1;
// ����
IMAGE img_death_background;

// ���Ĭ��ͼƬ
IMAGE img_player_idle;

// ƽ̨
IMAGE img_NULL_platform;
IMAGE img_AC_platform;
IMAGE img_WA_platform;
IMAGE img_CE_platform;
IMAGE img_SPEED_RIGHT_platform;
IMAGE img_SPEED_LEFT_platform;
IMAGE img_TLE_platform;
IMAGE img_MLE_platform;

// ����ͼ������
Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_player_fall_idle;

// ���尴ť����
// �˵�
MenuStartButton* btn_menu_start = nullptr;// btn button
MenuSetUpButton* btn_menu_setup = nullptr;
MenuShowDetailButton* btn_menu_show_detail = nullptr;
MenuRankButton* btn_menu_rank = nullptr;
MenuAchievementButton* btn_menu_achievement = nullptr;
MenuExitButton* btn_menu_exit = nullptr;
// ѡ��ģʽ
SelectModeNormalButton* btn_select_mode_normal = nullptr;// btn button
SelectModeChallengeButton* btn_select_mode_challenge = nullptr;
SelectModeReturnButton* btn_select_mode_return = nullptr;


// ���尴ť������
// �˵�
RECT region_menu_start;
RECT region_menu_show_detail;
RECT region_menu_setup;
RECT region_menu_rank;
RECT region_menu_achievement;
RECT region_menu_exit;
// ѡ��ģʽ
RECT region_select_mode_normal;
RECT region_select_mode_challenge;
RECT region_select_mode_return;

// ���峡������
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

// ������Ҷ���
Player* player = nullptr;

// ����ƽ̨����
// Platform 

std::vector<Platform*> platform_list;

// �ɾ�
//std::vector<Achievement*> achievement_list;
struct Map_massage map_massage[11] =
{
	//�ٶȡ�ͨ�ط�����{AC, WA, NULL, speed, bounce, MLE, TLE, CE}��
	//{��ϸ�տ������ݡ���ΰ���ҡ�����������һ�Ρ����磡��ʱͣ��}
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
	// ����˵�����
	loadimage(&img_menu_background, _T("resources/menu_background.png"));

	// ����ѡ��ģʽ����
	loadimage(&img_select_mode_background, _T("resources/select_mode_background.png"));

	// ����ѡ��ؿ�����
	loadimage(&img_select_level_background, _T("resources/select_level_background.png"));

	// ������ͨ��Ϸ����
	loadimage(&img_game_background_1, _T("resources/game_background_1.png"));

	// ������������
	loadimage(&img_death_background, _T("resources/game_over.png"));

	// ���Ĭ��ͼƬ
	loadimage(&img_player_idle, _T("resources/player_idle_1.png"), PLAYER_WIDTH, PLAYER_HEIGHT);

	// �������ͼ��
	atlas_player_left.LoadFromFile(_T("resources/left_walk_%d.png"), 6);
	// �������ͼ��
	FlipAtlas(atlas_player_left, atlas_player_right);
	// �����׹ͼ��
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
	// �˵���ť
	const int MENU_BUTTON_WIDTH = 115;
	const int MENU_BUTTON_HEIGHT = 45;

	// ����start_game(��ʼ��Ϸ)�����زĲ��������䷶Χ
	region_menu_start.left = 200;
	region_menu_start.right = region_menu_start.left + MENU_BUTTON_WIDTH;
	region_menu_start.top = 210;
	region_menu_start.bottom = region_menu_start.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_start = new MenuStartButton(region_menu_start,
		_T("resources/menu_start_game_idle.png"), _T("resources/menu_start_game_hovered.png"), _T("resources/menu_start_game_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// ����show_detail(��Ϸ˵��)�����زĲ��������䷶Χ
	region_menu_show_detail.left = 200;
	region_menu_show_detail.right = region_menu_show_detail.left + MENU_BUTTON_WIDTH;
	region_menu_show_detail.top = 280;
	region_menu_show_detail.bottom = region_menu_show_detail.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_show_detail = new MenuShowDetailButton(region_menu_show_detail,
		_T("resources/menu_show_detail_idle.png"), _T("resources/menu_show_detail_hovered.png"), _T("resources/menu_show_detail_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// ����setup(��Ϸ����)�����زĲ��������䷶Χ
	region_menu_setup.left = 200;
	region_menu_setup.right = region_menu_setup.left + MENU_BUTTON_WIDTH;
	region_menu_setup.top = 350;
	region_menu_setup.bottom = region_menu_setup.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_setup = new MenuSetUpButton(region_menu_setup,
		_T("resources/menu_setup_idle.png"), _T("resources/menu_setup_hovered.png"), _T("resources/menu_setup_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// ����rank(���а�)�����زĲ��������䷶Χ
	region_menu_rank.left = 370;
	region_menu_rank.right = region_menu_rank.left + MENU_BUTTON_WIDTH;
	region_menu_rank.top = 210;
	region_menu_rank.bottom = region_menu_rank.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_rank = new MenuRankButton(region_menu_rank,
		_T("resources/menu_rank_idle.png"), _T("resources/menu_rank_hovered.png"), _T("menu_rank_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// ����achievement(�ɾ�)�����زĲ��������䷶Χ
	region_menu_achievement.left = 370;
	region_menu_achievement.right = region_menu_achievement.left + MENU_BUTTON_WIDTH;
	region_menu_achievement.top = 280;
	region_menu_achievement.bottom = region_menu_achievement.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_achievement = new MenuAchievementButton(region_menu_achievement,
		_T("resources/menu_achievement_idle.png"), _T("resources/menu_achievement_hovered.png"), _T("resources/menu_achievement_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);


	// ����exit(�˳���Ϸ)�����زĲ��������䷶Χ
	region_menu_exit.left = 370;
	region_menu_exit.right = region_menu_exit.left + MENU_BUTTON_WIDTH;
	region_menu_exit.top = 350;
	region_menu_exit.bottom = region_menu_exit.top + MENU_BUTTON_HEIGHT;

	// �����ز�
	btn_menu_exit = new MenuExitButton(region_menu_exit,
		_T("resources/menu_exit_idle.png"), _T("resources/menu_exit_hovered.png"), _T("resources/menu_exit_hovered.png"), MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);

	//--------------------------------------------------------------------------------------------------------------------------

	// ѡ��ģʽ��ť
	const int SELECT_MODE_BUTTON_WIDTH = 155;
	const int SELECT_MODE_BUTTON_HEIGHT = 60;

	// ����normal(��ͨģʽ)�����زĲ��������䷶Χ
	region_select_mode_normal.left = 260;
	region_select_mode_normal.right = region_select_mode_normal.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_normal.top = 190;
	region_select_mode_normal.bottom = region_select_mode_normal.top + SELECT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_select_mode_normal = new SelectModeNormalButton(region_select_mode_normal,
		_T("resources/select_mode_normal_idle.png"), _T("resources/select_mode_normal_hovered.png"), _T("resources/select_mode_normal_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);

	// ����challenge(��սģʽ)�����زĲ��������䷶Χ
	region_select_mode_challenge.left = 260;
	region_select_mode_challenge.right = region_select_mode_challenge.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_challenge.top = 280;
	region_select_mode_challenge.bottom = region_select_mode_challenge.top + SELECT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_select_mode_challenge = new SelectModeChallengeButton(region_select_mode_challenge,
		_T("resources/select_mode_challenge_idle.png"), _T("resources/select_mode_challenge_hovered.png"), _T("resources/select_mode_challenge_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);


	// ����return(���ز˵�)�����زĲ��������䷶Χ
	region_select_mode_return.left = 260;
	region_select_mode_return.right = region_select_mode_return.left + SELECT_MODE_BUTTON_WIDTH;
	region_select_mode_return.top = 370;
	region_select_mode_return.bottom = region_select_mode_return.top + SELECT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_select_mode_return = new SelectModeReturnButton(region_select_mode_return,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);

}

void LoadGameResources()
{
	// ����������Դ
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
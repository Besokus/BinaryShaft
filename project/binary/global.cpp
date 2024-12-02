/*
	������:ja1u0va
	����:
		1.����ȫ�ֱ���

*/

#include <vector>

// �������ͷ�ļ�
#include "scene/game_scene/game_scene.h"					// ��Ϸ����
#include "scene/menu_scene/menu_scene.h"					// �˵�����
#include "scene/achievement_scene/achievement_scene.h"		// �ɾͽ���
#include "scene/death_scene/death_scene.h"					// ��������
#include "scene/select_mode_scene/select_mode_scene.h"		// ѡ��ģʽ����
#include "scene/pause_scene/pause_scene.h"					// ��ͣ����
#include "scene/scene/scene.h"								// ��������
#include "scene/scene_manager/scene_manager.h"				// ����������
#include "scene/select_level_scene/select_level_scene.h"	// ѡ��ؿ�����
#include "scene/set_up_scene/set_up_scene.h"				// ���ý���
#include "scene/CG_scene/CG_scene.h"				        // CG����
#include "scene/win_scene/win_scene.h"				        // ʤ������
#include "scene/show_detail_scene/show_detail_scene.h"		// �������ǽ���
#include "scene/login_scene/login_scene.h"					// ע��,�������

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
#include"button/pause_button/pause_button.h"
#include"button/achievement_button/achievement_button.h"
#include"button/music_control_button/music_control_button.h"
#include "button/showus_button/showus_button.h"
#include "button/win_butoon/win_button.h"
#include "button/login_button/login_button.h"


extern void FlipAtlas(Atlas& src, Atlas& dst);


extern const int PLAYER_WIDTH = 70;		  // ��ҿ��
extern const int PLAYER_HEIGHT = 70;	  // ��Ҹ߶�

extern const int PLATFORM_WIDTH = 100;	  // ƽ̨���
extern const int PLATFORM_HEIGHT = 30;	  // ƽ̨�߶�


extern const int WINDOW_WIDTH = 700;	  // ���ڿ��
extern const int WINDOW_HEIGHT = 700;	  // ���ڸ߶�

extern const int LEVEL_NUM = 10;
extern const int PAGE_NUM = 10;

// ����bool����
bool running = true;	// ��Ϸ����
bool is_debug = false;  // ����ģʽ


// ������Ϸȫ�ֲ���
int level = 0;          //�ؿ���
int page = 0;           //��Ϸ˵��ҳ��


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
// �ɾ�
IMAGE img_achievement_background;
// ��ͣ
IMAGE img_pause_background;
// ͨ��
IMAGE img_ending_background;
// ��Ϸ˵��
IMAGE img_detail_background;
IMAGE img_ending_detail;
IMAGE img_death_detail;
// ���а����
IMAGE img_rank_background;
// ʤ��
IMAGE img_win_background;
// ��������
IMAGE img_showdetail_background;
// ��¼
IMAGE img_login_background;

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
Atlas atlas_CG;

// ���尴ť����
// �˵�
MenuStartButton* btn_menu_start = nullptr;// btn button
MenuSetUpButton* btn_menu_setup = nullptr;
MenuShowDetailButton* btn_menu_show_detail = nullptr;
MenuRankButton* btn_menu_rank = nullptr;
MenuAchievementButton* btn_menu_achievement = nullptr;
MenuExitButton* btn_menu_exit = nullptr;
//������ť
MusicBKUP* btn_musicbkup = nullptr;
MusicBKDown* btn_musicbkdown = nullptr;
MusicEFUP* btn_musiceffup = nullptr;
MusicEFDown* btn_musiceffdown = nullptr;
// ѡ��ģʽ
SelectModeNormalButton* btn_select_mode_normal = nullptr;// btn button
SelectModeChallengeButton* btn_select_mode_challenge = nullptr;
SelectModeReturnButton* btn_select_mode_return = nullptr;
// ��ͣ���水ť
PauseBackGameButton* btn_pause_backgame = nullptr;
PauseBackMenuButton* btn_pause_backmenu = nullptr;
PauseSetUpButton* btn_pause_setup = nullptr;
// �ɾ�
AchievementReturnMenuButton* btn_achievement_rtmenu = nullptr;
AchievementDetailButton* btn_achievement_detail = nullptr;
// ��������
ShowUsButton* btn_showus_return = nullptr;
// ʤ��
WinNextButton* btn_win_next = nullptr;
WinReturnButton* btn_win_return = nullptr;
// ��¼����login
LoginNewButton* btn_login_new = nullptr;
LoginDeleteButton* btn_login_delete = nullptr;
LoginReturnButton* btn_login_return = nullptr;


// ���尴ť������
// �˵�
RECT region_menu_start;
RECT region_menu_show_detail;
RECT region_menu_setup;
RECT region_menu_rank;
RECT region_menu_achievement;
RECT region_menu_exit;
//��ͣ����
RECT region_pause_backgame;
RECT region_pause_backmenu;
RECT region_pause_setup;
// ѡ��ģʽ
RECT region_select_mode_normal;
RECT region_select_mode_challenge;
RECT region_select_mode_return;
// �ɾ�
RECT region_achievement_rtmenu;
RECT region_achievement_detail;
// �����Ӽ���ť����
RECT region_setting_musicbkup;
RECT region_setting_musicbkdown;
RECT region_setting_musiceffup;
RECT region_setting_musiceffdown;
// ��������
RECT region_showus_return;
// ʤ��
RECT region_win_next;
RECT region_win_return;
// ��¼����login
RECT region_login_new;
RECT region_login_delete;
RECT region_login_return;


// ���峡������
Scene* game_scene = nullptr;
Scene* menu_scene = nullptr;
Scene* achievement_scene = nullptr;
Scene* death_scene = nullptr;
Scene* select_mode_scene = nullptr;
Scene* pause_scene = nullptr;
Scene* select_level_scene = nullptr;
SetUpScene* setup_scene = nullptr;
Scene* detail_scene = nullptr;
Scene* rank_scene = nullptr;
Scene* win_scene = nullptr;
Scene* CG_scene = nullptr;
Scene* showdetail_scene = nullptr;
Scene* login_scene = nullptr;

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

//�ؿ�����
struct Map_massage map_massage[11] =
{
	//�ٶȡ�ͨ�ط�����{AC, WA, NULL, speed, bounce, MLE, TLE, CE}��
	//{��ϸ�տ������ݡ���ΰ���ҡ�����������һ�Ρ����磡��ʱͣ��}
	{1.0f, 100, {40,20,20,10,10,0,0,0}, {0,0,0,0,0,0} },
	{1.0f, 120, {40,20,20,10,10,0,0,0}, {0,0,1,0,0,0} },
	{1.0f, 130, {40,20,10,10,10,10,0,0}, {0,0,1,0,0,0} },
	{1.3f, 150, {40,20,10,10,5,5,0,0}, {0,0,1,0,0,1} },
	{1.3f, 200, {40,20,10,5,5,5,5,10}, {0,0,1,0,1,1} },
	{1.3f, 200, {40,20,5,5,5,0,24,1}, {0,1,0,0,1,1} },
	{1.5f, 250, {40,20,5,5,5,24,0,1}, {1,0,0,0,1,1} },
	{1.5f, 250, {30,20,10,10,10,10,10,0}, {0,1,1,1,0,0} },
	{1.5f, 300, {30,20,10,10,10,0,0,20}, {0,0,1,1,0,1} },
	{1.8f, 320, {25,25,5,5,5,15,15,5}, {1,1,0,0,0,1} },
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

	// ����ɾͱ���
	loadimage(&img_achievement_background, _T("resources/show_detail_background.png"));//achievement_background

	//����ͨ�ر���
	loadimage(&img_ending_background, _T("resources/ending_1.png"));

	// ����ʤ������
	loadimage(&img_win_background, _T("resources/TEMP_win_background.png"));

	// ����������Ǳ���
	loadimage(&img_showdetail_background, _T("resources/TEMP_showus_background.png"));

	// ������Ϸ˵������ͼ
	loadimage(&img_detail_background, _T("resources/detail_scene_background.jpg"));
	loadimage(&img_ending_detail, _T("resources/ending_1.png"), 190, 190, false);
	loadimage(&img_death_detail, _T("resources/game_over.png"), 190, 190, false);

	// �������а񱳾�
	loadimage(&img_rank_background, _T("resources/rank_scene_background.png"));

	// ������ͣ���汳��
	loadimage(&img_pause_background, _T("resources/pause_background.png"), 700, 700);

	// �����¼login���汳��
	loadimage(&img_login_background, _T("resources/login_background.png"), 700, 700);

	// ���Ĭ��ͼƬ
	loadimage(&img_player_idle, _T("resources/player_idle_1.png"), PLAYER_WIDTH, PLAYER_HEIGHT);

	// �������ͼ��
	atlas_player_left.LoadFromFile(_T("resources/left_walk_%d.png"), 6);
	// �������ͼ��
	FlipAtlas(atlas_player_left, atlas_player_right);
	// �����׹ͼ��
	atlas_player_fall_idle.LoadFromFile(_T("resources/idle_fall_%d.png"), 5);

	// CGͼ��
	atlas_CG.LoadFromFile(_T("resources/idle_fall_%d.png"), 5);


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

	//--------------------------------------------------------------------------------------------------------------------------

	// �������ǰ�ť
	const int SHOWUS_BUTTON_WIDTH = 155;
	const int SHOWUS_BUTTON_HEIGHT = 60;

	// ����showus_return�����زĲ��������䷶Χ
	region_showus_return.left = 520;
	region_showus_return.right = region_showus_return.left + SHOWUS_BUTTON_WIDTH;
	region_showus_return.top = 600;
	region_showus_return.bottom = region_showus_return.top + SHOWUS_BUTTON_HEIGHT;

	// �����ز�
	btn_showus_return = new ShowUsButton(region_showus_return,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), SHOWUS_BUTTON_WIDTH, SHOWUS_BUTTON_HEIGHT);

	//--------------------------------------------------------------------------------------------------------------------------

	//ʤ����ť
	const int WIN_BUTTON_WIDTH = 155;
	const int WIN_BUTTON_HEIGHT = 60;

	// ����win_return�����زĲ��������䷶Χ
	region_win_return.left = 155;
	region_win_return.right = region_win_return.left + WIN_BUTTON_WIDTH;
	region_win_return.top = 450;
	region_win_return.bottom = region_win_return.top + WIN_BUTTON_HEIGHT;

	// �����ز�
	btn_win_return = new WinReturnButton(region_win_return,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), WIN_BUTTON_WIDTH, WIN_BUTTON_HEIGHT);

	// ����win_next�����زĲ��������䷶Χ
	region_win_next.left = 390;
	region_win_next.right = region_win_next.left + WIN_BUTTON_WIDTH;
	region_win_next.top = 450;
	region_win_next.bottom = region_win_next.top + WIN_BUTTON_HEIGHT;

	// �����ز�
	btn_win_next = new WinNextButton(region_win_next,
		_T("resources/select_mode_normal_idle.png"), _T("resources/select_mode_normal_hovered.png"), _T("resources/select_mode_normal_hovered.png"), WIN_BUTTON_WIDTH, WIN_BUTTON_HEIGHT);


	//---------------------------------------------------------------------------------------------
	//���������Ӽ���ť�ز�

	//������ť��С����
	const int MUSIC_SET_BUTTON_WIDTH = 55;
	const int MUSIC_SET_BUTTON_HEIGHT = 45;
	region_setting_musicbkup.left = 540;
	region_setting_musicbkup.right = region_setting_musicbkup.left + MUSIC_SET_BUTTON_WIDTH;
	region_setting_musicbkup.top = 330;
	region_setting_musicbkup.bottom = region_setting_musicbkup.top + MUSIC_SET_BUTTON_HEIGHT;

	btn_musicbkup = new MusicBKUP(region_setting_musicbkup,
		_T("resources/musicup_idle.png"), _T("resources/musicup_hovered.png"), _T("resources/musicup_hovered.png"), MUSIC_SET_BUTTON_WIDTH, MUSIC_SET_BUTTON_HEIGHT);

	region_setting_musicbkdown.left = 600;
	region_setting_musicbkdown.right = region_setting_musicbkdown.left + MUSIC_SET_BUTTON_WIDTH;
	region_setting_musicbkdown.top = 330;
	region_setting_musicbkdown.bottom = region_setting_musicbkdown.top + MUSIC_SET_BUTTON_HEIGHT;

	btn_musicbkdown = new MusicBKDown(region_setting_musicbkdown,
		_T("resources/musicdown_idle.png"), _T("resources/musicdown_hovered.png"), _T("resources/musicdown_hovered.png"), MUSIC_SET_BUTTON_WIDTH, MUSIC_SET_BUTTON_HEIGHT);

	//��Ч�Ӽ�
	region_setting_musiceffup.left = 540;
	region_setting_musiceffup.right = region_setting_musiceffup.left + MUSIC_SET_BUTTON_WIDTH;
	region_setting_musiceffup.top = 390;
	region_setting_musiceffup.bottom = region_setting_musiceffup.top + MUSIC_SET_BUTTON_HEIGHT;

	btn_musiceffup = new MusicEFUP(region_setting_musiceffup,
		_T("resources/musicup_idle.png"), _T("resources/musicup_hovered.png"), _T("resources/musicup_hovereded.png"), MUSIC_SET_BUTTON_WIDTH, MUSIC_SET_BUTTON_HEIGHT);

	region_setting_musiceffdown.left = 600;
	region_setting_musiceffdown.right = region_setting_musiceffdown.left + MUSIC_SET_BUTTON_WIDTH;
	region_setting_musiceffdown.top = 390;
	region_setting_musiceffdown.bottom = region_setting_musiceffdown.top + MUSIC_SET_BUTTON_HEIGHT;

	btn_musiceffdown = new MusicEFDown(region_setting_musiceffdown,
		_T("resources/musicdown_idle.png"), _T("resources/musicdown_hovered.png"), _T("resources/musicdown_hovered.png"), MUSIC_SET_BUTTON_WIDTH, MUSIC_SET_BUTTON_HEIGHT);

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // ��ͣ���水ť
	const int PAUSE_MODE_BUTTON_WIDTH = 155;
	const int PAUSE_MODE_BUTTON_HEIGHT = 60;

	// ���÷�����Ϸ��ť��Χ
	region_pause_backgame.left = 260;
	region_pause_backgame.right = region_pause_backgame.left + PAUSE_MODE_BUTTON_WIDTH;
	region_pause_backgame.top = 190;
	region_pause_backgame.bottom = region_pause_backgame.top + PAUSE_MODE_BUTTON_HEIGHT;

	//�����ز�
	btn_pause_backgame = new PauseBackGameButton(region_pause_backgame,
		_T("resources/pause_backgame_idle.png"), _T("resources/pause_backgame_hovered.png"), _T("resources/pause_backgame_hovered.png"), PAUSE_MODE_BUTTON_WIDTH, PAUSE_MODE_BUTTON_HEIGHT);

	//���÷��ز˵�����
	region_pause_backmenu.left = 260;
	region_pause_backmenu.right = region_pause_backmenu.left + PAUSE_MODE_BUTTON_WIDTH;
	region_pause_backmenu.top = 280;
	region_pause_backmenu.bottom = region_pause_backmenu.top + PAUSE_MODE_BUTTON_HEIGHT;

	//�����ز�
	btn_pause_backmenu = new PauseBackMenuButton(region_pause_backmenu,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), PAUSE_MODE_BUTTON_WIDTH, PAUSE_MODE_BUTTON_HEIGHT);

	//�������ð�ť
	region_pause_setup.left = 260;
	region_pause_setup.right = region_pause_setup.left + PAUSE_MODE_BUTTON_WIDTH;
	region_pause_setup.top = 370;
	region_pause_setup.bottom = region_pause_setup.top + PAUSE_MODE_BUTTON_HEIGHT;

	//�����ز�
	btn_pause_setup = new PauseSetUpButton(region_pause_setup,
		_T("resources/menu_setup_idle.png"), _T("resources/menu_setup_hovered.png"), _T("resources/menu_setup_hovered.png"), PAUSE_MODE_BUTTON_WIDTH, PAUSE_MODE_BUTTON_HEIGHT);

	//--------------------------------------------------------------------------------------------------------------------------

	// �ɾ�ģʽ��ť
	const int ACHIEVEMENT_MODE_BUTTON_WIDTH = 130;
	const int ACHIEVEMENT_MODE_BUTTON_HEIGHT = 60;


	// ����rtmenu(���ز˵�)�����زĲ��������䷶Χ
	region_achievement_rtmenu.left = 250;
	region_achievement_rtmenu.right = region_achievement_rtmenu.left + ACHIEVEMENT_MODE_BUTTON_WIDTH;
	region_achievement_rtmenu.top = 350;
	region_achievement_rtmenu.bottom = region_achievement_rtmenu.top + ACHIEVEMENT_MODE_BUTTON_HEIGHT;

	//�����ز�
	btn_achievement_rtmenu = new AchievementReturnMenuButton(region_menu_achievement,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), SELECT_MODE_BUTTON_WIDTH, SELECT_MODE_BUTTON_HEIGHT);

	//����detail(չʾ��ϸ��Ϣ)

	//--------------------------------------------------------------------------------------------------------------------------

	// ��¼���水ťlogin
	const int LOGIN_BUTTON_WIDTH = 130;
	const int LOGIN_BUTTON_HEIGHT = 50;


	// �����½��浵�����زĲ��������䷶Χ
	region_login_new.left = 85;
	region_login_new.right = region_login_new.left + ACHIEVEMENT_MODE_BUTTON_WIDTH;
	region_login_new.top = 480;
	region_login_new.bottom = region_login_new.top + ACHIEVEMENT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_login_new = new LoginNewButton(region_login_new,
		_T("resources/login_new_archive_idle.png"), _T("resources/login_new_archive_hovered.png"), _T("resources/login_new_archive_hovered.png"), LOGIN_BUTTON_WIDTH, LOGIN_BUTTON_HEIGHT);

	
	// ����ɾ���浵�����زĲ��������䷶Χ
	region_login_delete.left = 290;
	region_login_delete.right = region_login_delete.left + ACHIEVEMENT_MODE_BUTTON_WIDTH;
	region_login_delete.top = 480;
	region_login_delete.bottom = region_login_delete.top + ACHIEVEMENT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_login_delete = new LoginDeleteButton(region_login_delete,
		_T("resources/login_delete_archive_idle.png"), _T("resources/login_delete_archive_hovered.png"), _T("resources/login_delete_archive_hovered.png"), LOGIN_BUTTON_WIDTH, LOGIN_BUTTON_HEIGHT);

	// ���뷵�ز˵������زĲ��������䷶Χ
	region_login_return.left = 505;
	region_login_return.right = region_login_return.left + ACHIEVEMENT_MODE_BUTTON_WIDTH;
	region_login_return.top = 480;
	region_login_return.bottom = region_login_return.top + ACHIEVEMENT_MODE_BUTTON_HEIGHT;

	// �����ز�
	btn_login_return = new LoginReturnButton(region_login_return,
		_T("resources/select_mode_return_idle.png"), _T("resources/select_mode_return_hovered.png"), _T("resources/select_mode_return_hovered.png"), LOGIN_BUTTON_WIDTH, LOGIN_BUTTON_HEIGHT);
}

void LoadGameResources()
{
	// ����������Դ
	AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

	game_scene = new GameScene();
	menu_scene = new MenuScene();
	achievement_scene = new AchievementScene();
	death_scene = new DeathScene();
	showdetail_scene = new ShowDetailScene();
	select_mode_scene = new SelectModeScene();
	pause_scene = new PauseScene();
	select_level_scene = new SelectLevelScene();
	setup_scene = new SetUpScene();
	// rank_scene = new RankScene();
	login_scene = new LoginScene();

	animation_player_left = new Animation();
	animation_player_right = new Animation();
	animation_player_fall_idle = new Animation();

	LoadButton();

	LoadImageAndAtlas();

	animation_player_left->SetAtlas(&atlas_player_left);
	animation_player_right->SetAtlas(&atlas_player_right);
	animation_player_fall_idle->SetAtlas(&atlas_player_fall_idle);

}
#include "menu_scene.h"
#include "../../button/button/button.h"
#include "../../button/menu_button/menu_button.h"

extern bool running;
extern SceneManager scene_manager;

extern MenuStartButton* btn_menu_start;// btn button
extern MenuSetUpButton* btn_menu_setup;
extern MenuShowDetailButton* btn_menu_show_detail;
extern MenuRankButton* btn_menu_rank;
extern MenuAchievementButton* btn_menu_achievement;
extern MenuExitButton* btn_menu_exit;

extern IMAGE img_menu_background;

void MenuScene::OnEnter()
{
	btn_menu_start->OnEnter();
	btn_menu_show_detail->OnEnter();
	btn_menu_setup->OnEnter();
	btn_menu_rank->OnEnter();
	btn_menu_achievement->OnEnter();
	btn_menu_exit->OnEnter();

	mciSendString(_T("play bgm_menu_1 repeat from 0"), NULL, 0, NULL);
}

void MenuScene::OnUpdate()
{
}

void MenuScene::OnDraw()
{
	putimage(0, 0, &img_menu_background);

	btn_menu_start->OnDraw();
	btn_menu_show_detail->OnDraw();
	btn_menu_setup->OnDraw();
	btn_menu_rank->OnDraw();
	btn_menu_achievement->OnDraw();
	btn_menu_exit->OnDraw();

}

void MenuScene::OnInput(const ExMessage& msg)
{
	btn_menu_start->OnInput(msg);
	btn_menu_show_detail->OnInput(msg);
	btn_menu_setup->OnInput(msg);
	btn_menu_rank->OnInput(msg);
	btn_menu_achievement->OnInput(msg);
	btn_menu_exit->OnInput(msg);

	if (msg.message == WM_KEYDOWN)
	{

	}
}

void MenuScene::OnExit()
{

}

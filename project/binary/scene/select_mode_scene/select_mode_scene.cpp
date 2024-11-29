#include "select_mode_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/select_mode_button/select_mode_button.h"

extern SceneManager scene_manager;

extern SelectModeNormalButton* btn_select_mode_normal;// btn button
extern SelectModeChallengeButton* btn_select_mode_challenge;
extern SelectModeReturnButton* btn_select_mode_return;

extern IMAGE img_select_mode_background;

void SelectModeScene::OnEnter() 
{
	btn_select_mode_normal->OnEnter();
	btn_select_mode_challenge->OnEnter();
	btn_select_mode_return->OnEnter();
}

// 绘制模式选择界面
void SelectModeScene::OnDraw() 
{
	putimage(0, 0, &img_select_mode_background);
	
	btn_select_mode_normal->OnDraw();
	btn_select_mode_challenge->OnDraw();
	btn_select_mode_return->OnDraw();

}

void SelectModeScene::OnInput(const ExMessage& msg) 
{
	btn_select_mode_normal->OnInput(msg);
	btn_select_mode_challenge->OnInput(msg);
	btn_select_mode_return->OnInput(msg);
}

void SelectModeScene::OnUpdate() 
{

}

void SelectModeScene::OnExit()
{

}
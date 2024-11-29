#include "select_mode_scene.h"
#include "../scene_manager/scene_manager.h"


extern SceneManager scene_manager;
extern int Mode_;


// extern SelectModeButton* btn_select_mode;


void SelectModeScene::OnEnter() {
//	btn_select_mode->OnEnter();

	std::cout << "进入模式选择界面" << std::endl;
}

void SelectModeScene::OnExit() {
	std::cout << "退出模式选择界面" << std::endl;

}

//绘制模式选择界面
void SelectModeScene::OnDraw() {
	//putimage(275, 0, &img_select_mode_background);
	//putimage(380, 180, &img_normal_mode_idle);
	//putimage(650, 180, &img_challenge_mode_idle);
	//阴影效果
	settextcolor(RGB(156, 156, 156));
	settextstyle(25, 0, L"微软雅黑");
	//string Mode[MODENUM]{};//两个模式
	//_sprintf_s(Mode, _T("当前模式:%s"), *Mode);
	//outtextxy(10, 50, Mode[Mode_]);
	outtextxy(20, 20, _T("按ESC返回上一页"));

	settextcolor(RGB(255, 255, 255));
	settextstyle(25, 0, L"微软雅黑");
	outtextxy(23, 23, _T("按ESC返回上一页"));

	//btn_select_mode->OnDraw();

}

void SelectModeScene::OnInput(const ExMessage& msg) 
{
//	btn_select_mode->OnInput(msg);
	switch (msg.vkcode)
	{
		/*case 'A':
			Mode_ = (Mode_  + MODENUM) % MODENUM;
			break;
		case 'D':
			Mode_ = (Mode_ ) % MODENUM;
			break;*/
	case VK_ESCAPE:
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		break;
	}

}

void SelectModeScene::OnUpdate() 
{

	std::cout << "正在选模式" << std::endl;
}
#include "select_mode_scene.h"
#include "../scene_manager/scene_manager.h"


extern SceneManager scene_manager;
extern int Mode_;


// extern SelectModeButton* btn_select_mode;


void SelectModeScene::OnEnter() {
//	btn_select_mode->OnEnter();

	std::cout << "����ģʽѡ�����" << std::endl;
}

void SelectModeScene::OnExit() {
	std::cout << "�˳�ģʽѡ�����" << std::endl;

}

//����ģʽѡ�����
void SelectModeScene::OnDraw() {
	//putimage(275, 0, &img_select_mode_background);
	//putimage(380, 180, &img_normal_mode_idle);
	//putimage(650, 180, &img_challenge_mode_idle);
	//��ӰЧ��
	settextcolor(RGB(156, 156, 156));
	settextstyle(25, 0, L"΢���ź�");
	//string Mode[MODENUM]{};//����ģʽ
	//_sprintf_s(Mode, _T("��ǰģʽ:%s"), *Mode);
	//outtextxy(10, 50, Mode[Mode_]);
	outtextxy(20, 20, _T("��ESC������һҳ"));

	settextcolor(RGB(255, 255, 255));
	settextstyle(25, 0, L"΢���ź�");
	outtextxy(23, 23, _T("��ESC������һҳ"));

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

	std::cout << "����ѡģʽ" << std::endl;
}
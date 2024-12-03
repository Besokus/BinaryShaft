#include "set_up_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/music_control_button/music_control_button.h"
#include "../menu_scene/menu_scene.h"
#include<conio.h>
#include<algorithm>
using namespace std;
extern SceneManager scene_manager;
//extern MenuScene* menu_scene;
//ȫ�ֻ�������Ч��ť����
extern MusicBKUP* btn_musicbkup;
extern MusicBKDown* btn_musicbkdown;
extern MusicEFUP* btn_musiceffup;
extern MusicEFDown* btn_musiceffdown;

extern bool pause_back;

//��Ҫ�ĵ���ͼƬ
//IMAGE img_set;
IMAGE img_setting_bk;
void SetUpScene::OnEnter()
{	//��ʼ��������Ϣ
	//setbkcolor(BLACK);
	//�������ִ�С�ͷ��
	settextstyle(50, 0, _T("΢���ź�"));
	setbkmode(TRANSPARENT);

	//���ذ�ť����������ͼƬ...
	loadimage(&img_setting_bk, _T("resources/setup/setup_background.png"), 700, 700);
	//loadimage(&img_set, "path");
	btn_musicbkup->OnEnter();
	btn_musicbkdown->OnEnter();
	btn_musiceffup->OnEnter();
	btn_musiceffdown->OnEnter();

	//������������
	ifstream ifs1("resources/Music_Data/Music_Bk.txt");
	ifstream ifs2("resources/Music_Data/Music_Eff.txt");
	if (ifs1.is_open())
	{
		getline(ifs1, this->m_bk);
		cout << "�������سɹ�" << endl;
	}
	else
		this->m_bk = "???";
	if (ifs2.is_open())
	{
		getline(ifs2, this->m_eff);
		cout << "��Ч���سɹ�" << endl;
	}
	else
		this->m_eff = "???";
	ifs1.close();
	ifs2.close();
	std::cout << "�������ý���" << std::endl;
}

void SetUpScene::OnUpdate()
{
	cout << "���ý�����������" << endl;

}

void SetUpScene::OnDraw()
{
	//�������ñ���ͼƬ...
	putimage(0, 0, &img_setting_bk);


	outtextxy(100, 320, _T("�������ִ�С:"));
	outtextxy(100, 380, _T("��Ϸ��Ч��С:"));
	//���ư�ťͼƬ...
	btn_musicbkup->OnDraw();
	btn_musicbkdown->OnDraw();
	btn_musiceffup->OnDraw();
	btn_musiceffdown->OnDraw();


	//outtextxy(400, 320, _T(this->m_bk.c_str()));
	//outtextxy(400, 380, _T(this->m_eff.c_str()));

	//���Ʒ�����ʾ�ı�
	outtextxy(200, 600, _T("��Esc�������˵�"));

}

void SetUpScene::OnInput(const ExMessage& msg)
{
	//��ť���¼�����
	btn_musicbkup->OnInput(msg);
	btn_musicbkdown->OnInput(msg);
	btn_musiceffup->OnInput(msg);
	btn_musiceffdown->OnInput(msg);

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		printf("EXIT\n");
		if (pause_back)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::Pause);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		}
	}
}

void SetUpScene::OnExit()
{
	cout << "���ý����˳�" << endl;

}

string SetUpScene::GetElement(string x)
{
	if (x == "music_BK")
		return this->m_bk;
	else if (x == "music_EFF")
		return this->m_eff;
	else
		return NULL;
}

void SetUpScene::SetElement(string choose, string x)
{
	if (choose == "music_BK")
		this->m_bk = x;
	else if (choose == "music_EFF")
		this->m_eff = x;
}

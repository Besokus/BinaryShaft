
#include "achievement_scene.h"
#include "../scene_manager/scene_manager.h"
#include"../../button/achievement_button/achievement_button.h"
#include "../../button/button/button.h"
#include "../../data.h"
#include <vector>

extern SceneManager scene_manager;

extern AchievementReturnMenuButton* btn_achievement_rtmenu;
extern IMAGE img_achievement_background;

extern vector<Data> data_list;
extern Data* current_data;

extern IMAGE img_achievement[20];

void AchievementScene::OnEnter()
{
	btn_achievement_rtmenu->OnEnter();

	if (current_data) 
	{
		current_data->UpdateAchievement();
	}
}


void AchievementScene::OnUpdate()
{

}

void AchievementScene::OnDraw() {
	// ����ͼ
	putimage(0, 0, &img_achievement_background);
	// ��ť
	btn_achievement_rtmenu->OnDraw();
	// ͸����ӡ����
	setbkmode(TRANSPARENT);
	// ����
	settextstyle(30, 0, _T("IPix"));

	static TCHAR text[64];
	_stprintf_s(text, _T("��%dҳ"), current_page + 1);
	outtextxy(195, 520, text);

	// ҳ���л�Ч��
	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(100, 520, _T("A"));
		outtextxy(150, 520, _T("<"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(100, 520, _T("A"));
		outtextxy(150, 520, _T("<"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(340, 520, _T("D"));
		outtextxy(290, 520, _T(">"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(340, 520, _T("D"));
		outtextxy(290, 520, _T(">"));
	}

	outtextxy(160, 660, _T("��Z��͵͵�鿴���гɾ�Ŷ"));

	// �����һ�ûѡ��浵,����ʾ���ѡ��浵
	if (current_data == nullptr)
	{
		settextstyle(50, 0, _T("IPix"));
		outtextxy(100, 350, _T("����ѡ��浵!!"));

		return;
	}

	// ������û�������سɾ�,����ʾδ֪״̬
	if (!current_data->unlocked_achievement[current_page] && !is_peek)
	{
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("???"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("?????"));

		return;
	}

	switch (current_page)
	{
	case 0:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("��������"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("�ӵײ���ջ"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("ţ�ٵĹײİ嶯��һ��..."));

		break;

	case 1:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("����˭��������"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("��ջ(����)һ��"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("���Ҹ�������?"));

		outtextxy(50, 440, _T("�⻹�ǹ�����?"));
		break;
	case 2:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("���ǣ���"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����CE"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("�����ڱ��ؼ��һ�����"));

		break;
	case 3:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("made in heaven"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����3��[TLE]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("��˵���һ��,"));

		outtextxy(50, 440, _T("����Ҫ��ʼ������!"));

		break;
	case 4:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("�з�����"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����3��[MLE]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("Ҫѧ����С��һ����ǿ!"));


		break;
	case 5:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("����������"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����3��[opposite]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("����ʱ��Ļ������~"));
		outtextxy(50, 440, _T("�ӷ�����ʼ�ƶ�~"));



		break;
	case 6:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("�ߺ����"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����3��[bounce]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("��,��,��,��"));
		outtextxy(50, 440, _T("������!!!"));

		break;
	case 7:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("������"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����3��[speed]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("��,�ҵĴ���Ҳ"));
		outtextxy(50, 440, _T("�ڷ�����ת"));
		break;

	case 8:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("��ȼ���"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("�ȹ������б���ƽ̨"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("��AC�����гɾ͸�!"));

		break;
	case 9:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("GrandMaster"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("���ȫ���ɾ�"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("������,����ʱ��!"));

		break;
	case 10:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("��ѡ������"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("������20��"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("�����Ɑ������!"));
		outtextxy(50, 440, _T("Ҫ�ǵ�������(�浵)Ŷ~"));


		break;

	case 11:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("������ȷ"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("����20��WA"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T("��ô���������������??"));
		outtextxy(50, 440, _T("�⻹�ܱ���?!"));

		break;
	}

	putimage(470, 290, &img_achievement[current_page]);

}


void AchievementScene::OnInput(const ExMessage& msg) {
	btn_achievement_rtmenu->OnInput(msg);

	//btn_achievement_detail->OnInput(msg);

	// �����û����룬���簴���¼�
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		case 'A':
			current_page = (current_page - 1 + PAGE_NUM) % PAGE_NUM;
			is_A_down = true;
			break;
		case 'D':
			current_page = (current_page + 1) % PAGE_NUM;
			is_D_down = true;
			break;
		case 'Z':
			if (!is_peek)
				is_peek = true;
			else
				is_peek = false;
		}


	}
	if (msg.message == WM_KEYUP)
	{
		switch (msg.vkcode)
		{
		case 'A':
			is_A_down = false;
			break;
		case 'D':
			is_D_down = false;
			break;
		}
	}

}

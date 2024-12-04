#include "rank_scene.h"

extern SceneManager scene_manager;
extern IMAGE img_rank_background;
extern const int RANKPAGE;
extern int rank_page;
//��ֹ����
extern Data* current_rank_data;
//int rank_num;//���а�����
extern vector<Data>rank_list[9];//ʮ����
extern vector<Data> data_list;							// ������������,�����洢���е��������
extern Data* current_data;
int rank_num;
//extern void WriteRankData();
//extern void ReadRankData();

//ÿ���񵥸���ע���û�����Ĳ�ͬ�ؿ��ĵ÷ֽ������������ѡ��浵������Ϸ�󣬵�ǰ��ҵ�ָ���ָ������
//�ڸ���Һ�����Ϸ����ʱ����������Ϸ�÷֣��Ǹ���Ҹùؿ��÷����ֵ���������Ҷ�Ӧ�Ĺؿ������У��ļ�����
// �ɷ�����ҽ���������Ϸ�����д�����ݣ����Ըùؿ������д浵����������sort�����൱��ÿ���ؿ�����һ
// ����Ӧ�����а�
//����ʾ���а��ʱ�򣬸��ݷ�ҳ��rank_page �л�rank_listȻ����ʾ


void RankScene::OnEnter() {
	rank_page = 0;
	rank_num = 0;

}

void RankScene::OnDraw()
{

	putimage(0, 0, &img_rank_background);
	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("IPix"));
	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), rank_page + 1);
	outtextxy(175, 195, text);
	outtextxy(52.5, 195, _T("��ͨģʽ:��    ��"));
	settextstyle(18, 0, _T("IPix"));
	outtextxy(40, 230, _T("����"));
	outtextxy(105, 230, _T("�ǳ�"));
	outtextxy(180, 230, _T("�÷�"));
	outtextxy(535, 665, _T("Esc�˳�"));

	settextstyle(15, 0, _T("IPix"));
	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(40, 665, _T("A <-��һҳ"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(40, 665, _T("A <-��һҳ"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(135, 665, _T("��һҳ-> D"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(135, 665, _T("��һҳ-> D"));
	}
	settextstyle(18, 0, _T("IPix"));
	switch (rank_page)
	{
	case 0:
		//�������ǰʮ
		//�����ɾ��д�������ַ����ĳ���Ȼ�����
		outtextxy(85, 255, _T("Besokus"));
		outtextxy(180, 255, _T("150"));
		break;
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;

	case 8:

		break;

	}

}

void RankScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			rank_page = (rank_page - 1 + RANKPAGE) % RANKPAGE;
			is_A_down = true;
			break;
		case 'D':
			rank_page = (rank_page + 1) % RANKPAGE;
			is_D_down = true;
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
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
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		}
	}

}

void RankScene::OnUpdate()
{

}

void RankScene::OnExit()
{


}
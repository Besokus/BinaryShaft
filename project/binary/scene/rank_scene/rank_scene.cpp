#include "rank_scene.h"
#include <algorithm>
#pragma warning(disable:4996)

extern SceneManager scene_manager;
extern IMAGE img_rank_background;

extern vector<Data> data_list;							// 定义数据链表,用来存储现有的玩家数据
extern Data* current_data;

void RankScene::OnEnter()
{
	page = 0;

	for (int i = 0;i < 11;i++)
	{
		rank[i].clear();
	}

	for (int i = 0;i < data_list.size();i++)
	{
		for (int j = 0;j < 11;j++)
		{
			RankDetail rank_detail;

			strcpy(rank_detail.name, data_list[i].name);

			rank_detail.score = data_list[i].level_score[j][0];
			rank[j].push_back(rank_detail);

			rank_detail.score = data_list[i].level_score[j][1];
			rank[j].push_back(rank_detail);

			rank_detail.score = data_list[i].level_score[j][2];
			rank[j].push_back(rank_detail);
		}
	}

	for (int i = 0;i < 11;i++)
	{
		std::sort(rank[i].begin(), rank[i].end(), [](const RankDetail& a, const RankDetail& b)
			{
				return a.score < b.score;
			});

	}
}

void RankScene::OnDraw()
{
	putimage(0, 0, &img_rank_background);

	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("IPix"));

	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), page + 1);

	outtextxy(175, 195, text);
	outtextxy(52, 195, _T("普通模式:第    关"));

	outtextxy(530, 195, _T("挑战模式"));

	settextstyle(18, 0, _T("IPix"));

	outtextxy(490, 230, _T("排名"));
	outtextxy(555, 230, _T("昵称"));
	outtextxy(630, 230, _T("得分"));


	outtextxy(40, 230, _T("排名"));
	outtextxy(105, 230, _T("昵称"));
	outtextxy(180, 230, _T("得分"));
	outtextxy(535, 665, _T("Esc退出"));

	settextstyle(15, 0, _T("IPix"));
	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(40, 665, _T("A <-上一页"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(40, 665, _T("A <-上一页"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(135, 665, _T("下一页-> D"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(135, 665, _T("下一页-> D"));
	}
	settextstyle(18, 0, _T("IPix"));



	for (int i = rank[page].size() - 1;i >= 0;i--)
	{
		int idx = rank[page].size() - i;

		_stprintf_s(text, _T("%d"), idx);

		outtextxy(55, idx * 20 + 235, text);

		MultiByteToWideChar(CP_ACP, 0, rank[page][i].name, -1, text, 64);
		outtextxy(85, idx * 20 + 235, text);

		_stprintf_s(text, _T("%d"), rank[page][i].score);
		outtextxy(195, idx * 20 + 235, text);
	}

	for (int i = rank[10].size() - 1;i >= 0;i--)
	{
		int idx = rank[10].size() - i;

		_stprintf_s(text, _T("%d"), idx);

		outtextxy(495, idx * 20 + 235, text);

		MultiByteToWideChar(CP_ACP, 0, rank[10][i].name, -1, text, 64);
		outtextxy(525, idx * 20 + 235, text);

		_stprintf_s(text, _T("%d"), rank[10][i].score);
		outtextxy(635, idx * 20 + 235, text);
	}

}

void RankScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			page = (page - 1 + PAGE_SUM) % PAGE_SUM;
			is_A_down = true;
			break;
		case 'D':
			page = (page + 1) % PAGE_SUM;
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
		}
	}

}

void RankScene::OnUpdate()
{

}

void RankScene::OnExit()
{


}
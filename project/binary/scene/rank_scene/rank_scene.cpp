#include "rank_scene.h"

extern SceneManager scene_manager;
extern IMAGE img_rank_background;
extern const int RANKPAGE;
extern int rank_page;
//防止重名
extern Data* current_rank_data;
//int rank_num;//排行榜人数
extern vector<Data>rank_list[9];//十个榜单
extern vector<Data> data_list;							// 定义数据链表,用来存储现有的玩家数据
extern Data* current_data;
int rank_num;
//extern void WriteRankData();
//extern void ReadRankData();

//每个榜单根据注册用户保存的不同关卡的得分进行排序，在玩家选择存档进入游戏后，当前玩家的指针便指向该玩家
//在该玩家后续游戏结束时，将本轮游戏得分（记该玩家该关卡得分最大值）记入该玩家对应的关卡数组中，文件操作
// 可放在玩家结束本轮游戏后进行写入数据，并对该关卡的所有存档进行排序，用sort排序，相当于每个关卡都有一
// 个对应的排行榜
//在显示排行榜的时候，根据翻页的rank_page 切换rank_list然后显示


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
	outtextxy(52.5, 195, _T("普通模式:第    关"));
	settextstyle(18, 0, _T("IPix"));
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
	switch (rank_page)
	{
	case 0:
		//输出排名前十
		//想做成居中处理，获得字符串的长度然后操作
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
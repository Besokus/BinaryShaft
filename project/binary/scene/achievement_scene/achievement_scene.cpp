
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

	// 方便显示
	current_data = &data_list[0];


}


void AchievementScene::OnUpdate()
{

}

void AchievementScene::OnDraw() {
	// 背景图
	putimage(0, 0, &img_achievement_background);
	// 按钮
	btn_achievement_rtmenu->OnDraw();
	// 透明打印字体
	setbkmode(TRANSPARENT);
	// 字体
	settextstyle(30, 0, _T("IPix"));

	static TCHAR text[64];
	_stprintf_s(text, _T("第%d页"), current_page + 1);
	outtextxy(195, 520, text);

	// 页面切换效果
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

	// 如果玩家还没选择存档,就提示玩家选择存档
	if (current_data == nullptr)
	{
		settextstyle(50, 0, _T("IPix"));
		outtextxy(100, 350, _T("请先选择存档!!"));

		return;
	}

	// 如果玩家没解锁本关成就,就显示未知状态
	if (!current_data->unlocked_achievement[current_page])
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
		break;
	case 1:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("盖亚！！"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("触发条件:踩上CE"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;
	case 2:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("made in heaven"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("触发条件:跳上3次[TLE]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;
	case 3:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("世界真小"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("跳上3次[MLE]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));


		break;
	case 4:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("左右互博"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("跳上3次[opposite]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;
	case 5:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("芜湖起飞"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("跳上3次[bounce]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;
	case 6:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("闪电神经"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("跳上3次[speed]"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;

	case 7:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("洛谷集邮"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("踩过了所有报错平台"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));


		break;
	case 8:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("GrandMaster"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("获得全部成就"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;
	case 9:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("天选不死人"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("死亡了20次"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));



		break;

	case 10:
		settextstyle(45, 0, _T("IPix"));
		outtextxy(50, 260, _T("部分正确"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 320, _T("跳上20次WA"));

		settextstyle(35, 0, _T("IPix"));
		outtextxy(50, 400, _T(""));

		break;


	}

	putimage(470, 290, &img_achievement[current_page]);

}


void AchievementScene::OnInput(const ExMessage& msg) {
	btn_achievement_rtmenu->OnInput(msg);

	//btn_achievement_detail->OnInput(msg);

	// 处理用户输入，比如按键事件
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

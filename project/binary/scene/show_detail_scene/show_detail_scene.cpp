#include "show_detail_scene.h"

extern SceneManager scene_manager;

extern IMAGE img_detail_background;
extern IMAGE img_AC_detail;
extern IMAGE img_NULL_platform;
extern IMAGE img_AC_platform;
extern IMAGE img_WA_platform;
extern IMAGE img_CE_platform;
extern IMAGE img_SPEED_RIGHT_platform;
extern IMAGE img_SPEED_LEFT_platform;
extern IMAGE img_TLE_platform;
extern IMAGE img_MLE_platform;
extern IMAGE img_death_detail;
extern IMAGE img_ending_detail;
extern IMAGE img_detail_background;
extern IMAGE img_ending_detail;
extern IMAGE img_death_detail;
extern IMAGE image_item_carefully_BBQ;
extern IMAGE image_item_ctrl_Z;
extern IMAGE image_item_helpme_awei;
extern IMAGE image_item_hiraijin;
extern IMAGE image_item_once_again;
extern IMAGE image_item_the_world;

void ShowDetailScene::OnEnter() 
{
	page = 0;
}

void ShowDetailScene::OnDraw()
{
	putimage(0, 0, &img_detail_background);
	setbkmode(TRANSPARENT);

	settextstyle(25, 0, _T("IPix"));
	outtextxy(510, 200, _T("Esc返回"));
	outtextxy(285, 430, _T("第"));
	outtextxy(375, 430, _T("页"));

	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(100, 430, _T("A <- 上一页"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(100, 430, _T("A <- 上一页"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(440, 430, _T("下一页 - > D"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(440, 430, _T("下一页 - > D"));
	}



	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), page + 1);
	outtextxy(335, 430, text);

	switch (page)
	{
	case 0:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("开发者说明:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("在这个充满奇思妙想和无限可能的游戏世界中 ，有一群人默"));
		outtextxy(90, 265, _T("默耕耘 ，用他们的智慧和热情创造了 xcpcer-go-down 。"));
		outtextxy(90, 295, _T("开发者团队: [游戏科学组]"));
		outtextxy(90, 325, _T("开发者成员: 余某  阿氟  Besokus  涵  Minato  土豆"));
		outtextxy(210, 355, _T("yuuki  endl  指短琴长"));
		outtextxy(90, 390, _T("致敬，最优秀的游戏创造者们!"));
		outtextxy(370, 390, _T("———致敬每一位热爱的玩家"));
		break;
	case 1:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("游戏背景:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("你是一位xcpcer，正在OJ平台上进行着正常的刷题训练 ，"));
		outtextxy(90, 265, _T("突然机房断电，你两眼前一片漆黑，并伴随着一种强烈的下坠"));
		outtextxy(90, 295, _T("感，你想要呼喊求助，却感觉自己的嘴好像已经不存在了..."));
		outtextxy(90, 325, _T("终于，你再次感受到了身边的空间，但这个空间不像已不再"));
		outtextxy(90, 355, _T("是过去所熟悉的空间，你来到了只有0和1的空间——你进入到"));
		outtextxy(90, 385, _T("了你写的程序当中 ..."));

		break;
	case 2:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("游戏背景:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("现在，你发现自己不再是血肉之躯，而是一串流动的代码 ，"));
		outtextxy(90, 265, _T("你的意识与程序融为一体。现在，你只能操控键盘上的A和D"));
		outtextxy(90, 295, _T("控制自己移动，随时注意从界面下方升起来的平台，踩在它们"));
		outtextxy(90, 325, _T("上面可能会有神奇的效果呢..."));
		outtextxy(90, 355, _T("你的直觉告诉你，你需要通过所有的题目样例(AC)，才能重"));
		outtextxy(90, 385, _T("返现实世界.否则，就淹没在无尽的代码海洋 。"));
		break;
	case 3:
		putimage(490, 245, &img_AC_platform);
		putimage(490, 290, &img_WA_platform);
		putimage(490, 335, &img_TLE_platform);
		putimage(490, 380, &img_MLE_platform);

		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("平台种类和功能:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("AC: AC分数加1，离目标又近了一步!"));
		outtextxy(90, 295, _T("WA: AC分数减1，快陷入代码海洋了!"));
		outtextxy(90, 340, _T("TLE: 游戏速度开始变化，注意别掉下去噢"));
		outtextxy(90, 385, _T("MLE：地图边界变化，可活动范围又小了!"));
		break;
	case 4:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("平台种类和功能:"));
		putimage(490, 245, &img_CE_platform);
		putimage(490, 290, &img_NULL_platform);
		putimage(490, 335, &img_SPEED_LEFT_platform);
		putimage(490, 380, &img_SPEED_RIGHT_platform);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("CE：直接退出游戏，你迷失在代码世界了!"));
		outtextxy(90, 295, _T("NULL：无事发生，暗自高兴吧!"));
		outtextxy(90, 340, _T("BOUNCE:向上弹起，注意头不要碰到上面!"));
		outtextxy(90, 385, _T("SPEED_RIGHT: 保持平衡，向右加速咯"));
		break;
	case 5:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("道具类型:"));
		putimage(510, 225, &image_item_carefully_BBQ);
		putimage(510, 325, &image_item_ctrl_Z);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("仔细烧烤:平台的速度降到0.5，慢慢思考下"));
		outtextxy(90, 295, _T("一步怎么走，当心平台突然加快噢!!!"));
		outtextxy(90, 340, _T("Ctrl_Z:时光回溯，注意使用时机!否则可能"));
		outtextxy(90, 385, _T("有意想不到的结果..."));

		break;
	case 6:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("道具类型:"));
		putimage(510, 225, &image_item_helpme_awei);
		putimage(510, 325, &image_item_hiraijin);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("阿伟助我:阿伟附身，在使用期间无视所有负面"));
		outtextxy(90, 295, _T("效果，平台不再加快速度!"));
		outtextxy(90, 340, _T("飞雷神:瞬间转移到所示位置，把握时机使用有"));
		outtextxy(90, 385, _T("起死回生之妙用，人类对它的开发不足0.01%.."));

		break;
	case 7:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("道具类型:"));
		putimage(510, 225, &image_item_once_again);
		putimage(510, 325, &image_item_the_world);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("复活甲:复活吧我的爱人!使用后复活玩家，重置"));
		outtextxy(90, 295, _T("到一个初始位置，注意只能触发一次!"));
		outtextxy(90, 340, _T("砸瓦鲁多:时停!游戏暂停5秒，这段时间你可以"));
		outtextxy(90, 385, _T("随意跳动，注意平台突然的移动噢!"));

		break;

	case 8:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("结束场景:"));
		putimage(425, 230, &img_ending_detail);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 320, _T("恭喜你顺利通关，回到了现实世界!"));
		break;
	case 9:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("结束场景:"));
		putimage(425, 230, &img_death_detail);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 320, _T("很遗憾，你彻底地迷失在代码世界了!"));
		break;

	}
}

void ShowDetailScene::OnInput(const ExMessage& msg)
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
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		}
	}

}

void ShowDetailScene::OnUpdate()
{

}

void ShowDetailScene::OnExit()
{


}
#include"CG_scene.h"
#include "../../button/button/button.h"
#include "../../button/menu_button/menu_button.h"


extern Scene* menu_scene;
extern Atlas atlas_CG;
extern SceneManager scene_manager;

void CGScene::OnEnter()
{
	current = 0;
	mciSendString(_T("play cg from 0"), NULL, 0, NULL);
}

void CGScene::OnUpdate()
{

}

void CGScene::OnDraw()
{
	if (current > 11)
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		return;
	}

	putimage(0, 0, atlas_CG.GetImage(current));

	setbkmode(TRANSPARENT);
	settextstyle(20, 0, _T("IPix"));
	settextcolor(RGB(255, 255, 0));

	outtextxy(0, 0, _T("按Esc退出CG"));
	outtextxy(0, 20, _T("按其余键继续CG"));
}

void CGScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYUP)
	{
		if (msg.vkcode == VK_ESCAPE)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		}
		else
		{
			current++;
			return;
		}

	}

	// 鼠标左键
	if (msg.message == WM_LBUTTONDOWN)
	{
		current++;
	}
}

void CGScene::OnExit()
{
	mciSendString(_T("close cg"), NULL, 0, NULL);

}
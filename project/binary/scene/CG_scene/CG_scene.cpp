#include"CG_scene.h"
#include "../../button/button/button.h"
#include "../../button/menu_button/menu_button.h"


extern Scene* menu_scene;
extern Atlas atlas_CG;
extern SceneManager scene_manager;

void CGScene::OnEnter()
{
	current = 0;
	len = atlas_CG.GetSize();
}

void CGScene::OnUpdate()
{

}

void CGScene::OnDraw()
{
	LPCTSTR str = _T("��Esc�˳�CG");
	//setbkmode(TRANSPARENT);

	const clock_t FPS = 1000 / 1;//��ʾһ����ѭ��1�Σ������ÿһ֡��������Ҫ��ʱ��
	int startTime = 0;//ÿ֡��ʼʱ��ʱ��
	int freamTime = 0;//ÿ֡����ʱʵ���ϵ�ʱ��
	if (current < len)
	{
		startTime = clock();
		putimage(0, 0, atlas_CG.GetImage(current));
		current++;

		freamTime = clock() - startTime;
		if (freamTime < FPS)
		{
			Sleep(FPS - freamTime);
		}
	}
	outtextxy(20, 20, str);

}

void CGScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYUP && msg.vkcode == VK_ESCAPE)
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}


}




void CGScene::OnExit()
{


}
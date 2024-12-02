#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  

extern SceneManager scene_manager;
extern IMAGE img_death_background;

void DeathScene::OnEnter()
{
	// �����������ʼ������������ض� ��Դ��״̬
	// ������ʾ��ҵ�������Ϣ��������
}

void DeathScene::OnUpdate()
{


}

int DeathScene::GetPlayerScore()
{
	//������ҷ���
	return 1;
}

void DeathScene::OnDraw()
{
	// �����������������
	// ʹ���ض��Ļ�ͼAPI���ܺ�������ʾ����Ϸ������������ķ���������Ϣ
	// ���磬ʹ��outtextxy��������ã���������ͼ����
	//outtextxy(10, 10, _T("GAME OVER"));
	// ��һ����������ȡ��ҵķ���
	//int score = GetPlayerScore();
	//static TCHAR text[64];
	//_stprintf_s(text, _T("���λ�÷���:%d"), score);  //��ʾ����
	//outtextxy(10, 30, text);
	//outtextxy(10, 50, _T("��������������˵�"));
	putimage(0, 0, &img_death_background);

	// ��¼�������ô���,ȷ������ֻ����һ��
	static int cnt = 0;
	cnt++;
	if (cnt == 1)
	{
		static TCHAR text[64];
		_stprintf_s(text, _T("���յ÷�:%d !"), 114514);

		MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
	}

}

void DeathScene::OnInput(const ExMessage& msg)
{

	if (msg.message == WM_KEYUP)
	{
		// �л������˵�����
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
	}


}

#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  

extern SceneManager scene_manager;
extern IMAGE img_death_background;

void DeathScene::OnEnter()
{
	mciSendString(_T("play resources/����.mp3 from 0"), NULL, 0, NULL);
	mciSendString(_T("stop bgm_normal_1"), NULL, 0, NULL);
	static TCHAR text[64];
	_stprintf_s(text, _T("���յ÷�:%d !"), 114514);

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
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
	putimage(0, 0, &img_death_background);
}

void DeathScene::OnInput(const ExMessage& msg)
{
	// ���̰���
	if (msg.message == WM_KEYUP)
	{
		// �л������˵�����
		scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
	}

	// ������
	if (msg.message == WM_LBUTTONDOWN)
	{
		// �л������˵�����
		scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
	}

}

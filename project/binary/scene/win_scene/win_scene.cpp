#include "win_scene.h"


extern IMAGE img_win_background;
extern WinReturnButton* btn_win_return;
extern WinNextButton* btn_win_next;


void WinScene::OnEnter()
{
	btn_win_next->OnEnter();
	btn_win_return->OnEnter();
	mciSendString(_T("play resources/Ê¤Àû.mp3.mp3 from 0"), NULL, 0, NULL);
}


void WinScene::OnUpdate()
{
}




void WinScene::OnDraw()
{
	putimage(0, 0, &img_win_background);

	//
	btn_win_return->OnDraw();
	btn_win_return->OnDraw();
	btn_win_next->OnDraw();

}

void WinScene::OnInput(const ExMessage& msg)
{
	btn_win_next->OnInput(msg);
	btn_win_return->OnInput(msg);

	if (msg.message == WM_KEYDOWN)
	{

	}
}

void WinScene::OnExit()
{

}
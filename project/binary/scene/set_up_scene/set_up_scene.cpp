#include "set_up_scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/music_control_button/set_up_button.h"
#include "../menu_scene/menu_scene.h"

extern int volume_bgm;
extern int volume_sound;

extern SceneManager scene_manager;

extern MusicBKUP* btn_musicbkup;
extern MusicBKDown* btn_musicbkdown;
extern MusicEFUP* btn_musiceffup;
extern MusicEFDown* btn_musiceffdown;

extern IMAGE img_set_up_background;

extern bool pause_back;

void SetUpScene::OnEnter()
{


	btn_musicbkup->OnEnter();
	btn_musicbkdown->OnEnter();
	btn_musiceffup->OnEnter();
	btn_musiceffdown->OnEnter();



}

void SetUpScene::OnUpdate()
{
	static TCHAR text[64];

	// CG音乐
	_stprintf_s(text, _T("setaudio cg volume to %d"), volume_bgm);
	mciSendString(text, NULL, 0, NULL);

	// 菜单音乐
	_stprintf_s(text, _T("setaudio bgm_menu_1 volume to %d"), volume_bgm);
	mciSendString(text, NULL, 0, NULL);

	// 普通模式
	_stprintf_s(text, _T("setaudio bgm_normal_1 volume to %d"), volume_bgm);
	mciSendString(text, NULL, 0, NULL);

	// 结局cg音乐
	_stprintf_s(text, _T("setaudio bgm_ending_1 volume to %d"), volume_bgm);
	mciSendString(text, NULL, 0, NULL);

	// 挑战模式
	_stprintf_s(text, _T("setaudio bgm_challenge_1 volume to %d"), volume_bgm);
	mciSendString(text, NULL, 0, NULL);


	// 音效
	_stprintf_s(text, _T("setaudio resources/飞雷神.MP3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/复活.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/胜利.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/死亡.mp3 volume to %d"), (int)(volume_sound * 1.2));
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/速度减缓.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/跳跃音效.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/通关音效.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/救救我.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/ctrlz.MP3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/DIO时停.mp3 volume to %d"), volume_sound);
	mciSendString(text, NULL, 0, NULL);

	_stprintf_s(text, _T("setaudio resources/Ac音效.mp3 volume to %d"), (int)(volume_sound * 0.3));
	mciSendString(text, NULL, 0, NULL);


}

void SetUpScene::OnDraw()
{

	putimage(0, 0, &img_set_up_background);

	static TCHAR text[64];

	settextstyle(50, 0, _T("IPix"));
	settextcolor(RGB(255, 255, 255));
	setbkmode(TRANSPARENT);

	outtextxy(50, 320, _T("背景音乐大小:"));
	outtextxy(50, 380, _T("游戏音效大小:"));

	_stprintf_s(text, _T("%d"), volume_bgm / 10);
	outtextxy(400, 320, text);
	_stprintf_s(text, _T("%d"), volume_sound / 10);
	outtextxy(400, 380, text);

	btn_musicbkup->OnDraw();
	btn_musicbkdown->OnDraw();
	btn_musiceffup->OnDraw();
	btn_musiceffdown->OnDraw();

	outtextxy(200, 600, _T("按任意键返回"));

}

void SetUpScene::OnInput(const ExMessage& msg)
{

	btn_musicbkup->OnInput(msg);
	btn_musicbkdown->OnInput(msg);
	btn_musiceffup->OnInput(msg);
	btn_musiceffdown->OnInput(msg);

	if (msg.message==WM_KEYDOWN)
	{
		if (pause_back)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::Pause);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		}
	}
}

void SetUpScene::OnExit()
{

}


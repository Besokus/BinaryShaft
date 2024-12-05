#pragma once

#include "../../data.h"
#include "../button/button.h"
extern int level;
extern Data* current_data;

// ��ͨģʽ
class SelectModeNormalButton :public Button
{
public:
	SelectModeNormalButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~SelectModeNormalButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
	}
};


// ��սģʽ
class SelectModeChallengeButton :public Button
{
public:
	SelectModeChallengeButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~SelectModeChallengeButton() = default;

protected:
	void OnClick()
	{
		level = 10;
		if (current_data->unlocked_level < 10)
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("����ͨ��ǰ��Ĺؿ�֮��,������ս!"));

			MessageBox(GetHWnd(), text, _T("��ܰ��ʾ"), MB_OK);
		}
		scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
	}
};

// ���ز˵�
class SelectModeReturnButton :public Button
{
public:
	SelectModeReturnButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~SelectModeReturnButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}
};
#pragma once

#include "../button/button.h"
extern int level;

// 普通模式
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


// 挑战模式
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
		scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
	}
};

// 返回菜单
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
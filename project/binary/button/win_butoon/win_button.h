#pragma once
#include "../button/button.h"

extern bool running;

// 下一关
class WinNextButton :public Button
{
public:
	WinNextButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~WinNextButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Next);
	}
};

// 返回主菜单
class WinReturnButton :public Button
{
public:
	WinReturnButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~WinReturnButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}
};

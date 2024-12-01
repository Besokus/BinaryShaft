#pragma once
#include "../button/button.h"


//返回游戏
class PauseBackGameButton :public Button
{
public:
	PauseBackGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~PauseBackGameButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Game);
	}
};

//游戏设置
class PauseSetUpButton :public Button
{
public:
	PauseSetUpButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~PauseSetUpButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::SetUp);
	}
};

//返回菜单
class PauseBackMenuButton :public Button
{
public:
	PauseBackMenuButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~PauseBackMenuButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}
};



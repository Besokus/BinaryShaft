#pragma once
#include "../button/button.h"


//������Ϸ
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

//��Ϸ����
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

//���ز˵�
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



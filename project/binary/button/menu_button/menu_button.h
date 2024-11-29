#pragma once

#include "../button/button.h"

extern bool running;

// ��ʼ��Ϸ
class MenuStartButton :public Button
{
public:
	MenuStartButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuStartButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
	}
};


// ��Ϸ˵��
class MenuShowDetailButton :public Button
{
public:
	MenuShowDetailButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuShowDetailButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::ShowDetail);
	}
};

// ��Ϸ����
class MenuSetUpButton :public Button
{
public:
	MenuSetUpButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuSetUpButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::SetUp);
	}
};

// ���а�
class MenuRankButton :public Button
{
public:
	MenuRankButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuRankButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Rank);
	}
};

// �ɾ�
class MenuAchievementButton :public Button
{
public:
	MenuAchievementButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuAchievementButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Achievemnt);
	}
};

class MenuExitButton :public Button
{
public:
	MenuExitButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~MenuExitButton() = default;

protected:
	void OnClick()
	{
		running = false;
	}
};
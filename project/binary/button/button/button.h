#pragma once
/*



*/
#include <graphics.h>
#include "../../scene/scene_manager/scene_manager.h"
extern SceneManager scene_manager;

class Button {
private:
	// 按钮状态
	enum class Status
	{
		Idle = 0,		// 默认状态
		Hovered,		// 被选中
		Pushed			// 被按下
	};

private:
	Status status = Status::Idle;
	RECT region;					// 按钮的区域
	IMAGE img_idle;
	IMAGE img_hovered;
	IMAGE img_pushed;

protected:
	virtual void OnClick() = 0;

public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);

	~Button() = default;

	void OnDraw();

	void OnInput(const ExMessage& msg);

private:
	bool CheckCursorHit(int x, int y);
};

class StartButton :public Button
{
public:
	StartButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}
	~StartButton() = default;

protected:
	void OnClick()
	{
		//scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
	}
};

class FindButton :public Button
{
public:
	FindButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}
	~FindButton() = default;

protected:
	void OnClick()
	{

	}
};

class SetUpButton :public Button 
{
public:
	SetUpButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}
	~SetUpButton() = default;

protected:
	void OnClick()
	{

	}
};


class AchievementButton :public Button 
{

};



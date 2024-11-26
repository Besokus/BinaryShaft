#pragma once
/*



*/
#include <graphics.h>

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

class StartGameButton :public Button
{

};

class QuitGameButton :public Button
{

};

class RankButton :public Button 
{

};


class AchievementButton :public Button 
{

};

class SetUpButton :public Button 
{


};


#pragma once
/*



*/
#include <graphics.h>

class Button {
private:
	// ��ť״̬
	enum class Status
	{
		Idle = 0,		// Ĭ��״̬
		Hovered,		// ��ѡ��
		Pushed			// ������
	};

private:
	Status status = Status::Idle;
	RECT region;					// ��ť������
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


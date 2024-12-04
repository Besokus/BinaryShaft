#include "button.h"

extern void PutImage(int x, int y, IMAGE* img);

Button::Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
{
	region = rect;
	this->height = height;
	this->width = width;

	loadimage(&img_idle, path_img_idle, width, height);
	loadimage(&img_hovered, path_img_hovered, width, height);
	loadimage(&img_pushed, path_img_pushed, width, height);
}

void Button::OnEnter()
{
	// 将状态重置为默认
	status = Status::Idle;
}

void Button::OnDraw()
{
	switch (status)
	{
	case Status::Idle:
		PutImage(region.left, region.top, &img_idle);
		break;
	case Status::Hovered:
		PutImage(region.left, region.top, &img_hovered);
		break;
	case Status::Pushed:
		PutImage(region.left, region.top, &img_pushed);
		break;
	}
}

void Button::OnInput(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_MOUSEMOVE:
		if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
			status = Status::Hovered;
		else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
			status = Status::Idle;
		break;
	case WM_LBUTTONDOWN:
		if (CheckCursorHit(msg.x, msg.y))
			status = Status::Pushed;
	case WM_LBUTTONUP:
		if (status == Status::Pushed)
		{
			OnClick();
			status = Status::Idle;
		}
		break;
	default:
		break;
	}
}

bool Button::CheckCursorHit(int x, int y)
{
	return x >= region.left && x <= region.right
		&& y >= region.top && y <= region.bottom;
}
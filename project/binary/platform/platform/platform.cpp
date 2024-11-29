#include "platform.h"

extern bool is_debug;


Platform::Platform(IMAGE img_platform)
{
	this->img_platform = img_platform;
	velocity.y = -up_velocity;
}

void Platform::OnUpdate()
{
	if (is_visited && change_times > 0)
	{
		PlatformChange();
		change_times--;
	}

	shape.y += velocity.y;

	render_position.x = (int)shape.left;
	render_position.y = (int)shape.y - 20;
}


void Platform::OnDraw()
{
	PutImage(render_position.x, render_position.y, &img_platform);

	if (is_debug)
	{
		// 被踩过且离开了则显示黄线
		if (is_leave)
		{
			setlinecolor(RGB(0, 255, 255));
			line((int)shape.left, (int)shape.y, (int)shape.right, (int)shape.y);
		}
		// 否则显示红线
		else
		{
			setlinecolor(RGB(255, 0, 0));
			line((int)shape.left, (int)shape.y, (int)shape.right, (int)shape.y);
		}
	}
}


void Platform::SetPosition(int x, int y)
{
	shape.left = (float)x;
	shape.right = shape.left + 100;
	shape.y = (float)y;
}

void Platform::Disappear()
{
	is_exist = false;
}

bool Platform::CheckExist()
{
	return is_exist;
}
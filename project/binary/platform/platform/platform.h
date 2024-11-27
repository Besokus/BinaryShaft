#pragma once

/*
	负责人:
	功能:
		1.
		2.
	示例:
		1.



*/
#include <graphics.h>

extern void PutImage(int x, int y, IMAGE* img);

class Platform
{
public:

	bool is_exist = true;

	bool is_player_on = false; // 判断是否有玩家在上面

	typedef struct CollisionShape
	{
		float left, right;
		float y;
	}CollisionShape;

	CollisionShape shape;

	POINT render_position; // 渲染位置

	IMAGE img_platform;
public:
	Platform() = default;

	~Platform() = default;

	// virtual void PlatformChange() = 0;

	void OnEnter(IMAGE img_platform)
	{
		this->img_platform = img_platform;
	}

	void OnUpdate()
	{
		if (is_player_on)
		{
			//PlatformChange();
		}

		render_position.x = (int)shape.left;
		render_position.y = (int)shape.y;
	}

	void OnDraw()
	{
		PutImage(render_position.x, render_position.y, &img_platform);
		setlinecolor(RGB(255, 0, 0));
		line(shape.left, shape.y, shape.right, shape.y);
	}

	void SetPosition(int x, int y)
	{
		shape.left = (int)x;
		shape.right = shape.left +150;
		shape.y = (int)y;
	}

	//bool CheckCollision(Player* player)
	//{
	//	return false;
	//}

	void Disappear()
	{
		is_exist = false;
	}

	bool CheckExist()
	{
		return is_exist;
	}
};
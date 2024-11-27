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
#include "../../player/player.h"

extern void PutImage(int x, int y, IMAGE* img);

extern const int PLAYER_HEIGHT;

class Platform
{
private:
	// int speed;
	// int length;
	bool is_exist = true;
	struct CollisionShape
	{
		float left, right;
		float y;

	}shape;

	POINT render_position; // 渲染位置

	IMAGE img_platform;
public:
	Platform() = default;
	~Platform() = default;

	void OnEnter(IMAGE img_platform)
	{
		this->img_platform = img_platform;
	}

	virtual void OnUpdate() {}

	void OnDraw()
	{
		setlinecolor(RGB(255, 0, 0));
		line(render_position.x, render_position.y, render_position.x + 100, render_position.y);
		PutImage(render_position.x, render_position.y, &img_platform);
	}

	void SetPosition(int x, int y)
	{
		shape.left = x;
		shape.right = shape.left + 100;
		shape.y = y;

		render_position.x = (int)shape.left + 30;
		render_position.y = (int)shape.y;
	}

	struct CollisionShape GetCollisonShape()
	{
		return shape;
	}

	bool CheckCollision(Player* player)
	{
		if (player->GetPosition().y + PLAYER_HEIGHT > shape.y && player->GetPosition().y + PLAYER_HEIGHT - 10 < shape.y)
		{
			if (player->GetPosition().x > shape.left && player->GetPosition().x < shape.right)
			{
				return true;
			}
		}
		return false;
	}

	void Disappear()
	{
		is_exist = false;
	}

	bool CheckExist()
	{
		return is_exist;
	}
};
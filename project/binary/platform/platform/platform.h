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
#include "../../vector2/vector2.h"

extern void PutImage(int x, int y, IMAGE* img);

class Platform
{
public:
    float up_velocity = 1.0f;

	bool is_exist = true;

	bool is_player_on = false; // 判断是否有玩家在上面

	bool is_visited = false;

	bool is_leave = false;

	typedef struct CollisionShape
	{
		float left, right;
		float y;
	}CollisionShape;

	Vector2 velocity = { 0,-up_velocity };	// 平台速度

	CollisionShape shape = { 0,0 };

	POINT render_position = { 0,0 }; // 渲染位置

	IMAGE img_platform;
public:
	Platform(IMAGE img_platform)
	{
		this->img_platform = img_platform;
		velocity.y = -up_velocity;
	}

	~Platform() = default;

	// virtual void PlatformChange() = 0;

	//void OnEnter(IMAGE img_platform)
	//{
	//	this->img_platform = img_platform;
	//}

	void OnUpdate()
	{
		if (is_player_on)
		{
			//PlatformChange();
		}

		shape.y += velocity.y;

		render_position.x = (int)shape.left;
		render_position.y = (int)shape.y;
	}

	void OnDraw()
	{
		PutImage(render_position.x, render_position.y, &img_platform);
		setlinecolor(RGB(255, 0, 0));
		line((int)shape.left, (int)shape.y, (int)shape.right, (int)shape.y);
	}

	void SetPosition(int x, int y)
	{
		shape.left = (float)x;
		shape.right = shape.left + 100;
		shape.y = (float)y;
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
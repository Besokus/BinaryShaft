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

	}platform_shape;
public:
	Platform() = default;
	~Platform() = default;

	virtual void OnUpdate() {}

	virtual void OnDraw() {}

	virtual void OnInput(const ExMessage& msg) {}

	struct CollisionShape GetCollisonShape() 
	{
		return platform_shape;
	}

	bool CheckCollision(const Player& player);

	void Disappear()
	{
		is_exist = false;
	}

	bool CheckExist()
	{
		return is_exist;
	}
};
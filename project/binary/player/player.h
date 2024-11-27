#pragma once

/*
	负责人:ja1u0va
	功能:
		1.
		2.
	示例:
		1.



*/
#include"../animation/animation.h"
#include "../vector2/vector2.h"
#include <graphics.h>
#include <iostream>

class Player
{
public:
	const float run_velocity = 2.5;			// 设定x方向速度
	const float speed_velocity = 0.1;		// 设定speed平台速度
	const float gravity = 0.1;

	// const int PLAYER_WIDTH = 80;
	// const int PLAYER_HEIGHT = 80;
	const int delta = 10;
private:
	Vector2 position;	// 角色位置
	Vector2 velocity;				// 角色速度

	bool is_right_key_down = false;
	bool is_left_key_down = false;



	bool is_facing_right = false;

	bool is_on_speed_platform = false;

	Animation* current_animation = nullptr;

public:
	bool is_on_platform = false;
public:
	Player();

	~Player() = default;

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void SetPosition(int x, int y);

	Vector2 GetPosition()
	{
		return position;
	}

};
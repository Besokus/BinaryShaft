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
#include <graphics.h>
#include <iostream>

class Player
{
public:
	const int PLAYER_SPEED = 3;
	const int PLAYER_QUICK_SPEED = 5;
	// const int PLAYER_WIDTH = 80;
	// const int PLAYER_HEIGHT = 80;
	const int delta = 10;
private:
	POINT position = { 500,500 };
	bool is_right_key_down = false;
	bool is_left_key_down = false;
	bool is_on_platform = false;
	bool is_move_left = false;
	bool is_move_right = false;
	bool is_facing_right = false;
	Animation* current_animation = nullptr;

public:
	Player();

	~Player() = default;

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void SetPosition(int x, int y);
};
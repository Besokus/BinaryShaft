#pragma once

/*
	������:ja1u0va
	����:
		1.
		2.
	ʾ��:
		1.



*/
#include"../animation/animation.h"
#include "../vector2/vector2.h"
#include <graphics.h>
#include <iostream>

class Player
{
public:
	const float run_velocity = 2.5;			// �趨x�����ٶ�
	const float speed_velocity = 0.1;		// �趨speedƽ̨�ٶ�
	const float gravity = 0.1;

	// const int PLAYER_WIDTH = 80;
	// const int PLAYER_HEIGHT = 80;
	const int delta = 10;
private:
	Vector2 position;	// ��ɫλ��
	Vector2 velocity;				// ��ɫ�ٶ�

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
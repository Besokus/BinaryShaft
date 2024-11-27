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
#include "../platform/platform/platform.h"
#include <graphics.h>
#include <iostream>

class Player
{
public:
	const float run_velocity = 2.5;			// �趨x�����ٶ�
	const float speed_velocity = 0.1;		// �趨speedƽ̨�ٶ�
	const float gravity = 0.2;				// �趨�������ٶ�

	const int delta = 10;					// �趨���ʱ��
public:
	Animation* current_animation = nullptr;
	
	Vector2 position;	// ��ɫλ��
	Vector2 velocity;	// ��ɫ�ٶ�
	Vector2 size;		// ��ɫ��С

	POINT render_position;

	bool is_right_key_down = false;
	bool is_left_key_down = false;

	bool is_on_speed_platform = false;

public:
	bool is_on_platform = false;
public:
	Player();

	~Player() = default;

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void UpdatePosition();

	void SetPosition(int x, int y);

	void CheckCollison(Platform* platform);
};
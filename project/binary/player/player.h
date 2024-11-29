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
	const float run_velocity = 2.0f;			// �趨x�����ٶ�
	const float speed_velocity = 0.1f;			// �趨speedƽ̨�ٶ�
	const float gravity = 0.2f;					// �趨�������ٶ�

	const int delta = 10;						// �趨���ʱ��
public:
	Animation* current_animation = nullptr;

	Vector2 position = { 0,0 };	// ��ɫλ��
	Vector2 velocity = { 0,0 };	// ��ɫ�ٶ�
	Vector2 size = { 0,0 };		// ��ɫ��С

	POINT render_position = { 0,0 };

	bool is_right_key_down = false;
	bool is_left_key_down = false;
	bool is_on_speed_platform = false;
	bool is_on_platform = false;
	bool is_alive = true;

	float platform_velocity = 0;

public:
	Player();

	~Player() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	// �������λ��
	void UpdatePosition();

	void SetPosition(int x, int y);

	// �ж�����Ƿ���ƽ̨������ײ
	void CheckCollison(Platform* platform);

	void CheckAlive();
};
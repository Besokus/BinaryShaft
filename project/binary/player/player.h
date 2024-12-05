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
#include "../platform/platform/platform.h"
#include <graphics.h>
#include <iostream>

class Platform;
class Map_Msg;

class Player
{
public:
	const float run_velocity = 4.0f;			// 设定x方向速度
	const float speed_velocity = 0.1f;			// 设定speed平台速度
	const float gravity = 0.4f;				// 设定重力加速度
	const float acceleration_x = 0.2f;
	const int delta = 10;						// 设定间隔时间
	float max_speed_y = 10;                //最高y轴速度
public:
	Animation* current_animation = nullptr;

	Vector2 position = { 0,0 };	// 角色位置
	Vector2 velocity = { 0,0 };	// 角色速度
	Vector2 size = { 0,0 };		// 角色大小

	POINT render_position = { 0,0 };

	bool is_right_key_down = false;
	bool is_left_key_down = false;
	bool is_on_speed_platform = false;
	bool is_on_platform = false;
	bool is_alive = true;
	bool is_jumping = false;
	int jumping_time = 30;

	int health = 12;

	float platform_velocity = 0;

	Platform* down_platform = nullptr;

	Map_Msg* map_msg = nullptr;

public:
	Player(Map_Msg* map_msg);

	~Player() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	// 更新玩家位置
	void UpdatePosition();

	void SetPosition(int x, int y);

	// 判断玩家是否与平台发生碰撞
	void CheckCollison(Platform* platform);

	void CheckAlive();
};
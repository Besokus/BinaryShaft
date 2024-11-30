#pragma once

/*
	负责人:ja1u0va
	功能:
		1.
	示例:


*/
#include <graphics.h>
#include "../../vector2/vector2.h"
#include "../../player/player.h"

extern void PutImage(int x, int y, IMAGE* img);

class Player;

class Platform
{
private:
	bool is_exist = true;		// 平台是否存在
public:
	float up_velocity = 1.0f;	// 平台上升速度

	bool is_visited = false;    // 平台是否有玩家踩过
	bool is_leave = false;		// 玩家是否离开过平台
	bool is_on_platform = false;// 玩家是否在平台上

	int change_times = 1;

	typedef struct CollisionShape
	{
		float left, right;
		float top, bottom;

	}CollisionShape;

	Vector2 velocity = { 0,-up_velocity };	// 平台速度

	CollisionShape shape = { 0,0 };

	POINT render_position = { 0,0 }; // 渲染位置

	IMAGE img_platform;
public:
	Platform(IMAGE img_platform);

	~Platform() = default;

	virtual void PlatformChange(Player* player) = 0;

	void OnUpdate();

	void OnDraw();

	void SetPosition(int x, int y);

	// 平台消失方法
	void Disappear();

	// 检查平台是否存在
	bool CheckExist();

	void CheckCollison(Player* player);

	bool CheckLeave(Player* player);
};
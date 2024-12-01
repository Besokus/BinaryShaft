#pragma once

/*
	������:ja1u0va
	����:
		1.
	ʾ��:


*/
#include <graphics.h>
#include "../../vector2/vector2.h"
#include "../../player/player.h"
#include "../../map/map.h"

extern void PutImage(int x, int y, IMAGE* img);

class Player;

class Platform
{
private:
	bool is_exist = true;		// ƽ̨�Ƿ����
public:
	float up_velocity = 1.0f;	// ƽ̨�����ٶ�

	bool is_visited = false;    // ƽ̨�Ƿ�����Ҳȹ�
	bool is_leave = false;		// ����Ƿ��뿪��ƽ̨
	bool is_on_platform = false;// ����Ƿ���ƽ̨��

	int change_times = 1;

	Map_Msg* map_msg = nullptr; // ����ؿ���Ϣ

	typedef struct CollisionShape
	{
		float left, right;
		float top, bottom;

	}CollisionShape;

	Vector2 velocity = { 0,-up_velocity };	// ƽ̨�ٶ�

	CollisionShape shape = { 0,0 };

	POINT render_position = { 0,0 }; // ��Ⱦλ��

	IMAGE img_platform;
public:
	Platform(IMAGE img_platform, Map_Msg* map_msg);

	~Platform() = default;

	virtual void PlatformChange(Player* player, int direction = 0) = 0;

	void OnUpdate();

	void OnDraw();

	void SetPosition(int x, int y);

	// ƽ̨��ʧ����
	void Disappear();

	// ���ƽ̨�Ƿ����
	bool CheckExist();

	void CheckCollison(Player* player);

	bool CheckLeave(Player* player);
};
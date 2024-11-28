#pragma once

/*
	������:
	����:
		1.
		2.
	ʾ��:
		1.

*/
#include <graphics.h>
#include "../../vector2/vector2.h"

extern void PutImage(int x, int y, IMAGE* img);

class Platform
{
private:
	bool is_exist = true;		// ƽ̨�Ƿ����
public:
    float up_velocity = 1.0f;	// ƽ̨�����ٶ�

	bool is_visited = false;    // ƽ̨�Ƿ�����Ҳȹ�
	bool is_leave = false;		// ����Ƿ��뿪��ƽ̨

	int change_times = 1;

	typedef struct CollisionShape
	{
		float left, right;
		float y;

	}CollisionShape;

	Vector2 velocity = { 0,-up_velocity };	// ƽ̨�ٶ�

	CollisionShape shape = { 0,0 };

	POINT render_position = { 0,0 }; // ��Ⱦλ��

	IMAGE img_platform;
public:
	Platform(IMAGE img_platform);

	~Platform() = default;

	//virtual void PlatformChange();

	void OnUpdate();

	void OnDraw();

	void SetPosition(int x, int y);

	// ƽ̨��ʧ����
	void Disappear();

	// ���ƽ̨�Ƿ����
	bool CheckExist();

};
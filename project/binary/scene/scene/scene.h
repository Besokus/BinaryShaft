#pragma once

/*
	������:ja1u0va
	����:
		1.
		2.
	ʾ��:
		1.



*/

#include <graphics.h>

class Scene
{
private:

public:
	Scene() = default;
	~Scene() = default;

	// �麯��,���ڼ̳�,����ģ��
	// ������淽��
	virtual void OnEnter() {}
	// ˢ�½��淽��
	virtual void OnUpdate() {}
	// ���ƽ��淽��
	virtual void OnDraw() {}
	// ����������뷽��
	virtual void OnInput(const ExMessage& msg) {}
	// �˳�����
	virtual void OnExit() {}

};
#pragma once

/*
* ��ͣ
	������:endl
	����:
		1.�������µļܹ�ģʽ����������ĵ��Ĺ��ܣ�����ز�
		2.
*/

#include "../scene/scene.h"

class PauseScene :public Scene
{

private:

public:
	PauseScene() = default;
	~PauseScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
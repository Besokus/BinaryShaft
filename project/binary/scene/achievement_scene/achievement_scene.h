#pragma once
#include "../scene/scene.h"

/*
�ɾͽ���
	�����ˣ�minato
	���ܣ����������ĵ�����ɹ��ܣ�����ز�
*/

class AchieveScene :public Scene
{
private:

public:
	AchieveScene() = default;
	~AchieveScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

};
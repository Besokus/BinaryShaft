#pragma once
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include"../../button/achievement_button/achievement_button.h"
#include <iostream>	

/*
�ɾͽ���
	�����ˣ�minato
	���ܣ����������ĵ�����ɹ��ܣ�����ز�
*/

class AchievementScene :public Scene
{
private:

public:
	AchievementScene() = default;
	~AchievementScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

};
#pragma once

/*
δ��ɣ�
	����ͼ��ѡ��
	ͨ��ʱ��ӡ��ҷ�������ʱ����Ϣ
	��һ�ذ�ť����ת���ܵľ���ʵ�ֺ���ͼ






*/

#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include "../../button/win_butoon/win_button.h"
#include <iostream>	

class WinScene :public Scene
{

private:

public:
	WinScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};

#pragma once

#pragma once

/*
* ���ý���
	������:yuuki
	����:
		1.�������еļܹ�ģʽ�������ĵ�����ɹ�������ز�
		2.�������������������û�е����ݣ��Ȳ���
*/

#include "../scene/scene.h"

class SetUpScene :public Scene
{

private:

public:
	SetUpScene() = default;
	~SetUpScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
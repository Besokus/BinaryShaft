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
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
class SetUpScene :public Scene
{

private:
	string m_bk;
	string m_eff;

public:
	SetUpScene() = default;
	~SetUpScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();


};
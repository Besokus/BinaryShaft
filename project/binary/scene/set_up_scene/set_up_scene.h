#pragma once

#pragma once

/*
* 设置界面
	负责人:yuuki
	功能:
		1.根据已有的架构模式、需求文档，完成功能填充素材
		2.关于设计音量。。。还没有的数据，先不动
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
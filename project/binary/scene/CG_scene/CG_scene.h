/*
CG界面
负责人：指短琴长
	功能：
*/


#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include <iostream>	
#include"../../animation/animation.h"

class CGScene :public Scene
{

private:
	int current;     //记录当前播放到第几张CG
	int len;         //记录CG长度

public:
	CGScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
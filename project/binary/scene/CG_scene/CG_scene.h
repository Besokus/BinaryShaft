/*
CG����
�����ˣ�ָ���ٳ�
	���ܣ�
*/


#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"
#include "../../button/button/button.h"
#include <iostream>	
#include"../../animation/animation.h"

class CGScene :public Scene
{

private:
	int current;     //��¼��ǰ���ŵ��ڼ���CG
	int len;         //��¼CG����

public:
	CGScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
#include "set_up_scene.h"
#include "../scene_manager/scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;

void SetUpScene::OnEnter()
{
	std::cout << "�������ý���" << std::endl;
}

void SetUpScene::OnUpdate()
{

}

void SetUpScene::OnDraw()
{
	outtextxy(10, 10, _T("�������ý���"));
}

void SetUpScene::OnInput(const ExMessage& msg)
{

}

void SetUpScene::OnExit()
{

}
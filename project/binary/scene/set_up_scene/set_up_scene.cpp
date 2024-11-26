#include "set_up_scene.h"
#include "../scene_manager/scene_manager.h"
#include <iostream>

extern SceneManager scene_manager;

void SetUpScene::OnEnter()
{
	std::cout << "进入设置界面" << std::endl;
}

void SetUpScene::OnUpdate()
{

}

void SetUpScene::OnDraw()
{
	outtextxy(10, 10, _T("这是设置界面"));
}

void SetUpScene::OnInput(const ExMessage& msg)
{

}

void SetUpScene::OnExit()
{

}
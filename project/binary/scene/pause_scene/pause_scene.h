#pragma once

/*
* 暂停
	负责人:endl
	功能:
		1.根据最新的架构模式，完成需求文档的功能，填充素材
		2.
*/

#include "../scene/scene.h"

class PauseScene :public Scene
{

private:

public:
	PauseScene() = default;
	~PauseScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
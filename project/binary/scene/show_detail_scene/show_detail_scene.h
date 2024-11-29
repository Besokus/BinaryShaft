#pragma once
#include "../scene/scene.h"
#include "../scene_manager/scene_manager.h"

class ShowDetailScene : public Scene
{

private:


public:
	ShowDetailScene() = default;
	~ShowDetailScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();

};
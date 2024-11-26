#pragma once

/*

*/
#include "../scene/scene.h"


class SelectLevelScene :public Scene
{
public:
	const int LEVELNUM = 20;
private:


public:
	SelectLevelScene() = default;
	~SelectLevelScene() = default;

	void OnEnter();

	void OnUpdate();

	void OnDraw();

	void OnInput(const ExMessage& msg);

	void OnExit();


};
#pragma once
/*
	负责人:
	功能:
		1.
		2.
	示例:
		1.


*/
#include "../scene/scene.h"

class SceneManager
{
private:
	Scene* current_scene = nullptr;

public:
	// 枚举界面类型
	enum class SceneType
	{
		Menu,
		Game,
		Pause,
		SetUp,
		SelectLevel

	};
public:
	SceneManager() = default;
	~SceneManager() = default;

	// 设置当前的场景
	void SetCurrentScene(Scene* scene);

	// 实现场景间的切换
	void SwitchTo(SceneType type);

	// 更新场景的函数
	void OnUpdate();

	// 绘制场景的函数
	void OnDraw();

	// 接受输入的函数
	void OnInput(const ExMessage& msg);
};
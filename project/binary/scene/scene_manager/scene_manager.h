#pragma once
/*
	������:
	����:
		1.
		2.
	ʾ��:
		1.


*/
#include "../scene/scene.h"

class SceneManager
{
private:
	Scene* current_scene = nullptr;

public:
	// ö�ٽ�������
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

	// ���õ�ǰ�ĳ���
	void SetCurrentScene(Scene* scene);

	// ʵ�ֳ�������л�
	void SwitchTo(SceneType type);

	// ���³����ĺ���
	void OnUpdate();

	// ���Ƴ����ĺ���
	void OnDraw();

	// ��������ĺ���
	void OnInput(const ExMessage& msg);
};
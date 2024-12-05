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
#include"../set_up_scene/set_up_scene.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

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
		SelectLevel,
		SelectMode,
		Death,
		ShowDetail,
		Rank,
		Achievemnt,
		Next,
		Win,
		CG,
		Login,
		SelectItem
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
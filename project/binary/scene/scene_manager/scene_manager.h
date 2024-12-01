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
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

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
		SelectLevel,
		SelectMode,
		Death,
		ShowDetail,
		Rank,
		Achievemnt,
		Next,
		Win,
		CG,
	};
	typedef enum Choose
	{
		music_BK = 1,
		music_EFF
	}opt;
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

	//设置静态操作文件函数
	static void Opertate_File(opt choice, string x)
	{
		switch (choice)
		{
		case music_BK:
		{
			ofstream ofs("resources/Music_Data/Music_Bk.txt");
			if (ofs.is_open())
			{
				ofs << x << endl;
			}
			else
				printf("Error!\n");
			ofs.close();
			break;
		}

		case music_EFF:
		{
			ofstream ofs("resources/Music_Data/Music_Eff.txt");
			if (ofs.is_open())
			{
				ofs << x << endl;
			}
			else
				printf("Error!\n");
			ofs.close();
			break;
		}

		}
	}
};
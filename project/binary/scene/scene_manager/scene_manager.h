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
	};
	typedef enum Choose
	{
		music_BK = 1,
		music_EFF
	}opt;
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

	//���þ�̬�����ļ�����
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
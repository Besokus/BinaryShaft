#pragma once
#include "../button/button.h"
extern SetUpScene* setup_scene;
//音量调节按钮
class MusicBKUP : public Button
{
public:
	MusicBKUP(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}



	~MusicBKUP() = default;

protected:
	void OnClick()
	{
		int temp = stoi(setup_scene->GetElement("music_BK"));
		temp += 1;
		if (temp >= 0 && temp <= 100)
		{
			setup_scene->SetElement("music_BK", to_string(temp));
			SceneManager::Opertate_File(SceneManager::opt::music_BK, to_string(temp));
		}

	}

};

class MusicBKDown : public Button
{
public:
	MusicBKDown(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}

	~MusicBKDown() = default;

protected:
	void OnClick()
	{
		int temp = stoi(setup_scene->GetElement("music_BK"));
		temp -= 1;
		if (temp >= 0 && temp <= 100)
		{
			setup_scene->SetElement("music_BK", to_string(temp));
			SceneManager::Opertate_File(SceneManager::opt::music_BK, to_string(temp));
		}

	}

};

class MusicEFUP : public Button
{
public:
	MusicEFUP(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}


	~MusicEFUP() = default;

protected:
	void OnClick()
	{
		int temp = stoi(setup_scene->GetElement("music_EFF"));
		temp += 1;
		if (temp >= 0 && temp <= 100)
		{
			setup_scene->SetElement("music_EFF", to_string(temp));
			SceneManager::Opertate_File(SceneManager::opt::music_EFF, to_string(temp));
		}

	}

};

class MusicEFDown : public Button
{
public:
	MusicEFDown(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}


	~MusicEFDown() = default;

protected:
	void OnClick()
	{
		int temp = stoi(setup_scene->GetElement("music_EFF"));
		temp -= 1;
		if (temp >= 0 && temp <= 100)
		{
			setup_scene->SetElement("music_EFF", to_string(temp));
			SceneManager::Opertate_File(SceneManager::opt::music_EFF, to_string(temp));
		}

	}

};


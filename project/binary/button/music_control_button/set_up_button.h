#pragma once
#include "../button/button.h"

extern Scene* setup_scene;

extern int volume_bgm;
extern int volume_sound;

class MusicBKUP : public Button
{
public:
	MusicBKUP(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}

	~MusicBKUP() = default;

protected:
	void OnClick()
	{
		volume_bgm += 50;
		if (volume_bgm >= 1000)
			volume_bgm = 1000;
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
		volume_bgm -= 50;
		if (volume_bgm <= 0)
			volume_bgm = 0;
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
		volume_sound += 50;

		if (volume_sound >= 1000)
			volume_sound = 1000;
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
		volume_sound -= 50;

		if (volume_sound <= 0)
			volume_sound = 0;

	}

};


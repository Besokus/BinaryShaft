#pragma once


#include "../button/button.h"

// 关于我们的返回按钮
class ShowUsButton :public Button
{
public:
	ShowUsButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}

	~ShowUsButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}
};

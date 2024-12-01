#pragma once
/*
	负责人:ja1u0va
	功能:
		1.导入按钮素材
		2.绘制按钮素材
		3.更新按钮状态
		4.实现跳转功能
	示例:
		StartButton* btn_menu_start = nullptr;
		RECT region_menu_start;					// 定义按键的区域变量

		// 设置区域大小
		region_menu_start.left = 300;
		region_menu_start.right = region_menu_start.left + BUTTON_WIDTH;
		region_menu_start.top = 235;
		region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

		// 导入图片素材
		btn_menu_start = new StartButton(region_menu_start,
			_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

		// Enter阶段会重置按钮状态
		btn_menu_start->OnEnter();

		// 根据输入信息改变状态,或实现跳转
		// OnClick()就是在这里面实现跳转界面的函数
		btn_menu_start->OnInput(msg);

		// 绘制按钮
		btn_menu_start->OnDraw();

*/
#include <graphics.h>
#include "../../scene/scene_manager/scene_manager.h"
#include"../../scene/set_up_scene/set_up_scene.h"

extern SceneManager scene_manager;

class Button
{
private:
	// 按钮状态
	enum class Status
	{
		Idle = 0,		// 默认状态
		Hovered,		// 被选中
		Pushed			// 被按下
	};


private:
	Status status = Status::Idle;
	RECT region;					// 按钮的区域
	IMAGE img_idle;
	IMAGE img_hovered;
	IMAGE img_pushed;
	int width;
	int height;

protected:
	virtual void OnClick() = 0;

public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height);

	~Button() = default;

	void OnEnter();

	void OnDraw();

	void OnInput(const ExMessage& msg);

private:
	bool CheckCursorHit(int x, int y);
};





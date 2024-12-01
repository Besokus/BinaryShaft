#pragma once
/*
	������:ja1u0va
	����:
		1.���밴ť�ز�
		2.���ư�ť�ز�
		3.���°�ť״̬
		4.ʵ����ת����
	ʾ��:
		StartButton* btn_menu_start = nullptr;
		RECT region_menu_start;					// ���尴�����������

		// ���������С
		region_menu_start.left = 300;
		region_menu_start.right = region_menu_start.left + BUTTON_WIDTH;
		region_menu_start.top = 235;
		region_menu_start.bottom = region_menu_start.top + BUTTON_HEIGHT;

		// ����ͼƬ�ز�
		btn_menu_start = new StartButton(region_menu_start,
			_T("resources/menu_start_idle.png"), _T("resources/menu_start_hovered.png"), _T("resources/menu_start_pushed.png"));

		// Enter�׶λ����ð�ť״̬
		btn_menu_start->OnEnter();

		// ����������Ϣ�ı�״̬,��ʵ����ת
		// OnClick()������������ʵ����ת����ĺ���
		btn_menu_start->OnInput(msg);

		// ���ư�ť
		btn_menu_start->OnDraw();

*/
#include <graphics.h>
#include "../../scene/scene_manager/scene_manager.h"
#include"../../scene/set_up_scene/set_up_scene.h"

extern SceneManager scene_manager;

class Button
{
private:
	// ��ť״̬
	enum class Status
	{
		Idle = 0,		// Ĭ��״̬
		Hovered,		// ��ѡ��
		Pushed			// ������
	};


private:
	Status status = Status::Idle;
	RECT region;					// ��ť������
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





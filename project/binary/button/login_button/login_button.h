#pragma once

#include "../button/button.h"
#include "../../data.h"
#pragma warning(disable:4996) // 禁用使用wstombs带来的警告

extern vector<Data> data_list;
extern Data* current_data;

extern bool running;

// 新建存档
class LoginNewButton :public Button
{
public:
	LoginNewButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~LoginNewButton() = default;

protected:
	void OnClick()
	{
		if (data_list.size() >= 3)
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("玩家数量超出上限!"));

			MessageBox(GetHWnd(), text, _T("创建新用户失败"), MB_OK);

			OnEnter();

			return;
		}

		Data new_data;
		wchar_t s[12];
		InputBox(s, 12, L"输入玩家姓名\n请输入英文名哦");

		wcstombs(new_data.name, s, sizeof(new_data.name));

		if (strcmp(new_data.name, "") == 0)
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("名称不能为空!"));

			MessageBox(GetHWnd(), text, _T("创建新用户失败"), MB_OK);
		}
		else
		{
			data_list.push_back(new_data);
		}

		// 是按钮变回默认状态
		OnEnter();
	}
};


// 删除存档
class LoginDeleteButton :public Button
{
public:
	LoginDeleteButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~LoginDeleteButton() = default;

protected:
	void OnClick()
	{
		wchar_t delete_num[5];
		InputBox(delete_num, 5, L"请问要删除第几位玩家");

		int num = _wtoi(delete_num);

		if (num<1 || num>data_list.size())
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("请输入正确的数字!"));

			MessageBox(GetHWnd(), text, _T("删除用户失败"), MB_OK);

		}
		else
		{
			auto iter = data_list.begin();
			iter += num - 1;
			data_list.erase(iter);
			if (data_list.size() > 0)
			{
				current_data = &data_list[0];
			}
			else
				current_data = nullptr;
		}

		// 是按钮变回默认状态
		OnEnter();
	}
};

// 返回菜单
class LoginReturnButton :public Button
{
public:
	LoginReturnButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
		:Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
	~LoginReturnButton() = default;

protected:
	void OnClick()
	{
		scene_manager.SwitchTo(SceneManager::SceneType::Menu);
	}
};
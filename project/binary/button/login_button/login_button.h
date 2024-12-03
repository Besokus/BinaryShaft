#pragma once

#include "../button/button.h"
#include "../../data.h"
#pragma warning(disable:4996) // ����ʹ��wstombs�����ľ���

extern vector<Data> data_list;
extern Data* current_data;

extern bool running;

// �½��浵
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
			_stprintf_s(text, _T("���������������!"));

			MessageBox(GetHWnd(), text, _T("�������û�ʧ��"), MB_OK);

			OnEnter();

			return;
		}

		Data new_data;
		wchar_t s[12];
		InputBox(s, 12, L"�����������\n������Ӣ����Ŷ");

		wcstombs(new_data.name, s, sizeof(new_data.name));

		if (strcmp(new_data.name, "") == 0)
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("���Ʋ���Ϊ��!"));

			MessageBox(GetHWnd(), text, _T("�������û�ʧ��"), MB_OK);
		}
		else
		{
			data_list.push_back(new_data);
		}

		// �ǰ�ť���Ĭ��״̬
		OnEnter();
	}
};


// ɾ���浵
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
		InputBox(delete_num, 5, L"����Ҫɾ���ڼ�λ���");

		int num = _wtoi(delete_num);

		if (num<1 || num>data_list.size())
		{
			static TCHAR text[64];
			_stprintf_s(text, _T("��������ȷ������!"));

			MessageBox(GetHWnd(), text, _T("ɾ���û�ʧ��"), MB_OK);

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

		// �ǰ�ť���Ĭ��״̬
		OnEnter();
	}
};

// ���ز˵�
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
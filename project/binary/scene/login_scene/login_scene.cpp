#include "login_scene.h"
#include "../../button/button/button.h"
#include "../../button/login_button/login_button.h"
#include "../../data.h"
#include <vector>

extern SceneManager scene_manager;

extern IMAGE img_login_background;

extern LoginNewButton* btn_login_new;
extern LoginDeleteButton* btn_login_delete;
extern LoginReturnButton* btn_login_return;

extern vector<Data> data_list;
extern Data* current_data;
extern int current_idx;

void LoginScene::OnEnter()
{
	btn_login_new->OnEnter();
	btn_login_delete->OnEnter();
	btn_login_return->OnEnter();
}

void LoginScene::OnUpdate()
{

}

void LoginScene::OnDraw()
{
	putimage(0, 0, &img_login_background);

	for (int i = 0; i < data_list.size(); i++)
	{
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, _T("IPix"));

		static TCHAR text1[64];
		if(current_data!=nullptr)
		{
			if (*current_data == data_list[i])
			{
				settextcolor(RGB(255, 255, 0));
			}
			else 
			{
				settextcolor(RGB(255, 255, 255));
			}
		}


		MultiByteToWideChar(CP_ACP, 0, data_list[i].name, -1, text1, 64);

		outtextxy(70, 255 + i * 50, text1);

		static TCHAR text2[64];
		_stprintf_s(text2, _T("µÚ%d¹Ø"), data_list[i].unlocked_level);
		outtextxy(320, 255 + i * 50, text2);

		settextcolor(RGB(255, 255, 255));
	}

	btn_login_new->OnDraw();
	btn_login_delete->OnDraw();
	btn_login_return->OnDraw();
}

void LoginScene::OnInput(const ExMessage& msg)
{
	btn_login_new->OnInput(msg);
	btn_login_delete->OnInput(msg);
	btn_login_return->OnInput(msg);

	for (int i = 0; i < data_list.size(); i++)
	{


	}

	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'S':
			if (current_data == nullptr)
			{
				if (!data_list.empty())
				{
					current_idx = 0;
					current_data = &data_list[current_idx];
				}
			}
			else
			{
				current_idx = (current_idx + 1) % data_list.size();
				current_data = &data_list[current_idx];
			}
			break;
		case 'W':
			if (current_data == nullptr)
			{
				if (!data_list.empty())
				{
					current_idx = 0;
					current_data = &data_list[current_idx];
				}
			}
			else
			{
				current_idx = (current_idx - 1 + data_list.size()) % data_list.size();
				current_data = &data_list[current_idx];
			}
			break;
		case VK_RETURN:
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}

	}
}

void LoginScene::OnExit()
{

}
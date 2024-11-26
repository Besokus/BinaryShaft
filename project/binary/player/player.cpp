#include "player.h"

Player::Player() 
{
	
	current_animation = &animation_idle_left;

}


void Player::OnUpdate()
{
	int direction = is_right_key_down - is_left_key_down;

	if (direction != 0)
	{
		is_facing_right = direction > 0;
		current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
	}
	else 
	{
		current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
	}

	if (is_on_platform)
	{
		std::cout << "�����ƽ̨��" << "\n";
	}
	else
	{
		std::cout << "����ڿ���" << "\n";
	}

	current_animation->OnUpDate(delta);
}

void Player::OnDraw()
{
	outtextxy(10, 30, _T("��ұ�����"));
	// current_animation->OnDraw(position.x,position.y);
}

void Player::OnInput(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case'A':
		case'a':
			is_left_key_down = true;
		case'D':
		case'd':
			is_right_key_down = true;
		}
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case'A':
		case'a':
			is_left_key_down = false;
		case'D':
		case'd':
			is_right_key_down = false;

		}
	}
}

void Player::SetPosition(int x, int y)
{


}
#include "player.h"

extern Animation* animation_player_left;
extern Animation* animation_player_right;
extern Animation* animation_player_idle;

extern void PutImage(int x, int y, IMAGE* img);

extern IMAGE img_player_idle;

Player::Player()
{
	current_animation = animation_player_right;

	animation_player_right->SetInterval(50);
	animation_player_right->SetLoop(true);
	animation_player_left->SetInterval(50);
	animation_player_left->SetLoop(true);
}


void Player::OnUpdate()
{
	int direction = is_right_key_down - is_left_key_down;

	if (direction != 0)
	{
		is_facing_right = direction > 0;
		current_animation = is_facing_right ? animation_player_right : animation_player_left;
	}
	else
	{
		current_animation = nullptr;
	}

	if (is_on_platform)
	{
		std::cout << "玩家在平台上" << "\n";
	}
	else
	{
		std::cout << "玩家在空中" << "\n";
	}

	if (direction>0) 
	{
		position.x += PLAYER_SPEED;
	}
	else if(direction < 0)
	{
		position.x -= PLAYER_SPEED;
	}

	if (current_animation)
	{
		current_animation->OnUpDate(delta);
	}

}

void Player::OnDraw()
{
	outtextxy(10, 30, _T("玩家被绘制"));

	if (current_animation)
	{
		current_animation->OnDraw(position.x, position.y);
	}
	else
	{
		PutImage(position.x, position.y, &img_player_idle);
	}
}

void Player::OnInput(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case 'A':
		case 'a':
			is_left_key_down = true;
			break;
		case 'D':
		case 'd':
			is_right_key_down = true;
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case 'A':
		case 'a':
			is_left_key_down = false;
			break;
		case 'D':
		case 'd':
			is_right_key_down = false;
			break;
		}
		break;
	}
}

void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.x = y;
}
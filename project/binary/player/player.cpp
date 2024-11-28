#include "player.h"
#include "../platform/platform/platform.h"

extern Animation* animation_player_left;
extern Animation* animation_player_right;
extern Animation* animation_player_fall_idle;

extern void PutImage(int x, int y, IMAGE* img);

extern IMAGE img_player_idle;

extern Platform* AC_platform;
extern std::vector<Platform*> platform_list;

extern const int PLAYER_WIDTH;
extern const int PLAYER_HEIGHT;

extern const int PLATFORM_WIDTH;
extern const int PLATFORM_HEIGHT;


Player::Player()
{
	current_animation = nullptr;

	animation_player_right->SetInterval(100);
	animation_player_right->SetLoop(true);

	animation_player_left->SetInterval(100);
	animation_player_left->SetLoop(true);

	animation_player_fall_idle->SetInterval(100);
	animation_player_fall_idle->SetLoop(true);

	size.x = 30;
	size.y = 30;
}


void Player::OnUpdate()
{
	DWORD start_time = GetTickCount();

	for (Platform* platform : platform_list)
	{
		CheckCollison(platform);
		if (is_on_platform)
			break;
	}

	// 更新玩家位置
	UpdatePosition();

	DWORD end_time = GetTickCount();
	DWORD delta_time = end_time - start_time;
	if (delta_time < 1000 / 144)
		Sleep(1000 / 144 - delta_time);

	render_position.x = (int)position.x - 20;
	render_position.y = (int)position.y - 40;

	// 更新动画
	if (current_animation)
	{
		current_animation->OnUpDate(delta);
	}
}

void Player::OnDraw()
{
	// 如果有动画则播放动画
	// 没有动画,则放默认图片

	if (current_animation)
	{
		current_animation->OnDraw((int)render_position.x, (int)render_position.y);
	}
	else
	{
		PutImage((int)render_position.x, (int)render_position.y, &img_player_idle);
	}

	setlinecolor(RGB(0, 255, 0));
	line((int)position.x, (int)position.y, (int)position.x + (int)size.x, (int)position.y);
	line((int)position.x, (int)position.y, (int)position.x, (int)position.y + (int)size.y);
	line((int)position.x + (int)size.x, (int)position.y, (int)position.x + (int)size.x, (int)position.y + (int)size.y);
	line((int)position.x, (int)position.y + (int)size.y, (int)position.x + (int)size.x, (int)position.y + (int)size.y);
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
	position.x = (float)x;
	position.y = (float)y;
}

void Player::UpdatePosition()
{
	// 判断玩家方向
	int direction = is_right_key_down - is_left_key_down;

	// 如果direction>0,则方向为右
	// 如果direction<0,则方向为左
	// 如果direction=0,则无方向
	if (direction != 0)
	{
		current_animation = direction > 0 ? animation_player_right : animation_player_left;
	}
	else
	{
		current_animation = nullptr;
	}

	// 竖直速度
	// 如果不在平台上,则竖直方向上自由落体,
	// 如果在平台上,则竖直方向上速度为平台速度
	if (!is_on_platform)
	{
		velocity.y += gravity;

		// 并改变动画
		current_animation = animation_player_fall_idle;
	}
	else
	{
		velocity.y = -platform_velocity; // 等于平台速度
	}

	// 水平速度
	if (direction > 0)
	{
		velocity.x = run_velocity;
	}
	else if (direction < 0)
	{
		velocity.x = -run_velocity;
	}
	else
	{
		velocity.x = 0;
	}

	// 位置随速度变化
	// 这里是重载了向量运算,所以不用分别在x,y方向更改
	position += velocity;
}

void Player::CheckCollison(Platform* platform)
{
	bool is_collision_x = ((max(position.x + size.x, platform->shape.right) - min(position.x, platform->shape.left)) <= (size.x + (platform->shape.right - platform->shape.left)));
	bool is_collision_y = (platform->shape.y >= position.y && platform->shape.y <= position.y + size.y);

	if (is_collision_x && is_collision_y)
	{
		if (!platform->is_leave)
		{
			position.y = platform->shape.y - size.y;
			platform_velocity = platform->up_velocity;
			is_on_platform = true;
		}

		platform->is_visited = true;

		return;
	}

	if (!is_collision_x && platform->is_visited)
	{
		platform->is_leave = true;
	}

	is_on_platform = false;

}
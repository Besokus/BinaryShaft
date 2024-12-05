#include "player.h"
#include "../platform/platform/platform.h"
#pragma warning(disable:28159)

extern const int PLAYER_WIDTH;
extern const int PLAYER_HEIGHT;

extern const int PLATFORM_WIDTH;
extern const int PLATFORM_HEIGHT;

extern bool is_debug;

extern Animation* animation_player_left;
extern Animation* animation_player_right;
extern Animation* animation_player_fall_idle;

extern IMAGE img_player_idle;
extern IMAGE img_player_health;

extern Platform* AC_platform;
extern std::vector<Platform*> platform_list;

extern void PutImage(int x, int y, IMAGE* img);

Player::Player(Map_Msg* map_msg)
{
	current_animation = nullptr;

	animation_player_right->SetInterval(100);
	animation_player_right->SetLoop(true);

	animation_player_left->SetInterval(100);
	animation_player_left->SetLoop(true);

	animation_player_fall_idle->SetInterval(100);
	animation_player_fall_idle->SetLoop(true);

	size.x = 30;
	size.y = 50;

	this->map_msg = map_msg;


}

void Player::OnEnter()
{
	is_alive = true;
}

void Player::OnUpdate()
{
	DWORD start_time = GetTickCount();

	// 检测碰撞
	bool flag = false;
	//如果脚下有平台则只检测是否离开了脚下的平台
	if (down_platform != nullptr)
	{
		if (down_platform->CheckLeave(this))
		{
			is_on_platform = false;
			this->down_platform->is_on_platform = false;
			this->down_platform = nullptr;
		}
		else
		{
			down_platform->PlatformChange(this);
		}
	}
	else//如果没有则遍历
	{
		for (Platform* platform : platform_list)
		{
			//if (platform->is_leave)
			//	continue;
			platform->CheckCollison(this);
			if (is_on_platform)
				break;
		}
	}

	// 更新玩家位置
	UpdatePosition();

	DWORD end_time = GetTickCount();
	DWORD delta_time = end_time - start_time;
	if (delta_time < 1000 / 144)
		Sleep(1000 / 144 - delta_time);

	// 更新渲染位置
	render_position.x = (int)position.x - 20;
	render_position.y = (int)position.y - 20;

	// 更新动画
	if (current_animation)
	{
		current_animation->OnUpDate(delta);
	}

	CheckAlive();
}

void Player::OnDraw()
{
	// 如果有动画则播放动画
	if (current_animation)
	{
		current_animation->OnDraw((int)render_position.x, (int)render_position.y);
	}
	// 如果没有动画,则放默认图片
	else
	{
		PutImage((int)render_position.x, (int)render_position.y, &img_player_idle);
	}

	// 绘制血量
	if (health > 12)
	{
		health = 12;
	}
	if (health <= 6 && health > 0)
	{
		for (int i = 0; i < health; i++)
		{
			PutImage(510 + 20 * i, 200 , &img_player_health);
		}
	}
	else if (health > 6 && health <= 12)
	{
		for (int i = 0; i < 6; i++)
		{
			PutImage(530 + 20 * i, 200, &img_player_health);
		}
		for (int i = 0; i < health - 6; i++)
		{
			PutImage(530 + 20 * i, 220, &img_player_health);
		}
	}

	// 调试辅助线
	if (is_debug)
	{
		setlinecolor(RGB(0, 255, 0));
		line((int)position.x, (int)position.y, (int)position.x + (int)size.x, (int)position.y);
		line((int)position.x, (int)position.y, (int)position.x, (int)position.y + (int)size.y);
		line((int)position.x + (int)size.x, (int)position.y, (int)position.x + (int)size.x, (int)position.y + (int)size.y);
		setlinecolor(RGB(255, 0, 0));
		line((int)position.x, (int)position.y + (int)size.y, (int)position.x + (int)size.x, (int)position.y + (int)size.y);
		TCHAR text[64];
		_stprintf_s(text, _T("%f"), velocity.y);
		outtextxy(0, 80, text);
		TCHAR text2[64];
		_stprintf_s(text2, _T("%d"), jumping_time);
		outtextxy(0, 110, text2);
		if(is_on_platform)
			outtextxy(0, 50, _T("YES"));
		else
			outtextxy(0, 50, _T("NO"));
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
		case ' ':
			if (is_on_platform)//重置跳跃时间
			{
				is_jumping = true;
				jumping_time = 30;
			}
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
		case ' ':
			is_jumping = false;
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

	//跳跃
	if (is_on_platform || is_jumping)
	{
		if (jumping_time >= 0 && is_jumping)
		{
			if (jumping_time >= 22)
			{
				velocity.y = -8;
			}
			else if (jumping_time >= 7)
			{
				velocity.y = -7;
			}
			else if(jumping_time >= 0)
			{
				velocity.y = -5;
			}
			is_on_platform = false;
			if (this->down_platform != nullptr)
			{
				this->down_platform->is_on_platform = false;
				this->down_platform = nullptr;
			}
			jumping_time--;
		}
	}

	// 竖直速度
	// 如果不在平台上,则竖直方向上自由落体,
	// 如果在平台上,则竖直方向上速度为平台速度
	if (!is_on_platform)
	{
		if (velocity.y < max_speed_y)
			velocity.y += gravity;
		else
			velocity.y = max_speed_y;

		// 并改变动画
		current_animation = animation_player_fall_idle;
	}

	// 水平速度
	if (direction > 0)
	{
		if (velocity.x <= 0)
		{
			velocity.x = 1.5f;
		}
		if (velocity.x < run_velocity)
			velocity.x += acceleration_x;
		else
			velocity.x = run_velocity;
	}
	else if (direction < 0)
	{
		if (velocity.x >= 0)
		{
			velocity.x = -1.5f;
		}
		if (velocity.x > -run_velocity)
			velocity.x -= acceleration_x;
		else
			velocity.x = -run_velocity;
	}
	else
	{
			velocity.x = 0;
	}

	// 位置随速度变化
	// 这里是重载了向量运算,所以不用分别在x,y方向更改
	position += velocity;

	// 判断是否出界
	if (position.x < map_msg->left_limit)
		position.x = (float)map_msg->left_limit;
	if (position.x + 70 > map_msg->right_limit)
		position.x = (float)map_msg->right_limit - 70;
}

void Player::CheckCollison(Platform* platform)
{
	platform->is_on_platform = false;
	// 判断x,y方向上是否发生碰撞
	bool is_collision_x = ((max(position.x + size.x, platform->shape.right) - min(position.x, platform->shape.left)) <= (size.x + (platform->shape.right - platform->shape.left)));
	bool is_collision_y = (platform->shape.top >= position.y && platform->shape.top <= position.y + size.y);

	// 如果都发生碰撞
	if (is_collision_x && is_collision_y)
	{
		// 如果没离开过平台,即是第一次踩在平台上
		if (!platform->is_leave)
		{
			// 修正y的值,使玩家正确地踩在平台上端
			float next_pos_y = position.y + size.y + velocity.y;
			if (next_pos_y > platform->shape.top)
				position.y = platform->shape.top - size.y;


			// 更新玩家Player基类中记录的平台速度
			// 以方便玩家在平台上速度和平台同步
			platform_velocity = platform->up_velocity;

			// 标记玩家为在平台上
			is_on_platform = true;
		}

		if(!platform->is_on_platform)
		velocity.y = platform->velocity.y;

		platform->is_on_platform = true;
		is_on_platform = true;

		// 标记平台为被玩家踩过
		platform->is_visited = true;

		return;
	}

	// 如果x方向上不重叠 且 平台被踩过
	if (!is_collision_x && platform->is_visited)
	{
		// 则标记玩家已离开该平台
		platform->is_leave = true;
	}

	is_on_platform = false;
}

void Player::CheckAlive()
{
	if (position.y < 0 || position.y>700)
	{
		is_alive = false;
	}
	if (health < 1)
	{
		is_alive = false;
	}
}
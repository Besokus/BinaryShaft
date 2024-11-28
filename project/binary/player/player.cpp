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

	// �������λ��
	UpdatePosition();

	DWORD end_time = GetTickCount();
	DWORD delta_time = end_time - start_time;
	if (delta_time < 1000 / 144)
		Sleep(1000 / 144 - delta_time);

	render_position.x = (int)position.x - 20;
	render_position.y = (int)position.y - 40;

	// ���¶���
	if (current_animation)
	{
		current_animation->OnUpDate(delta);
	}
}

void Player::OnDraw()
{
	// ����ж����򲥷Ŷ���
	// û�ж���,���Ĭ��ͼƬ

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
	// �ж���ҷ���
	int direction = is_right_key_down - is_left_key_down;

	// ���direction>0,����Ϊ��
	// ���direction<0,����Ϊ��
	// ���direction=0,���޷���
	if (direction != 0)
	{
		current_animation = direction > 0 ? animation_player_right : animation_player_left;
	}
	else
	{
		current_animation = nullptr;
	}

	// ��ֱ�ٶ�
	// �������ƽ̨��,����ֱ��������������,
	// �����ƽ̨��,����ֱ�������ٶ�Ϊƽ̨�ٶ�
	if (!is_on_platform)
	{
		velocity.y += gravity;

		// ���ı䶯��
		current_animation = animation_player_fall_idle;
	}
	else
	{
		velocity.y = -platform_velocity; // ����ƽ̨�ٶ�
	}

	// ˮƽ�ٶ�
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

	// λ�����ٶȱ仯
	// ��������������������,���Բ��÷ֱ���x,y�������
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
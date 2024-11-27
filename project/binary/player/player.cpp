#include "player.h"
#include "../platform/platform/platform.h"

extern Animation* animation_player_left;
extern Animation* animation_player_right;
extern Animation* animation_player_fall_idle;

extern void PutImage(int x, int y, IMAGE* img);

extern IMAGE img_player_idle;

extern Platform* AC_platform;
extern std::vector<Platform*> platform_list;

Player::Player()
{
	current_animation = nullptr;

	animation_player_right->SetInterval(50);
	animation_player_right->SetLoop(true);

	animation_player_left->SetInterval(50);
	animation_player_left->SetLoop(true);

	animation_player_fall_idle->SetInterval(50);
	animation_player_fall_idle->SetLoop(true);

	size.x = 30;
	size.y = 90;
}


void Player::OnUpdate()
{
	CheckCollison(AC_platform);

	// �������λ��
	UpdatePosition();

	render_position.x = (int)position.x - 30;
	render_position.y = (int)position.y;

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
		current_animation->OnDraw(render_position.x, render_position.y);
	}
	else
	{
		PutImage(render_position.x, render_position.y, &img_player_idle);
	}

	setlinecolor(RGB(0, 255, 0));
	line(position.x, position.y, position.x + size.x, position.y);
	line(position.x, position.y, position.x, position.y + 90);
	line(position.x + size.x, position.y, position.x + size.x, position.y + 90);
	line(position.x, position.y + 90, position.x + size.x, position.y + 90);
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
		velocity.y = 0; // ����ƽ̨�ٶ�
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
		float delta_pos_y = velocity.y;
		float last_tick_foot_pos_y = position.y + size.y - delta_pos_y;
		
		if (last_tick_foot_pos_y <= platform->shape.y)
		{
			position.y = platform->shape.y - size.y;

			is_on_platform = true;
			return;
		}

	}
	is_on_platform = false;

}
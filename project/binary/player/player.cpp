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

	// �����ײ
	bool flag = false;
	//���������ƽ̨��ֻ����Ƿ��뿪�˽��µ�ƽ̨
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
	else//���û�������
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

	// �������λ��
	UpdatePosition();

	DWORD end_time = GetTickCount();
	DWORD delta_time = end_time - start_time;
	if (delta_time < 1000 / 144)
		Sleep(1000 / 144 - delta_time);

	// ������Ⱦλ��
	render_position.x = (int)position.x - 20;
	render_position.y = (int)position.y - 20;

	// ���¶���
	if (current_animation)
	{
		current_animation->OnUpDate(delta);
	}

	CheckAlive();
}

void Player::OnDraw()
{
	// ����ж����򲥷Ŷ���
	if (current_animation)
	{
		current_animation->OnDraw((int)render_position.x, (int)render_position.y);
	}
	// ���û�ж���,���Ĭ��ͼƬ
	else
	{
		PutImage((int)render_position.x, (int)render_position.y, &img_player_idle);
	}

	// ����Ѫ��
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

	// ���Ը�����
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
			if (is_on_platform)//������Ծʱ��
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

	//��Ծ
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

	// ��ֱ�ٶ�
	// �������ƽ̨��,����ֱ��������������,
	// �����ƽ̨��,����ֱ�������ٶ�Ϊƽ̨�ٶ�
	if (!is_on_platform)
	{
		if (velocity.y < max_speed_y)
			velocity.y += gravity;
		else
			velocity.y = max_speed_y;

		// ���ı䶯��
		current_animation = animation_player_fall_idle;
	}

	// ˮƽ�ٶ�
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

	// λ�����ٶȱ仯
	// ��������������������,���Բ��÷ֱ���x,y�������
	position += velocity;

	// �ж��Ƿ����
	if (position.x < map_msg->left_limit)
		position.x = (float)map_msg->left_limit;
	if (position.x + 70 > map_msg->right_limit)
		position.x = (float)map_msg->right_limit - 70;
}

void Player::CheckCollison(Platform* platform)
{
	platform->is_on_platform = false;
	// �ж�x,y�������Ƿ�����ײ
	bool is_collision_x = ((max(position.x + size.x, platform->shape.right) - min(position.x, platform->shape.left)) <= (size.x + (platform->shape.right - platform->shape.left)));
	bool is_collision_y = (platform->shape.top >= position.y && platform->shape.top <= position.y + size.y);

	// �����������ײ
	if (is_collision_x && is_collision_y)
	{
		// ���û�뿪��ƽ̨,���ǵ�һ�β���ƽ̨��
		if (!platform->is_leave)
		{
			// ����y��ֵ,ʹ�����ȷ�ز���ƽ̨�϶�
			float next_pos_y = position.y + size.y + velocity.y;
			if (next_pos_y > platform->shape.top)
				position.y = platform->shape.top - size.y;


			// �������Player�����м�¼��ƽ̨�ٶ�
			// �Է��������ƽ̨���ٶȺ�ƽ̨ͬ��
			platform_velocity = platform->up_velocity;

			// ������Ϊ��ƽ̨��
			is_on_platform = true;
		}

		if(!platform->is_on_platform)
		velocity.y = platform->velocity.y;

		platform->is_on_platform = true;
		is_on_platform = true;

		// ���ƽ̨Ϊ����Ҳȹ�
		platform->is_visited = true;

		return;
	}

	// ���x�����ϲ��ص� �� ƽ̨���ȹ�
	if (!is_collision_x && platform->is_visited)
	{
		// ����������뿪��ƽ̨
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
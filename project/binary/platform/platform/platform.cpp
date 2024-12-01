#include "platform.h"

extern bool is_debug;


Platform::Platform(IMAGE img_platform, Map_Msg* map_msg)
{
	this->img_platform = img_platform;
	velocity.y = -up_velocity;
	this->map_msg = map_msg;
}

void Platform::OnUpdate()
{
	if (is_visited && change_times > 0)
	{
		change_times--;
	}
	
	velocity.y = -up_velocity;
	velocity.y *= map_msg->speed;

	shape.top += velocity.y;
	shape.bottom = shape.top + 20;

	render_position.x = (int)shape.left;
	render_position.y = (int)shape.top - 20;
}


void Platform::OnDraw()
{
	PutImage(render_position.x, render_position.y, &img_platform);

	if (is_debug)
	{
		// ���ȹ����뿪������ʾ����
		if (is_leave)
		{
			setlinecolor(RGB(0, 255, 255));
			line((int)shape.left, (int)shape.top, (int)shape.right, (int)shape.top);
		}
		// ������ʾ����
		else
		{
			setlinecolor(RGB(255, 0, 0));
			line((int)shape.left, (int)shape.top, (int)shape.right, (int)shape.top);
			setlinecolor(RGB(0, 255, 255));
			line((int)shape.left, (int)shape.bottom, (int)shape.right, (int)shape.bottom);
			setlinecolor(RGB(255, 0, 0));
			line((int)shape.left, (int)shape.top, (int)shape.left, (int)shape.bottom);
			line((int)shape.right, (int)shape.top, (int)shape.right, (int)shape.bottom);
		}
	}
}


void Platform::SetPosition(int x, int y)
{
	shape.left = (float)x;
	shape.right = shape.left + 100;
	shape.top = (float)y;
}

void Platform::Disappear()
{
	is_exist = false;
}

bool Platform::CheckExist()
{
	return is_exist;
}

void Platform::CheckCollison(Player* player)	//��ײ���
{
	float player_top = player->position.y;
	float player_bottom = player->position.y + player->size.y;
	float player_left = player->position.x;
	float player_right = player->position.x + player->size.x;
	bool collision_down = (shape.top <= player_bottom);
	bool collision_up = (shape.bottom >= player_top);
	bool collision_right = (shape.left <= player_right);
	bool collision_left = (shape.right >= player_left);
	if (collision_down && collision_up && collision_left && collision_right)//����ģ�����ཻ��ʱ��
	{
		if (player_bottom <= shape.bottom)		//��ײ
		{
			if (!is_on_platform)
			{
				// ����y��ֵ,ʹ�����ȷ�ز���ƽ̨�϶�
				if (player->velocity.y > 0)
				{
					float next_pos_y = player->position.y + player->size.y;
					if (next_pos_y > shape.top)
						player->position.y = shape.top - player->size.y;
				}

				// �������Player�����м�¼��ƽ̨�ٶ�
				// �Է��������ƽ̨���ٶȺ�ƽ̨ͬ��
				player->platform_velocity = up_velocity * map_msg->speed;

				//�޸���ҵ��ٶ���ƽ̨��ͬ
				player->velocity.y = velocity.y;
			}
			is_on_platform = true;//��������ƽ̨��
			player->is_on_platform = true;//����Ѿ���ƽ̨��
			player->down_platform = this;//��Ǵ�Ϊ����ƽ̨
			is_visited = true;
			this->PlatformChange(player);
		}
		if (player_right-2>shape.left&&player_left+2<shape.right&&player_top + 1 >= shape.top)
		{
			player->velocity.y = 1;
			player->is_jumping = false;
			is_visited = true;
			this->PlatformChange(player, 1);
		}
		if ((player_bottom>shape.bottom || player_top<shape.top)&&player_left < shape.left)
		{
			if (player_right + 1 >= shape.left)
				player->position.x -= 1;
			if (player->is_right_key_down)
				player->velocity.x = 0;
		}
		if ((player_bottom > shape.bottom && player_top < shape.top) && player_right > shape.right)
		{
			if (player_left - 1 <= shape.left)
				player->position.x += 1;
			if (player->is_left_key_down)
				player->velocity.x = 0;
		}
	}
}

bool Platform::CheckLeave(Player* player)
{
	float player_bottom = player->position.y;
	float player_top = player->position.y + player->size.y;
	float player_left = player->position.x;
	float player_right = player->position.x + player->size.x;
	if (player_left > shape.right || player_right < shape.left || player_bottom>shape.top)
	{
		return true;
	}
	return false;
}
#pragma once
#include "../../player/player.h"
#include "../../scene/game_scene/game_scene.h"

extern int level;

struct Map_massage
{
	float speed;
	int target_score;
	std::vector<int> platform_weight;
	std::vector<bool> item_choice;
};
extern Map_massage map_massage[11];

class Map_Msg
{
public:
	int level;
	int left_limit;
	int right_limit;
	float speed;
	float real_speed;
	int score;
	int target_score;
	std::vector<int> platform_weight;
	std::vector<bool> item_choice;
	Map_Msg(int level)
	{
		score = 0;
		real_speed = speed = map_massage[level].speed;
		this->level = level;
		target_score = map_massage[level].target_score;
		platform_weight.insert(platform_weight.begin(), map_massage[level].platform_weight.begin(), map_massage[level].platform_weight.end());
		item_choice.insert(item_choice.begin(), map_massage[level].item_choice.begin(), map_massage[level].item_choice.end());
		left_limit = 0;
		right_limit = 550;
	}
	~Map_Msg() {}
	/*
	* 负责人：余某
	* 功能：
		1.绘制分数，绘制目标分数，绘制两条边界limit的线，绘制当前速度倍率，绘制关卡数
	*/
	void OnDraw()
	{
		if (level != 10)
		{
			TCHAR level_msg[64];
			_stprintf_s(level_msg, _T("第%d关"), level + 1);
			TCHAR target_msg[64];
			_stprintf_s(target_msg, _T("目标分数：%d"), target_score);
			TCHAR score_msg[64];
			_stprintf_s(score_msg, _T("当前分数：%d"), score);
			TCHAR speed_msg[64];
			_stprintf_s(speed_msg, _T("当前速度：x%.2f"), speed);
			outtextxy(530, 250, level_msg);
			outtextxy(530, 300, target_msg);
			outtextxy(530, 350, score_msg);
			outtextxy(530, 400, speed_msg);
			setlinecolor(RGB(0, 0, 255));
			line(left_limit, 0, left_limit, 700);
			line(right_limit - 50, 0, right_limit - 50, 700);
		}
		else
		{
			TCHAR level_msg[64];
			_stprintf_s(level_msg, _T("挑战模式！！"));
			TCHAR target_msg[64];
			_stprintf_s(target_msg, _T("目标分数：无尽"));
			TCHAR score_msg[64];
			_stprintf_s(score_msg, _T("当前分数：%d"), score);
			TCHAR speed_msg[64];
			_stprintf_s(speed_msg, _T("当前速度：x%.2f"), speed);
			outtextxy(530, 250, level_msg);
			outtextxy(530, 300, target_msg);
			outtextxy(530, 350, score_msg);
			outtextxy(530, 400, speed_msg);
			setlinecolor(RGB(0, 0, 255));
			line(left_limit, 0, left_limit, 700);
			line(right_limit - 50, 0, right_limit - 50, 700);
		}
	}
	void OnUpdate()
	{
		if (level == 10)
		{
			if (score>0&&score % 100 == 0)
			{
				speed += 0.4;
				real_speed += 0.4;
				left_limit += 20;
				right_limit -= 20;
			}
		}
	}
};